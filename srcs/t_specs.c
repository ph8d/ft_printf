/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_specs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:46:01 by rtarasen          #+#    #+#             */
/*   Updated: 2018/01/29 12:22:06 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_size	t_specs_get_size_modifier(char *str)
{
	char *size_modifier;

	size_modifier = "hljz";
	while (*size_modifier != '\0')
	{
		if (*(str + 1) == *size_modifier)
		{
			if (*str == *size_modifier)
				return ((t_size)(*size_modifier + *size_modifier));
			return ((t_size)*size_modifier);
		}
		size_modifier++;
	}
	return (none);
}

void	t_specs_init(t_specs *conversion_specs)
{
	conversion_specs->specifier = 0;
	conversion_specs->left_justify = 0;
	conversion_specs->alt_conversion = 0;
	conversion_specs->padding_char = ' ';
	conversion_specs->add_space = 0;
	conversion_specs->force_sign = 0;
	conversion_specs->min_field_width = -1;
	conversion_specs->precision = -1;
	conversion_specs->size_modifier = none;
}

char	*t_specs_get_specs(t_specs *conversion_specs, char *format)
{
	t_specs_init(conversion_specs);
	while ((!is_specifier(*format) && *format != '\0'))
	{
		if (*format == '-')
			conversion_specs->left_justify = 1;
		else if (*format == '+')
			conversion_specs->force_sign = 1;
		else if (*format == ' ')
			conversion_specs->add_space = 1;
		else if (*format == '#')
			conversion_specs->alt_conversion = 1;
		else if (*format == '0' && *(format - 1) != '.')
			conversion_specs->padding_char = '0';
		else if (*format == '.')
			conversion_specs->precision = cut_digit_from_string(&format); //  <--- this function is doing weird things
		else if (ft_isdigit(*format))
			conversion_specs->min_field_width = cut_digit_from_string(&format);
		format++;
	}
	if (conversion_specs->precision != -1 || conversion_specs->left_justify == 1)
		conversion_specs->padding_char = ' ';
	if (is_specifier(*format))
		conversion_specs->specifier = *format;
	conversion_specs->size_modifier = t_specs_get_size_modifier(format - 2);
	return (format);
}
