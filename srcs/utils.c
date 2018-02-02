/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:42:23 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/02 14:55:54 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_specifier(char c, char* specifier)
{
	while (*specifier != '\0')
	{
		if (c == *specifier)
			return (1);
		specifier++;
	}
	return (0);
}

size_t	get_base_value(t_specs specs)
{
	if (specs.specifier == 'o' || specs.specifier == 'O')
		return (8);
	if (specs.specifier == 'x' || specs.specifier == 'X' ||
		specs.specifier == 'p')
		return (16);
	return (10);
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

size_t get_unsigned_data_type(va_list *arg_list, t_specs specs)
{
	if (specs.size_modifier == h)
		return (va_arg(*arg_list, unsigned short int));
	else if (specs.size_modifier == hh)
		return (va_arg(*arg_list, unsigned char));
	else if (specs.size_modifier == l)
		return (va_arg(*arg_list, unsigned long int));
	else if (specs.size_modifier == ll)
		return (va_arg(*arg_list, unsigned long long int));
	else if (specs.size_modifier == j)
		return (va_arg(*arg_list, uintmax_t));
	else if (specs.size_modifier == z)
		return (va_arg(*arg_list, size_t));
	else
		return (va_arg(*arg_list, unsigned int));
}

ssize_t get_signed_data_type(va_list *arg_list, t_specs specs)
{
	if (specs.size_modifier == h)
		return (va_arg(*arg_list, short int));
	else if (specs.size_modifier == hh)
		return (va_arg(*arg_list, unsigned int));
	else if (specs.specifier == 'D' || specs.size_modifier == l)
		return (va_arg(*arg_list, long int));
	else if (specs.size_modifier == ll)
		return (va_arg(*arg_list, long long int));
	else if (specs.size_modifier == j)
		return (va_arg(*arg_list, intmax_t));
	else if (specs.size_modifier == z)
		return (va_arg(*arg_list, ssize_t));
	else
		return (va_arg(*arg_list, int));
}
