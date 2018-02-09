/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_specs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:46:01 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/09 18:00:01 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	t_specs_handle_star(t_specs *specs, va_list *args, char *str)
{
	int		value;

	value = va_arg(*args, int);
	if (*(str - 1) == '.')
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

char	*t_specs_get_specs(t_specs *specs, char *str, va_list *args)
{
	t_specs_init(specs);
	while ((!is_specifier(*str, "sSpdDioOuUxXcC%") && *str != '\0'))
	{
		if (*str == '-')
			specs->left_justify = 1;
		else if (*str == '+')
			specs->force_sign = 1;
		else if (*str == ' ')
			specs->add_space = 1;
		else if (*str == '#')
			specs->alt_conversion = 1;
		else if (*str == '0' && *(str - 1) != '.')
			specs->padding_char = '0';
		else if (*str == '.' || ft_isdigit(*str) == 1)
			cut_digit_from_string(specs, &str);
		else if (*str == '*')
			t_specs_handle_star(specs, args, str);
		else if (is_specifier(*str, "hljz") == 1)
			specs->size_modifier += t_specs_get_size_modifier(&str);
		else
			break ;
		str++;
	}
	specs->specifier = *str;
	return (str);
}
