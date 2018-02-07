/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrtolst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:04:59 by rtarasen          #+#    #+#             */
/*   Updated: 2017/11/16 18:23:36 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_arrtolst(char **arr, size_t size)
{
	size_t	i;
	t_list	*res;
	t_list	*start;
	void	*f_delcontent;

	i = 0;
	f_delcontent = &ft_lstdelcontent;
	if (arr == NULL || *arr == NULL || size == 0)
		return (NULL);
	if ((res = ft_lstnew(*(arr + i), ft_strlen(*(arr + i)) + 1)) == NULL)
		return (NULL);
	start = res;
	i++;
	while (*(arr + i) != 0 && i != size)
	{
		res->next = ft_lstnew(*(arr + i), ft_strlen(*(arr + i)) + 1);
		if ((res = res->next) == NULL)
		{
			ft_lstdel(&start, f_delcontent);
			return (NULL);
		}
		i++;
	}
	return (start);
}
