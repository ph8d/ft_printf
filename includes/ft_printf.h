/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:52:34 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/06 20:28:31 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "..libft/includes/libft.h"

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
	char	padding_char;
	int		min_field_width;
	int		precision;
	t_size	size_modifier;
}				t_specs;

int				is_specifier(char c, char *specifier);
int				cut_digit_from_string(char **str);
size_t			get_line_length(t_specs *specs, char *converted_str);
size_t			get_unicode_str_len(t_specs specs, unsigned int *str);

size_t			get_base_value(t_specs specs);
void			print_hex_uppercase(char *str);
ssize_t			get_signed_data_type(va_list *arg_list, t_specs specs);
size_t			get_unsigned_data_type(va_list *arg_list, t_specs specs);

int				handle_percent(t_specs specs);
size_t			handle_str_null(t_specs specs);
int				handle_undefined_specifier(t_specs specs, char current_char);

int				handle_int(t_specs specs, va_list *arg_list);
int				handle_int_u(t_specs specs, va_list *arg_list);

int				handle_str_wide(t_specs specs, va_list *arg_list);
int				handle_str(t_specs specs, va_list *arg_list);
int				handle_char_wide(t_specs specs, va_list *arg_list);
int				handle_char(t_specs specs, va_list *arg_list);

void			handle_precision(t_specs specs);
void			handle_field_width(t_specs specs, size_t *str_len);
void			handle_prefixes_hex(t_specs *specs, char *str);
void			handle_prefixes(t_specs *specs, char *str);
size_t			handle_conversion_specs(t_specs specs, char *converted_str);

t_size			t_specs_get_size_modifier(char **str);
void			t_specs_init(t_specs *specs);
char			*t_specs_get_specs(t_specs *specs, char *format);

int				ft_printf(const char *format, ...);

#endif
