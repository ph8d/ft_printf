/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:36:48 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/03 18:09:53 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_int_u(t_specs specs, va_list *arg_list)
{
	int			i;
	size_t		base;
	size_t		integer;
	size_t		str_len;
	char		*integer_str;

	i = 0;
	base = get_base_value(specs);
	integer = get_unsigned_data_type(arg_list, specs);
	if ((integer_str = ft_itoa_base(integer, base, 0)) == NULL)
		return (0);
	str_len = handle_conversion_specs(specs, integer_str);
	if (integer_str[0] == '-')
		i++;
	if (specs.specifier == 'X')
		print_hex_uppercase(integer_str);
	else if (!(specs.precision == 0 && integer_str[0] == '0' && integer_str[1] == '\0'))
	{
		while (integer_str[i] != '\0')
			write(1, &integer_str[i++], 1);
	}
	free(integer_str);
	if (specs.left_justify == 1)
		handle_field_width(specs, &str_len);
	return ((int)str_len);
}

int		handle_int(t_specs specs, va_list *arg_list)
{
	int			i;
	int			is_negative;
	ssize_t		integer;
	size_t		str_len;
	char		*integer_str;

	i = 0;
	is_negative = 0;
	if ((integer = get_signed_data_type(arg_list, specs)) < 0)
	{
		integer *= -1;
		is_negative = 1;
		i++;
	}
	integer_str = ft_itoa_base((size_t)integer, 10, is_negative);
	str_len = handle_conversion_specs(specs, integer_str);
	if (!(specs.precision == 0 && integer_str[0] == '0' && integer_str[1] == '\0'))
		while (integer_str[i] != '\0')
			write(1, &integer_str[i++], 1);
	free(integer_str);
	if (specs.left_justify == 1)
		handle_field_width(specs, &str_len);
	return ((int)str_len);
}
