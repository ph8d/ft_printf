/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:06:00 by rtarasen          #+#    #+#             */
/*   Updated: 2018/01/23 18:07:45 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdio.h>
#include <locale.h>

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

int		cut_digit_from_string(char **str)
{
	int		result;
	size_t	digit_length;
	char	*digit;

	result = -1;
	digit_length = 0;
	while (ft_isdigit((*str)[digit_length]) && (*str)[digit_length] != '\0')
		digit_length++;
	if (digit_length != 0)
	{
		digit = ft_strsub(*str, 0, digit_length);
		result = ft_atoi(digit);
		free(digit);
		(*str) += digit_length - 1;
	}
	return (result);
}

int		is_specifier(char c)
{
	char *specifier;

	specifier = "sSpdDioOuUxXcC";
	while (*specifier != '\0')
	{
		if (c == *specifier)
			return (1);
		specifier++;
	}
	return (0);
}

void	t_specs_init(t_specs *conversion_specs)
{
	conversion_specs->specifier = 0;
	conversion_specs->left_justify = 0;
	conversion_specs->alt_conversion = 0;
	conversion_specs->pad_with_zeroes = 0;
	conversion_specs->add_space = 0;
	conversion_specs->force_sign = 0;
	conversion_specs->min_field_width = -1;
	conversion_specs->size_modifier = none;
}

void	t_specs_get_specs(t_specs *conversion_specs, char *format)
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
		else if (*format == '0')
			conversion_specs->pad_with_zeroes = 1;
		else if (*(format - 1) == '.' && ft_isdigit(*format))
			conversion_specs->precision = cut_digit_from_string(&format);
		else if (ft_isdigit(*format))
			conversion_specs->min_field_width = cut_digit_from_string(&format);
		format++;
	}
	if (is_specifier(*format))
		conversion_specs->specifier = *format;
	conversion_specs->size_modifier = t_specs_get_size_modifier(format - 2);
}

void	output_handler(t_specs conversion_specs, va_list *arg_list, int *n)
{
	if (conversion_specs.specifier == 'd' || conversion_specs.specifier == 'i')
		// Handle decimal
	if (conversion_specs.specifier == 'c')
		// Handle %c
	if (conversion_specs.specifier == 'C')
		// Handle %C
	if (conversion_specs.specifier == 's')
		// Handle %s
	if (conversion_specs.specifier == 'S')
		// Handle %S

}

int		format_parse(char **format, va_list *arg_list, int *chars_printed)
{
	t_specs conversion_specs;

	t_specs_get_specs(&conversion_specs, (*format + 1));
	output_handler(conversion_specs, arg_list, chars_printed);
	printf("\n[conversion specs (%c)]\n - size_modifier [%i]\n - left_justify [%i]\n - force_sign [%i]\n - add_space [%i]\n - alt_conversion [%i]\n - pad_with_zeroes [%i]\n - min_field_width [%i]\n - precision [%i]\n\n", conversion_specs.specifier, conversion_specs.size_modifier, conversion_specs.left_justify, conversion_specs.force_sign, conversion_specs.add_space, conversion_specs.alt_conversion, conversion_specs.pad_with_zeroes, conversion_specs.min_field_width, conversion_specs.precision);

	return (44442222); // <--- Change!
}

int		format_read(char *format, va_list *arg_list)
{
	int	chars_printed;

	chars_printed = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			format_parse(&format, arg_list, &chars_printed);
		else
		{
			write(1, format, 1);
			chars_printed++;
		}
		format++;
	}
	return (chars_printed);
}

int		ft_printf(const char *format, ...)
{
	int		ret;
	va_list	arg_list;

	va_start(arg_list, format);
	ret = format_read(format, &arg_list);
	va_end(arg_list);
	return (ret);
}

int		main(void)
{
	int ret;
	//setlocale(LC_ALL, "");
	ret = ft_printf("%-#.4d gigigig %s hah %lu rrrrr %010d");
	//printf("[%-#012.4s]\n", "123456789");
	return (ret);
}
