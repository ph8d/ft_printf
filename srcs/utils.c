/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:42:23 by rtarasen          #+#    #+#             */
/*   Updated: 2018/01/29 15:13:22 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_decimal(char c)
{
	char *is_decimal;

	is_decimal = "dDi";
	while (*is_decimal != '\0')
	{
		if (c == *is_decimal)
			return (1);
		is_decimal++;
	}
	return (0);
}

int		is_specifier(char c)
{
	char *is_specifier;

	is_specifier = "sSpdDioOuUxXcC";
	while (*is_specifier != '\0')
	{
		if (c == *is_specifier)
			return (1);
		is_specifier++;
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
