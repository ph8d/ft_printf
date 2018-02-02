/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion_specs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:46:54 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/02 17:48:40 by rtarasen         ###   ########.fr       */
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
	if (specs.min_field_width > 0)
	{
		while (*str_len < specs.min_field_width)
		{
			write(1, &specs.padding_char, 1);
			(*str_len)++;
		}
	}
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
		if (specs->specifier == 'x')
			ft_putstr("0x");
		else if (specs->specifier == 'X')
			ft_putstr("0X");
		else if ((specs->specifier == 'o' || specs->specifier == 'O') &&
				specs->precision < line_len)
			write(1, "0", 1);
	}
}

size_t	get_line_length(t_specs *specs, char *converted_str)
{
	size_t line_len;

	line_len = ft_strlen(converted_str);
	if (is_specifier(specs->specifier, "dDi") && converted_str[0] != '-')
	{
		if (specs->force_sign == 1 || specs->add_space == 1)
			line_len++;
		if (specs->force_sign == 1)
			specs->precision++;
	}
	else if (specs->specifier == 'p' || ((specs->specifier == 'x' ||
			specs->specifier == 'X') && specs->alt_conversion == 1))
	{
		line_len += 2;
		specs->precision += 2;
	}
	else if ((specs->specifier == 'o' || specs->specifier == 'O') && specs->alt_conversion == 1)
		line_len++;
	specs->precision -= line_len;
	if (is_specifier(specs->specifier, "dDi") && (converted_str[0] == '-' || specs->add_space == 1))
		specs->precision++;
	if (specs->precision > 0)
		line_len += specs->precision;
	return (line_len);
}

size_t	handle_conversion_specs(t_specs specs, char *converted_str)
{
	size_t line_len;

	line_len = get_line_length(&specs, converted_str);
	if (specs.left_justify == 1)
		handle_prefixes(&specs, converted_str, (int)line_len);
	if (specs.min_field_width > 0 && specs.left_justify == 0)
		handle_field_width(specs, &line_len);
	if (specs.left_justify == 0)
		handle_prefixes(&specs, converted_str, (int)line_len);
	if (specs.precision > 0)
		handle_precision(specs);
	return (line_len);
}
