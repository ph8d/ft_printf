/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:21:49 by rtarasen          #+#    #+#             */
/*   Updated: 2017/11/11 17:13:00 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_reverse(char *s, int n)
{
	size_t i;

	i = ft_strlen(s);
	if (n < 0)
		ft_putchar('-');
	while (i-- != 0)
		ft_putchar(s[i]);
}

void			ft_putnbr(int n)
{
	size_t	i;
	int		temp;
	char	result[12];

	temp = n;
	i = 0;
	if (n == 0)
		ft_putchar('0');
	else if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
			temp = n * -1;
		while (temp != 0)
		{
			result[i++] = (temp % 10) + '0';
			temp = temp / 10;
		}
		result[i] = '\0';
		ft_reverse(result, n);
	}
}
