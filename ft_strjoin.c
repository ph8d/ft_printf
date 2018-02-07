/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:32:40 by rtarasen          #+#    #+#             */
/*   Updated: 2017/11/16 14:43:23 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*result;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((ft_strlen(s1) + ft_strlen(s2)) == 0)
		return (result = ft_strdup(""));
	if ((result = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		result[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		result[i] = *s2;
		i++;
		s2++;
	}
	return (result);
}
