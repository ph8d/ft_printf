/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:38:52 by rtarasen          #+#    #+#             */
/*   Updated: 2018/01/29 12:38:23 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	get_result(size_t value, size_t base, char *buf, char **result)
{
	if (value >= base)
		get_result(value / base, base, buf, result);
	*(*result) = buf[value % base];
	(*result)++;
}

char			*ft_itoa_base(size_t value, size_t base, int is_negative)
{
	char *buf;
	char *result;
	char *result_tmp;

	if (base < 2 || base > 16)
		return (NULL);
	buf = "0123456789abcdef";
	result = ft_strnew(21);
	result_tmp = result;
	if (is_negative == 1)
	{
		result[0] = '-';
		result_tmp++;
	}
	get_result(value, base, buf, &result_tmp);
	return (result);
}
