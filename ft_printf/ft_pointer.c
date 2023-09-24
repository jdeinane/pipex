/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:55:34 by jubaldo           #+#    #+#             */
/*   Updated: 2023/03/21 16:00:05 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer(size_t ptr, int *len)
{
	char	str[25];
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (!ptr)
		ft_str("(nil)", len);
	else
	{
		write (1, "0x", 2);
		(*len) += 2;
	}
	while (ptr != 0)
	{
		str[i] = base[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
	{
		ft_putchar_len(str[i], len);
	}
}
