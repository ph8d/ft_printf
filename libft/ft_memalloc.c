/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:43:58 by rtarasen          #+#    #+#             */
/*   Updated: 2017/11/16 15:26:21 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*result;

	i = 0;
	if (size == 0)
		return (NULL);
	result = (unsigned char *)malloc(size);
	if (result == NULL)
		return (NULL);
	else
	{
		while (i < size)
		{
			result[i] = 0;
			i++;
		}
		return (result);
	}
}
