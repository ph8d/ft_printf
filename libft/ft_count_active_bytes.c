/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_active_bytes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:28:58 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/02 17:29:03 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_active_bytes(unsigned int value)
{
	int i;
	int active_bit_pos;

	i = 0;
	active_bit_pos = 0;
	while (i != 32)
	{
		if ((value & 1) == 1)
			active_bit_pos = i;
		value = value >> 1;
		i++;
	}
	if (active_bit_pos <= 7)
		return (1);
	else if (active_bit_pos <= 11)
		return (2);
	else if (active_bit_pos <= 16)
		return (3);
	else
		return (4);
}
