/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:20:49 by rtarasen          #+#    #+#             */
/*   Updated: 2017/11/09 18:17:27 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_len(int *n)
{
	int len;
	int temp;

	len = 0;
	if (*n < 0)
	{
		len++;
		*n = (*n) * -1;
	}
	temp = *n;
	while (temp != 0)
	{
		temp = temp / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	size_t	len;
	int		temp;
	char	*result;

	len = get_len(&n);
	temp = n;
	if (n == 0)
		return ((result = ft_strdup("0")));
	if (n == -2147483648)
		return ((result = ft_strdup("-2147483648")));
	result = ft_strnew(len);
	if (result == NULL)
		return (NULL);
	while (temp != 0)
	{
		result[--len] = (temp % 10) + '0';
		temp = temp / 10;
	}
	if (result[0] == '\0')
		(result[0] = '-');
	return (result);
}
