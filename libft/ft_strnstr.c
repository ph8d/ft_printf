/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:56:45 by rtarasen          #+#    #+#             */
/*   Updated: 2017/11/11 13:02:01 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t checkpoint;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[j])
		{
			checkpoint = i;
			while (i < len && haystack[i++] == needle[j++])
				if (needle[j] == '\0')
					return ((char*)haystack + (i - ft_strlen(needle)));
			i = checkpoint;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
