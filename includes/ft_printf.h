/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:52:34 by rtarasen          #+#    #+#             */
/*   Updated: 2018/01/23 13:14:51 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef	enum	e_size
{
	none,
	h = 'h',
	hh = 'h' + 'h',
	l = 'l',
	ll = 'l' + 'l',
	j = 'j',
	z = 'z'
}				t_size;

typedef	struct	s_specs
{
	char	specifier;
	char	left_justify;
	char	force_sign;
	char	add_space;
	char	alt_conversion;
	char	pad_with_zeroes;
	int 	min_field_width;
	int		precision;
	t_size	size_modifier;
}				t_specs;

int				ft_printf(const char *format, ...);

#endif
