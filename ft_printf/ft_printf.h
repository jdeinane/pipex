/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:26:05 by jubaldo           #+#    #+#             */
/*   Updated: 2023/03/21 14:43:08 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

int		ft_printf(const char *str, ...);
void	ft_hexadecimal(unsigned int x, int *len, char xx);
void	ft_nbr(int nb, int *len);
void	ft_pointer(size_t ptr, int *len);
void	ft_putchar_len(char c, int *len);
void	ft_str(char *args, int *len);
void	ft_unsigned_int(unsigned int u, int *len);

#endif