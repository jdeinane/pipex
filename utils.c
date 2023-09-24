/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:36:50 by jubaldo           #+#    #+#             */
/*   Updated: 2023/09/18 16:20:07 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	char	**directory;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	directory = ft_split(envp[i] + 5, ':');
	return (directory);
}

char	*path(char *cmd, char **envp)
{
	char	**directory;
	char	*path;
	char	*separate_path;
	int		i;

	i = 0;
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (cmd);
	directory = get_path(envp);
	i = -1;
	while (directory[++i])
	{
		separate_path = ft_strjoin(directory[i], "/");
		path = ft_strjoin(separate_path, cmd);
		free(separate_path);
		if (!access(path, F_OK))
		{
			free_args(directory);
			return (path);
		}
		free(path);
	}
	free_args(directory);
	return (0);
}

void	free_args(char **args)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (args[len])
		len++;
	while (i < len)
		free(args[i++]);
	free(args);
}
