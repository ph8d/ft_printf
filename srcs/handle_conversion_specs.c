/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion_specs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:46:54 by rtarasen          #+#    #+#             */
/*   Updated: 2018/01/31 17:02:27 by rtarasen         ###   ########.fr       */
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

void	handle_field_width(t_specs specs, char *str, size_t *str_len)
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

void	handle_prefixes(t_specs *specs, char *str)
{
	if (is_decimal(specs->specifier) == 1)
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
}

size_t	get_line_length(t_specs *specs, char *converted_str)
{
	size_t line_len;

	line_len = ft_strlen(converted_str);
	if (is_decimal(specs->specifier) && converted_str[0] != '-')
	{
		if (specs->force_sign == 1)
		{
			line_len++;
			specs->precision++;
		}
		else if (specs->add_space == 1)
			line_len++;
	}
	else if (specs->specifier == 'p')
	{
		line_len += 2;
		specs->precision += 2;
	}
	specs->precision -= line_len;
	if (is_decimal(specs->specifier) && (converted_str[0] == '-' || specs->add_space == 1))
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
		handle_prefixes(&specs, converted_str);
	if (specs.min_field_width > 0 && specs.left_justify == 0)
		handle_field_width(specs, converted_str, &line_len);
	if (specs.left_justify == 0)
		handle_prefixes(&specs, converted_str);
	if (specs.precision > 0)
		handle_precision(specs);
	return (line_len);
}
