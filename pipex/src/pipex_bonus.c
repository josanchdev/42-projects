/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:40:00 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/14 12:40:01 by josanch2         ###   ########.fr       */
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

void	here_doc_put_in(char *argv[], int *p_fd)
{
	char	*ret;

	close(p_fd[0]);
	while (1)
	{
		ret = get_next_line(0);
		if (ft_strncmp(ret, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(ret);
			close(p_fd[1]);
			exit(0);
		}
		ft_putstr_fd(ret, p_fd[1]);
		free(ret);
	}
}

void	here_doc(char *argv[])
{
	int		p_fd[2];
	pid_t	pid;

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
		here_doc_put_in(argv, p_fd);
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		close(p_fd[0]);
		wait(NULL);
	}
}

void	do_pipe(char *cmd, char **env)
{
	pid_t	pid;
	int		p_fd[2];

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
	{
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		exec(cmd, env);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
	}
}

int	main(int argc, char *argv[], char **env)
{
	int		i;
	int		fd_in;
	int		fd_out;

	if (argc < 5)
		exit_handler(1);
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc < 6)
			exit_handler(2);
		i = 3;
		fd_out = open_file(argv[argc - 1], 2);
		here_doc(argv);
	}
	else
	{
		i = 2;
		fd_in = open_file(argv[1], 0);
		fd_out = open_file(argv[argc - 1], 1);
		dup2(fd_in, 0);
	}
	while (i < argc - 2)
		do_pipe(argv[i++], env);
	dup2(fd_out, 1);
	exec(argv[argc - 2], env);
}
