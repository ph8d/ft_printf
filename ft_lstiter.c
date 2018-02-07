/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:05:42 by rtarasen          #+#    #+#             */
/*   Updated: 2017/11/14 14:18:06 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
	t_list *temp;

	if (lst != NULL && f != NULL)
	{
		while (lst->next != NULL)
		{
			temp = lst;
			lst = lst->next;
			f(temp);
		}
		f(lst);
	}
}
