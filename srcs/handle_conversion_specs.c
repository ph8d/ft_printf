/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion_specs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:46:54 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/06 18:03:10 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_precision(t_specs specs)
{
	while (specs.precision != 0)
	{
		write(1, "0", 1);
		specs.precision--;
	}
}

void	handle_field_width(t_specs specs, size_t *str_len)
{
	if (specs.precision > -1 || specs.left_justify == 1)
	{
		if (is_specifier(specs.specifier,"pdDioOuUxX"))
			specs.padding_char = ' ';
	}
	if (specs.min_field_width > 0)
	{
		while ((int)*str_len < specs.min_field_width)
		{
			write(1, &specs.padding_char, 1);
			(*str_len)++;
		}
	}
}

void	handle_prefixes_hex(t_specs *specs, char *str)
{
	if (specs->specifier == 'x' && !(str[0] == '0' && str[1] == '\0'))
		ft_putstr("0x");
	else if (specs->specifier == 'X' && !(str[0] == '0' && str[1] == '\0'))
		ft_putstr("0X");
}

void	handle_prefixes(t_specs *specs, char *str, int line_len)
{
	if (is_specifier(specs->specifier, "dDi") == 1)
	{
		if (str[0] == '-')
			write(1, "-", 1);
		else if (str[0] != '-')
		{
			if (specs->force_sign == 1)
				write(1, "+", 1);
			else if (specs->add_space == 1)
				write(1, " ", 1);
		}
	}
	else if (specs->specifier == 'p')
		ft_putstr("0x");
	else if (specs->alt_conversion == 1)
	{
		if ((specs->specifier == 'o' || specs->specifier == 'O'))
			write(1, "0", 1);
	}
	line_len++;
	line_len--;
}

size_t	handle_conversion_specs(t_specs specs, char *converted_str)
{
	size_t line_len;

	line_len = get_line_length(&specs, converted_str);
	if ((specs.specifier == 'x' || specs.specifier == 'X')
		&& specs.left_justify == 0 && specs.alt_conversion == 1 && specs.padding_char == '0')
		handle_prefixes_hex(&specs, converted_str);
	else if (specs.left_justify == 1 || specs.padding_char == '0')
		handle_prefixes(&specs, converted_str, (int)line_len);
	if (specs.min_field_width > 0 && specs.left_justify == 0)
		handle_field_width(specs, &line_len);
	if ((specs.specifier == 'x' || specs.specifier == 'X')
		&& (specs.left_justify == 1 || specs.padding_char == ' ') && specs.alt_conversion == 1)
		handle_prefixes_hex(&specs, converted_str);
	else if (specs.left_justify == 0 && specs.padding_char != '0')
		handle_prefixes(&specs, converted_str, (int)line_len);
	if (specs.precision > 0)
		handle_precision(specs);
	return (line_len);
}
