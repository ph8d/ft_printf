/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 17:31:01 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/02 17:34:49 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MASK1 (unsigned int)49280
#define MASK2 (unsigned int)14712960
#define MASK3 (unsigned int)4034953344

#include "libft.h"
#include <unistd.h>

static	void	four_bytes(unsigned int c, unsigned int *byte)
{
	unsigned int octet;

	byte[3] = (c << 26) >> 26;
	byte[2] = ((c >> 6) << 26) >> 26;
	byte[1] = ((c >> 12) << 26) >> 26;
	byte[0] = ((c >> 18) << 29) >> 29;
	octet = (MASK3 >> 24) | byte[0];
	write(1, &octet, 1);
	octet = ((MASK3 << 8) >> 24) | byte[1];
	write(1, &octet, 1);
	octet = ((MASK3 << 16) >> 24) | byte[2];
	write(1, &octet, 1);
	octet = ((MASK3 << 24) >> 24) | byte[3];
	write(1, &octet, 1);
}

static	void	three_bytes(unsigned int c, unsigned int *byte)
{
	unsigned int octet;

	byte[2] = (c << 26) >> 26;
	byte[1] = ((c >> 6) << 26) >> 26;
	byte[0] = ((c >> 12) << 28) >> 28;
	octet = (MASK2 >> 16) | byte[0];
	write(1, &octet, 1);
	octet = ((MASK2 << 16) >> 24) | byte[1];
	write(1, &octet, 1);
	octet = ((MASK2 << 24) >> 24) | byte[2];
	write(1, &octet, 1);
}

void			ft_uchar(unsigned int c)
{
	int				active_bytes;
	unsigned int	byte[4];
	unsigned int	octet;

	active_bytes = ft_count_active_bytes(c);
	if (active_bytes == 1)
		write(1, &c, 1);
	else if (active_bytes == 2)
	{
		byte[1] = (c << 26) >> 26;
		byte[0] = ((c >> 6) << 27) >> 27;
		octet = (MASK1 >> 8) | byte[0];
		write(1, &octet, 1);
		octet = ((MASK1 << 24) >> 24) | byte[1];
		write(1, &octet, 1);
	}
	else if (active_bytes == 3)
		three_bytes(c, byte);
	else
		four_bytes(c, byte);
}
