# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 12:23:55 by jubaldo           #+#    #+#              #
#    Updated: 2023/09/21 00:26:59 by jubaldo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_hexadecimal.c ft_nbr.c ft_pointer.c ft_putchar_len.c \
		ft_unsigned_int.c ft_str.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a
AR = ar crs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -c

all: ${NAME}

%.o : %.c
		${CC} ${CFLAGS} $< -o $@

${NAME}: ${OBJS}
		${AR} ${NAME} ${OBJS}

clean: 
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re