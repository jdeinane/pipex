/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:10:33 by jubaldo           #+#    #+#             */
/*   Updated: 2023/09/23 14:53:54 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_error(char **cmd)
{
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, ": command not found.\n", 21);
	free_args(cmd);
	exit(EXIT_FAILURE);
}

void	terminate(char *t)
{
	if (errno == 0)
		write(2, "Error.\n", 7);
	else
		perror(t);
	exit(EXIT_FAILURE);
}

void	args_error(void)
{
	write(2, "Invalid arguments.\n", 19);
	exit(EXIT_FAILURE);
}

void	envi(char **envp)
{
	ft_printf("envp =%s\n", envp[0]);
	write(2, "Environment variables ignored, path is empty.\n", 46);
	exit(EXIT_FAILURE);
}
