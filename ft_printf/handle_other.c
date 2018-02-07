/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:14:46 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/07 17:21:35 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_percent(t_specs specs)
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

size_t	handle_str_null(t_specs specs)
{
	int		i;
	char	*str;
	size_t	line_len;

	i = 0;
	str = "(null)";
	if ((int)(line_len = ft_strlen(str)) > specs.precision &&
		specs.precision >= 0)
		line_len = (size_t)specs.precision;
	if (specs.left_justify == 0 && specs.min_field_width > 0)
		handle_field_width(specs, &line_len);
	while (str[i] != '\0' && i != specs.precision)
		write(1, &str[i++], 1);
	if (specs.left_justify == 1 && specs.min_field_width > 0)
		handle_field_width(specs, &line_len);
	return (line_len);
}

int		handle_undefined_specifier(t_specs specs, char current_char)
{
	size_t line_len;

	line_len = 1;
	if (specs.left_justify == 0 && specs.min_field_width > 0)
		handle_field_width(specs, &line_len);
	write(1, &current_char, 1);
	if (specs.left_justify == 1 && specs.min_field_width > 0)
		handle_field_width(specs, &line_len);
	return ((int)line_len);
}
