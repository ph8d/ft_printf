/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:40:21 by rtarasen          #+#    #+#             */
/*   Updated: 2017/11/16 17:01:10 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstfind(t_list *lst, void *content)
{
	size_t element_nb;

	element_nb = 0;
	while (lst != NULL && content != NULL)
	{
		element_nb++;
		if (ft_memcmp(lst->content, content, lst->content_size) == 0)
			return (element_nb);
		lst = lst->next;
	}
	return (0);
}
