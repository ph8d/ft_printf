/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:16:19 by rtarasen          #+#    #+#             */
/*   Updated: 2017/11/15 18:11:47 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarr_del(char ***str_arr)
{
	size_t i;

	i = 0;
	if (str_arr != NULL)
	{
		while (*(*str_arr + i) != 0)
		{
			free(*(*str_arr + i));
			i++;
		}
		free(*str_arr);
		*str_arr = NULL;
	}
}
