/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:06:00 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/03 18:00:03 by rtarasen         ###   ########.fr       */
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
	else if (is_specifier(specs.specifier, "dDi") == 1)
		*n += handle_int(specs, arg_list);
	else if (is_specifier(specs.specifier, "uUoOxXp") == 1)
		*n += handle_int_u(specs, arg_list);
	else if (specs.specifier == 'c')
		*n += handle_char(specs, arg_list);
	else if (specs.specifier == 'C')
		*n += handle_char_wide(specs, arg_list);
	else if (specs.specifier == '%')
		*n += handle_percent(specs);
}

void	format_parse(char **format, va_list *arg_list, int *chars_printed)
{
	t_specs conversion_specs;

	if (*(*format + 1) == '%')
	{
		write(1, "%", 1);
		(*chars_printed)++;		//	<--- this whole thing is too messy
		(*format)++;
		return ;
	}
	*format = t_specs_get_specs(&conversion_specs, (*format + 1));
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

int		main(void)
{
	int std_ret;
	int ft_ret;

	ft_ret = ft_printf("ft_printf ---> [@moulitest: %.d %.0d]\n", 43, 43);
	  std_ret = printf("   printf ---> [@moulitest: %.d %.0d]\n", 42, 43);

	printf("\n ft_ret ---> %i", ft_ret);
	printf("\nstd_ret ---> %i\n", std_ret);
	return (0);
}
