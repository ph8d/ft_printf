/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:05:40 by rtarasen          #+#    #+#             */
/*   Updated: 2017/11/05 15:58:58 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t result;

	i = ft_strlen(dst);
	j = 0;
	result = ft_strlen(dst) + ft_strlen(src);
	if (size < ft_strlen(dst))
		return (size + ft_strlen(src));
	while (i < (size - 1))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	if (dst[i] != '\0')
		dst[i] = '\0';
	return (result);
}
