/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 13:37:32 by rtarasen          #+#    #+#             */
/*   Updated: 2017/11/16 15:36:00 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*result;

	i = ft_strlen(s);
	result = (NULL);
	if (*(s + i) == c)
		return (result = (char *)(s + i));
	while (i-- != 0)
		if (*(s + i) == c)
			return (result = (char *)(s + i));
	return (NULL);
}
