/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:39:50 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/14 12:39:53 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd || !s_cmd[0])
		exec_error(cmd, s_cmd, NULL);
	path = get_path(cmd, env);
	if (!path)
		exec_error(cmd, s_cmd, NULL);
	if (execve(path, s_cmd, env) == -1)
		exec_error(cmd, s_cmd, path);
}

void	child(char *argv[], int *p_fd, char **env)
{
	int		fd;

	fd = open_file(argv[1], 0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	exec(argv[2], env);
}

void	parent(char *argv[], int *p_fd, char **env)
{
	int		fd;

	fd = open_file(argv[4], 1);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	exec(argv[3], env);
}

int	main(int argc, char *argv[], char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (argc != 5)
		exit_handler(1);
	if (pipe(p_fd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (!pid)
		child(argv, p_fd, env);
	parent(argv, p_fd, env);
}
