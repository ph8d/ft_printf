/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:23:56 by rtarasen          #+#    #+#             */
/*   Updated: 2017/11/16 12:21:11 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_delcontent(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}

t_list			*ft_lstmap(t_list *lst, t_list *(f) (t_list *elem))
{
	void	*f_delcontent;
	t_list	*start;
	t_list	*result;

	f_delcontent = &ft_delcontent;
	if (f == NULL || lst == NULL)
		return (NULL);
	result = f(lst);
	start = result;
	lst = lst->next;
	while (lst != NULL)
	{
		if ((result->next = f(lst)) == NULL)
		{
			ft_lstdel(&start, f_delcontent);
			return (NULL);
		}
		result = result->next;
		lst = lst->next;
	}
	return (start);
}
