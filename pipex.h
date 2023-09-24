/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:01:20 by jubaldo           #+#    #+#             */
/*   Updated: 2023/09/23 15:04:18 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

//process creation
void	first_child(int *pipefd, int *fd, char **av, char **envp);
void	second_child(int *pipefd, int *fd, char **av, char **envp);

// main
int		main(int ac, char **av, char **envp);

// parsing - utils
char	**get_path(char **envp);
char	*path(char *cmd, char **envp);
void	free_args(char **args);

// error gestion
void	cmd_error(char **cmd);
void	terminate(char *t);
void	args_error(void);
void	envi(char **envp);

#endif