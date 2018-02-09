/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:40:43 by rtarasen          #+#    #+#             */
/*   Updated: 2018/02/09 17:49:59 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int number, int power)
{
	int result;

	result = number;
	if (number <= 0 || power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (--power > 0)
		result *= number;
	return (result);
}
