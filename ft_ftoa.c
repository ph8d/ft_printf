/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:12:14 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/09 17:51:17 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*get_fractional_part(double nb, int precision)
{
	int		i;
	size_t	integer_tmp;
	char	*str_tmp;
	char	*result;

	i = 0;
	nb += 1.0 / ft_power(10, precision + 1);
	str_tmp = ft_strnew(precision);
	while (i != precision)
	{
		nb *= 10;
		integer_tmp = (size_t)nb;
		str_tmp[i] = (integer_tmp + '0');
		nb -= integer_tmp;
		i++;
	}
	result = ft_strjoin(".", str_tmp);
	free(str_tmp);
	return (result);
}

static	char	*get_integer_part(double *nb)
{
	size_t	integer_part;
	int		is_negative;
	char	*result;

	is_negative = 0;
	if (*nb < 0)
	{
		*nb = *nb * -1;
		is_negative = 1;
	}
	integer_part = (size_t)(*nb);
	result = ft_itoa_base(integer_part, 10, is_negative);
	return (result);
}

char			*ft_ftoa(double nb, int precision)
{
	char	*integer_part;
	char	*fractional_part;
	char	*result;

	if (precision == 0 && (nb - (int)nb) >= 0.6)
		nb++;
	else if (precision < 0)
		precision = 6;
	integer_part = get_integer_part(&nb);
	if (precision > 0)
		fractional_part = get_fractional_part(nb - (size_t)nb, precision);
	else
		fractional_part = "";
	result = ft_strjoin(integer_part, fractional_part);
	free(integer_part);
	if (precision != 0)
		free(fractional_part);
	return (result);
}
