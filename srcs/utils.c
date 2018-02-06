/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:42:23 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/05 17:34:30 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_specifier(char c, char *specifier)
{
	while (*specifier != '\0')
	{
		if (c == *specifier)
			return (1);
		specifier++;
	}
	return (0);
}

int		cut_digit_from_string(char **str)
{
	int		result;
	size_t	digit_length;
	char	*digit;

	result = 0;
	digit_length = 0;
	if ((*str)[0] == '.')
	{
		if (ft_isdigit((*str)[1]))
			(*str)++;
		else
			return (0);
	}
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

size_t	handle_str_null(t_specs specs)
{
	int		i;
	char	*str;
	size_t	line_len;

	i = 0;
	str = "(null)";
	if ((int)(line_len = ft_strlen(str)) > specs.precision && specs.precision >= 0)
		line_len = (size_t)specs.precision;
	if (specs.left_justify == 0 && specs.min_field_width > 0)
		handle_field_width(specs, &line_len);
	while (str[i] != '\0' && i != specs.precision)
		write(1, &str[i++], 1);
	if (specs.left_justify == 1 && specs.min_field_width > 0)
		handle_field_width(specs, &line_len);
	return (line_len);
}

size_t	get_line_length(t_specs *specs, char *str)	//	<--- TODO fix this func!
{
	size_t line_len;

	if (specs->precision == 0 && str[0] == '0' && str[1] == '\0' && specs->specifier != 'o' && specs->specifier != 'O')
		line_len = 0;
	else
		line_len = ft_strlen(str);
	if (is_specifier(specs->specifier, "dDi") && str[0] != '-')
	{
		if (specs->force_sign == 1 || specs->add_space == 1)
			line_len++;
		if (specs->force_sign == 1)
			specs->precision++;
	}
	else if (specs->specifier == 'p' || ((specs->specifier == 'x' ||
			specs->specifier == 'X') && specs->alt_conversion == 1))
	{
		if (specs->specifier == 'p' || !(str[0] == '0' && str[1] == '\0'))
		{
			line_len += 2;
			specs->precision += 2;
		}
	}
	else if ((specs->specifier == 'o' || specs->specifier == 'O')
			 && specs->alt_conversion == 1 && !(str[0] == '0' && str[1] == '\0'))
		line_len++;
	specs->precision -= line_len;
	if (is_specifier(specs->specifier, "dDi") && (str[0] == '-' || specs->add_space == 1))
		specs->precision++;
	if (specs->precision > 0)
		line_len += specs->precision;
	return (line_len);
}

size_t	get_unicode_str_len(t_specs specs, unsigned int *str)
{
	size_t	len;
	int		current_char_len;

	len = 0;
	while (*str != '\0')
	{
		current_char_len = ft_count_active_bytes(*str);
		if (specs.precision >= 0 && (int)(len + current_char_len) > specs.precision)
			break ;
		else
			len += ft_count_active_bytes(*(str++));
	}
	return (len);
}
