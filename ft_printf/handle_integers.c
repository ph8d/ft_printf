/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:36:48 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/07 17:21:08 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_int_u(t_specs specs, va_list *arg_list)
{
	int			i;
	size_t		integer;
	size_t		str_len;
	char		*int_str;

	i = 0;
	integer = get_unsigned_data_type(arg_list, specs);
	if ((int_str = ft_itoa_base(integer, get_base_value(specs), 0)) == NULL)
		return (0);
	str_len = handle_conversion_specs(specs, int_str);
	if (int_str[0] == '-')
		i++;
	if (!(specs.precision == 0 && integer == 0 &&
		is_specifier(specs.specifier, "oOuUxXdDip")))
	{
		if (specs.specifier == 'X')
			print_hex_uppercase(int_str);
		while (int_str[i] != '\0' && specs.specifier != 'X')
			write(1, &int_str[i++], 1);
	}
	free(int_str);
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
	char		*int_str;

	i = 0;
	is_negative = 0;
	if ((integer = get_signed_data_type(arg_list, specs)) < 0)
	{
		integer *= -1;
		is_negative = 1;
		i++;
	}
	int_str = ft_itoa_base((size_t)integer, 10, is_negative);
	str_len = handle_conversion_specs(specs, int_str);
	if (!(specs.precision == 0 && integer == 0))
		while (int_str[i] != '\0')
			write(1, &int_str[i++], 1);
	free(int_str);
	if (specs.left_justify == 1)
		handle_field_width(specs, &str_len);
	return ((int)str_len);
}
