/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_specs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:46:01 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/08 13:48:49 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	t_specs_handle_star(t_specs *specs, va_list *arg_list, char *format)
{
	int		value;

	value = va_arg(*arg_list, int);
	if (*(format - 1) == '.')
		specs->precision = value;
	else
	{
		if (value < 0)
		{
			specs->left_justify = 1;
			value *= -1;
		}
		specs->min_field_width = value;
	}
}

t_size	t_specs_get_size_modifier(char **str)
{
	char size_modifier;

	size_modifier = *(*str);
	if (*(*(str + 1)) == size_modifier)
	{
		(*str)++;
		size_modifier += size_modifier;
	}
	return ((t_size)size_modifier);
}

void	t_specs_init(t_specs *specs)
{
	specs->specifier = 0;
	specs->left_justify = 0;
	specs->alt_conversion = 0;
	specs->padding_char = ' ';
	specs->add_space = 0;
	specs->force_sign = 0;
	specs->min_field_width = -1;
	specs->precision = -1;
	specs->size_modifier = none;
}

char	*t_specs_get_specs(t_specs *specs, char *format, va_list *arg_list)
{
	t_specs_init(specs);
	while ((!is_specifier(*format, "sSpdDioOuUxXcC%") && *format != '\0'))
	{
		if (*format == '-')
			specs->left_justify = 1;
		else if (*format == '+')
			specs->force_sign = 1;
		else if (*format == ' ')
			specs->add_space = 1;
		else if (*format == '#')
			specs->alt_conversion = 1;
		else if (*format == '0' && *(format - 1) != '.')
			specs->padding_char = '0';
		else if (*format == '.' || ft_isdigit(*format) == 1)
			cut_digit_from_string(specs, &format);
		else if (*format == '*')
			t_specs_handle_star(specs, arg_list, format);
		else if (is_specifier(*format, "hljz") == 1)
			specs->size_modifier += t_specs_get_size_modifier(&format);
		else
			break ;
		format++;
	}
	specs->specifier = *format;
	return (format);
}
