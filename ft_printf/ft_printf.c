/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:06:00 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/09 19:25:54 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		output_handler(t_specs specs, va_list *arg_list, char current_char)
{
	if (specs.specifier == 'S' || (specs.specifier == 's' &&
		specs.size_modifier == l))
		return (handle_str_wide(specs, arg_list));
	else if (specs.specifier == 's')
		return (handle_str(specs, arg_list));
	else if (is_specifier(specs.specifier, "dDi") == 1)
		return (handle_int(specs, arg_list));
	else if (specs.specifier == 'f' || specs.specifier == 'F')
		return (handle_floating_point(specs, arg_list));
	else if (is_specifier(specs.specifier, "uUoOxXpb") == 1)
		return (handle_int_u(specs, arg_list));
	else if (specs.specifier == 'C' || (specs.specifier == 'c' &&
		specs.size_modifier == l))
		return (handle_char_wide(specs, arg_list));
	else if (specs.specifier == 'c')
		return (handle_char(specs, arg_list));
	else if (specs.specifier == '%')
		return (handle_percent(specs));
	else
		return (handle_undefined_specifier(specs, current_char));
}

int		format_parse(char **format, va_list *arg_list, int *chars_printed)
{
	t_specs conversion_specs;

	*format = t_specs_get_specs(&conversion_specs, (*format + 1), arg_list);
	if (**format == '\0')
		return (-1);
	*chars_printed += output_handler(conversion_specs, arg_list, **format);
	return (1);
}

int		format_read(char *format, va_list *arg_list)
{
	int	chars_printed;

	chars_printed = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if ((format_parse(&format, arg_list, &chars_printed)) == -1)
				break ;
		}
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
