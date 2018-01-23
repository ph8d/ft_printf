/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:33:02 by rtarasen          #+#    #+#             */
/*   Updated: 2017/11/15 16:48:02 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarr_new(size_t size)
{
	char **result;

	if ((result = (char **)malloc(sizeof(char *) * size)) == NULL)
		return (NULL);
	result[size - 1] = 0;
	return (result);
}
