/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:34:18 by jubaldo           #+#    #+#             */
/*   Updated: 2023/02/23 21:50:00 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nbr(int nb, int *len)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_len('-', len);
		ft_nbr(nb * -1, len);
	}
	else
	{
		if (nb > 9)
			ft_nbr(nb / 10, len);
		ft_putchar_len(nb % 10 + '0', len);
	}
}
