/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:36:45 by jubaldo           #+#    #+#             */
/*   Updated: 2023/09/23 14:54:31 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(int *pipefd, int *fd, char **av, char **envp)
{
	pid_t	pid;
	char	**cmd;

	pid = fork();
	if (pid < 0)
		terminate("fork");
	if (pid == 0)
	{
		fd[0] = open(av[1], O_RDONLY);
		if (fd[0] < 0)
			terminate(av[1]);
		cmd = ft_split(av[2], ' ');
		close(pipefd[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(fd[0]);
		close(pipefd[1]);
		if (cmd[0] && path(cmd[0], envp))
		{
			execve(path(cmd[0], envp), cmd, envp);
			free_args(cmd);
		}
		else
			cmd_error(cmd);
	}
}

void	second_child(int *pipefd, int *fd, char **av, char **envp)
{
	pid_t	pid;
	char	**cmd;

	pid = fork();
	if (pid < 0)
		terminate("fork");
	if (pid == 0)
	{
		fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] < 0)
			terminate(av[4]);
		cmd = ft_split(av[3], ' ');
		close(pipefd[1]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		close(fd[1]);
		close(pipefd[0]);
		if (cmd[0] && path(cmd[0], envp))
		{
			execve(path(cmd[0], envp), cmd, envp);
			free_args(cmd);
		}
		cmd_error(cmd);
	}
}
