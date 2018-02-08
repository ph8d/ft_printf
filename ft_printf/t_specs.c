/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_specs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:46:01 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/07 20:25:51 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*t_specs_get_specs(t_specs *specs, char *format)
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
		else if (*format == '.')
			specs->precision = cut_digit_from_string(&format);
		else if (ft_isdigit(*format) == 1)
			specs->min_field_width = cut_digit_from_string(&format);
		else if (is_specifier(*format, "hljz") == 1)
			specs->size_modifier += t_specs_get_size_modifier(&format);
		else
			break ;
		format++;
	}
	specs->specifier = *format;
	return (format);
}
