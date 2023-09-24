# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 21:01:11 by jubaldo           #+#    #+#              #
#    Updated: 2023/09/22 12:13:54 by jubaldo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = error.c main.c pipex.c utils.c

NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
			make -C libft/ && mv libft/libft.a .
			make -C ft_printf/ && mv ft_printf/libftprintf.a .
			$(CC) -o $(NAME) $(OBJS) libft.a libftprintf.a

clean:
		make clean -C libft/
		make clean -C ft_printf/
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME) libft.a
		$(RM) $(NAME) libftprintf.a 
re: fclean all

.PHONY:	all clean fclean re
