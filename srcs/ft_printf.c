/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:06:00 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/06 11:33:02 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	output_handler(t_specs specs, va_list *arg_list, int *n)
{
	if (specs.specifier == 'S' || (specs.specifier == 's' && specs.size_modifier == l))
		*n += handle_str_wide(specs, arg_list);
	else if (specs.specifier == 's')
		*n += handle_str(specs, arg_list);
	else if (is_specifier(specs.specifier, "dDi") == 1)
		*n += handle_int(specs, arg_list);
	else if (is_specifier(specs.specifier, "uUoOxXp") == 1)
		*n += handle_int_u(specs, arg_list);
	else if (specs.specifier == 'C' || (specs.specifier == 'c' && specs.size_modifier == l))
		*n += handle_char_wide(specs, arg_list);
	else if (specs.specifier == 'c')
		*n += handle_char(specs, arg_list);
	else if (specs.specifier == '%')
		*n += handle_percent(specs);
}

void	format_parse(char **format, va_list *arg_list, int *chars_printed)
{
	char	*format_start;
	t_specs conversion_specs;

	format_start = *format;
	if ((*format = t_specs_get_specs(&conversion_specs, (*format + 1))) == NULL)
	{
		*format = format_start;
		return ;
	}
	output_handler(conversion_specs, arg_list, chars_printed);
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
	ret = format_read((char *)format, &arg_list);
	va_end(arg_list);
	return (ret);
}
