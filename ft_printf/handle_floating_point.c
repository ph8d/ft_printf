/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_floating_point.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:30:38 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/09 19:26:42 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_floating_point(t_specs specs, va_list *arg_list)
{
	int		i;
	double	number;
	size_t	line_len;
	char	*str;

	i = 0;
	number = va_arg(*arg_list, double);
	str = ft_ftoa(number, specs.precision);
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	free(str);
	line_len = handle_conversion_specs(specs, str);
	return ((int)line_len);
}
