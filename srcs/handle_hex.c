/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:28:32 by rtarasen          #+#    #+#             */
/*   Updated: 2018/01/29 12:40:35 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_pointer(t_specs specs, va_list *arg_list)
{
	int		i;
	size_t	str_len;
	char	*pointer_address;

	i = 0;
	pointer_address = ft_itoa_base(va_arg(*arg_list, size_t), 16, 0);
	if (pointer_address == NULL)
		return (0);
	str_len = handle_conversion_specs(specs, pointer_address);
	while (pointer_address[i] != '\0')
		write(1, &pointer_address[i++], 1);
	free(pointer_address);
	if (specs.left_justify == 1)
		handle_min_field_width(specs, pointer_address, &str_len);
	return ((int)str_len);
}
