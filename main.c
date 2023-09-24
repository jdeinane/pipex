/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:38:01 by jubaldo           #+#    #+#             */
/*   Updated: 2023/09/23 14:54:44 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	status;
	int	fd[2];
	int	pipefd[2];

	errno = 0;
	if (envp[0] == 0)
		envi(envp);
	if (ac == 5)
	{
		if (pipe(pipefd) < 0)
			terminate(NULL);
		first_child(pipefd, fd, av, envp);
		second_child(pipefd, fd, av, envp);
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(-1, &status, 0);
		waitpid(-1, &status, 0);
		return (0);
	}
	else
		args_error();
}
