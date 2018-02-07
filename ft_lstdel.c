/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:42:22 by rtarasen          #+#    #+#             */
/*   Updated: 2017/11/16 17:39:43 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list *temp;

	if (alst != NULL && del != NULL)
	{
		while ((*alst)->next != NULL)
		{
			temp = *alst;
			*alst = (*alst)->next;
			del(temp->content, temp->content_size);
			free(temp);
		}
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = (NULL);
	}
}
