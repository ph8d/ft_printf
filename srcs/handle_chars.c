/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:35:47 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/05 11:40:26 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_printf.h"

int 	handle_percent(t_specs specs)
{
	size_t	str_len;

	str_len = 1;
	if (specs.left_justify == 0 && specs.min_field_width > 0)
		handle_field_width(specs, &str_len);
	write(1, "%", 1);
	if (specs.left_justify == 1 && specs.min_field_width > 0)
		handle_field_width(specs, &str_len);
	return ((int)str_len);
}

int		handle_str_wide(t_specs specs, va_list *arg_list)
{
	int				i;
	size_t			bytes_to_print;
	size_t			str_len;
	unsigned int	*str_wide;

	if ((str_wide = va_arg(*arg_list, unsigned int *)) == NULL)
		str_len = handle_str_null(specs);
	else
	{
		str_len = get_unicode_str_len(specs, str_wide);
		bytes_to_print = str_len;
		if (specs.left_justify == 0 && specs.min_field_width > 0)
			handle_field_width(specs, &str_len);
		i = 0;
		while (bytes_to_print != 0)
		{
			ft_uchar(str_wide[i]);
			bytes_to_print -= ft_count_active_bytes(str_wide[i]);
			i++;
		}
		if (specs.left_justify == 1 && specs.min_field_width > 0)
			handle_field_width(specs, &str_len);
	}
	return ((int)str_len);
}

int		handle_str(t_specs specs, va_list *arg_list)
{
	int		i;
	size_t	line_len;
	char	*str;

	i = 0;
	if ((str = va_arg(*arg_list, char *)) == NULL)
		line_len = handle_str_null(specs);
	else
	{
		if ((int)(line_len = ft_strlen(str)) > specs.precision && specs.precision >= 0)
			line_len = (size_t)specs.precision;
		if (specs.left_justify == 0 && specs.min_field_width > 0)
			handle_field_width(specs, &line_len);
		while (str[i] != '\0' && i != specs.precision)
			write(1, &str[i++], 1);
		if (specs.left_justify == 1 && specs.min_field_width > 0)
			handle_field_width(specs, &line_len);
	}
	return ((int)line_len);
}

int		handle_char_wide(t_specs specs, va_list *arg_list)
{
	size_t			line_len;
	unsigned int	c_wide;

	c_wide = (unsigned int)va_arg(*arg_list, int);
	line_len = (size_t)ft_count_active_bytes(c_wide);
	if (specs.left_justify == 0 && specs.min_field_width > 0)
		handle_field_width(specs, &line_len);
	if (MB_CUR_MAX <= 1)
		write(1, &c_wide, 1);
	else
		ft_uchar(c_wide);
	if (specs.left_justify == 1 && specs.min_field_width > 0)
		handle_field_width(specs, &line_len);
	return ((int)line_len);
}

int		handle_char(t_specs specs, va_list *arg_list)
{
	int		c;
	size_t	str_len;

	str_len = 1;
	c = va_arg(*arg_list, int);
	if (specs.left_justify == 0 && specs.min_field_width > 0)
		handle_field_width(specs, &str_len);
	write(1, &c, 1);
	if (specs.left_justify == 1 && specs.min_field_width > 0)
		handle_field_width(specs, &str_len);
	return ((int)str_len);
}
