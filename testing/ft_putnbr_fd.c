/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:35:20 by rtarasen          #+#    #+#             */
/*   Updated: 2017/11/11 17:17:18 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_reverse(char *s, int n, int fd)
{
	size_t i;

	i = ft_strlen(s);
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (i-- != 0)
		ft_putchar_fd(s[i], fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	size_t	i;
	int		temp;
	char	result[12];

	temp = n;
	i = 0;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
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
		ft_reverse(result, n, fd);
	}
}
