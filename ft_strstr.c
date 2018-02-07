/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:57:41 by rtarasen          #+#    #+#             */
/*   Updated: 2017/11/16 14:44:38 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;
	size_t checkpoint;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[j])
		{
			checkpoint = i;
			while (haystack[i++] == needle[j++])
				if (needle[j] == '\0')
					return ((char*)haystack + (i - ft_strlen(needle)));
			i = checkpoint;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
