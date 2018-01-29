/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:36:48 by rtarasen          #+#    #+#             */
/*   Updated: 2018/01/29 12:42:38 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_decimal(t_specs conversion_specs, va_list *arg_list)
{
	int		i;
	size_t	str_len;
	char	*decimal;

	i = 0;
	if ((decimal = ft_itoa(va_arg(*arg_list, int))) == NULL)
		return (0);
	str_len = handle_conversion_specs(conversion_specs, decimal);
	if (decimal[0] == '-')
		i++;
	while (decimal[i] != '\0')
		write(1, &decimal[i++], 1);
	free(decimal);
	if (conversion_specs.left_justify == 1)
		handle_min_field_width(conversion_specs, decimal, &str_len);
	return ((int)str_len);
}

int		handle_decimal_long(t_specs conversion_specs, va_list *arg_list)
{
	int			i;
	int			is_negative;
	long int	decimal;
	size_t		str_len;
	char		*decimal_str;

	i = 0;
	is_negative = 0;
	if ((decimal = va_arg(*arg_list, long int)) < 0)
	{
		decimal *= -1;
		is_negative = 1;
	}
	decimal_str = ft_itoa_base((size_t)decimal, 10, is_negative);
	str_len = handle_conversion_specs(conversion_specs, decimal_str);
	while (decimal_str[i] != '\0')
		write(1, &decimal_str[i++], 1);
	free(decimal_str);
	if (conversion_specs.left_justify == 1)
		handle_min_field_width(conversion_specs, decimal_str, &str_len);
	return ((int)str_len);
}
