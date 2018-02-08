/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:42:23 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/08 13:54:55 by rtarasen         ###   ########.fr       */
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

void	cut_digit_from_string(t_specs *specs, char **str)
{
	size_t	digit_len;
	char	*digit;
	int		*dest;

	digit_len = 0;
	dest = &specs->min_field_width;
	if ((*str)[0] == '.')
	{
		if (!ft_isdigit((*str)[1]))
		{
			specs->precision = 0;
			return ;
		}
		(*str)++;
		dest = &specs->precision;
	}
	while (ft_isdigit((*str)[digit_len]) && (*str)[digit_len] != '\0')
		digit_len++;
	if (digit_len != 0)
	{
		digit = ft_strsub(*str, 0, digit_len);
		*dest = ft_atoi(digit);
		free(digit);
		(*str) += digit_len - 1;
	}
}

size_t	get_alt_conversion_len(t_specs *specs, char *str)
{
	char specifier;

	specifier = specs->specifier;
	if (specifier == 'p' || specifier == 'x' || specifier == 'X')
	{
		if (specifier == 'p' || !(str[0] == '0' && str[1] == '\0'))
		{
			specs->precision += 2;
			return (2);
		}
	}
	else if (specifier == 'o' || specifier == 'O')
	{
		if (!(specs->precision < 0 && str[0] == '0'))
			return (1);
	}
	return (0);
}

size_t	get_line_length(t_specs *specs, char *str)
{
	size_t line_len;

	if ((specs->precision == 0 && str[0] == '0') &&
		is_specifier(specs->specifier, "oOuUxXdDip"))
		line_len = 0;
	else
		line_len = ft_strlen(str);
	if (is_specifier(specs->specifier, "dDi"))
	{
		if (str[0] != '-' && (specs->force_sign == 1 || specs->add_space == 1))
		{
			line_len++;
			specs->precision++;
		}
		else if (str[0] == '-' || specs->add_space == 1)
			specs->precision++;
	}
	else if (specs->alt_conversion == 1 || specs->specifier == 'p')
		line_len += get_alt_conversion_len(specs, str);
	specs->precision -= line_len;
	if (specs->precision > 0)
		line_len += specs->precision;
	return (line_len);
}

size_t	get_unicode_str_len(int precision, unsigned int *str)
{
	size_t	len;
	int		current_char_len;

	len = 0;
	while (*str != '\0')
	{
		current_char_len = ft_count_active_bytes(*str);
		if (precision >= 0 && (int)(len + current_char_len) > precision)
			break ;
		else
			len += ft_count_active_bytes(*(str++));
	}
	return (len);
}
