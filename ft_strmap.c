/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:35:40 by rtarasen          #+#    #+#             */
/*   Updated: 2017/11/16 14:43:42 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*result;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	result = ft_strnew(ft_strlen(s));
	if (result == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		result[i] = f(s[i]);
		i++;
	}
	return (result);
}
