/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:06:00 by rtarasen          #+#    #+#             */
/*   Updated: 2018/01/29 15:15:42 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdio.h>
#include <locale.h>

void	output_handler(t_specs specs, va_list *arg_list, int *n)
{
	if (specs.specifier == 's')
		*n += handle_str(specs, arg_list);
	else if (specs.specifier == 'S')
		*n += handle_str_wide(specs, arg_list);
	else if (specs.specifier == 'p')
		*n += handle_pointer(specs, arg_list);
	else if (specs.specifier == 'd' || specs.specifier == 'i')
		*n += handle_decimal(specs, arg_list);
	else if (specs.specifier == 'D' || specs.size_modifier == l)
		*n += handle_decimal_long(specs, arg_list);
	else if (specs.specifier == 'c')
		*n += handle_char(arg_list);
	else if (specs.specifier == 'C')
		*n += handle_char_wide(specs, arg_list);

	//
	//	TODO all other types handling
	//

}

void	format_parse(char **format, va_list *arg_list, int *chars_printed)
{
	t_specs conversion_specs;

	*format = t_specs_get_specs(&conversion_specs, (*format + 1));
	output_handler(conversion_specs, arg_list, chars_printed);
	//printf("\n[conversion specs (%c)]\n - size_modifier [%i]\n - left_justify [%i]\n - force_sign [%i]\n - add_space [%i]\n - alt_conversion [%i]\n - pad_with_zeroes [%i]\n - min_field_width [%i]\n - precision [%i]\n\n", conversion_specs.specifier, conversion_specs.size_modifier, conversion_specs.left_justify, conversion_specs.force_sign, conversion_specs.add_space, conversion_specs.alt_conversion, conversion_specs.pad_with_zeroes, conversion_specs.min_field_width, conversion_specs.precision);
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
	int *pointer;
	int ft_ret;
	int ret;

	//setlocale(LC_ALL, "");
	ft_ret = ft_printf("[ft_printf]\t[%0.10s]\n", "12345");
	ret = printf("   [printf]\t[%0.10s]\n", "12345");
	printf("\n[ft_ret] ---> %i\n", ft_ret);
	printf("   [ret] ---> %i\n", ret);
	return (0);
}
