/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 15:09:12 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/03 17:08:13 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_base_value(t_specs specs)
{
	if (specs.specifier == 'o' || specs.specifier == 'O')
		return (8);
	if (specs.specifier == 'x' || specs.specifier == 'X' ||
		specs.specifier == 'p')
		return (16);
	return (10);
}

void	print_hex_uppercase(char *str)
{
	int i;
	int c;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) == 1)
			c = str[i] - 32;
		else
			c = str[i];
		write(1, &c, 1);
		i++;
	}
}

ssize_t	get_signed_data_type(va_list *arg_list, t_specs specs)
{
	if (specs.size_modifier == h)
		return ((short int)va_arg(*arg_list, ssize_t));
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

size_t	get_unsigned_data_type(va_list *arg_list, t_specs specs)
{
	if (specs.size_modifier == h)
		return ((unsigned short int)va_arg(*arg_list, size_t));
	else if (specs.size_modifier == hh)
		return ((unsigned char)va_arg(*arg_list, size_t));
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
