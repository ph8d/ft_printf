/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:35:47 by rtarasen          #+#    #+#             */
/*   Updated: 2018/01/29 15:19:15 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_char_wide(t_specs conversion_specs, va_list *arg_list)
{
	unsigned int c_wide;

	c_wide = (unsigned int)va_arg(*arg_list, int);
	if (MB_CUR_MAX <= 1)
		write(1, &c_wide, 1);
	else
		ft_uchar(c_wide);
	return (1);
}

int		handle_char(va_list *arg_list)
{
	int c;

	c = va_arg(*arg_list, int);
	write(1, &c, 1);
	return (1);
}

int		handle_str_wide(t_specs conversion_specs, va_list *arg_list)
{
	int				i;
	unsigned int	*str_wide;

	i = 0;
	str_wide = va_arg(*arg_list, unsigned int *);

	//
	//	TODO Wide string
	//
	return (0);
}

int		handle_str(t_specs specs, va_list *arg_list)
{
	int		i;
	size_t	line_len;
	char	*str;

	i = 0;
	str = va_arg(*arg_list, char *);
	if ((line_len = ft_strlen(str)) > specs.precision)
		line_len = (size_t)specs.precision;
	if (specs.left_justify == 0)
		handle_field_width(specs, str, &line_len);
	while (str[i] != '\0' && i != specs.precision)
		write(1, &str[i++], 1);
	if (specs.left_justify == 1)
		handle_field_width(specs, str, &line_len);
	return ((int)line_len);
}
