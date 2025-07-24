/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:50:06 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/19 12:50:08 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_absolute_path(char *cmd)
{
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_strdup(cmd));
	}
	return (NULL);
}

char	*search_in_path(char *cmd, char **allpath)
{
	int		i;
	char	*exec;
	char	*path_part;

	i = 0;
	while (allpath && allpath[i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
		i++;
	}
	return (NULL);
}

char	*find_command_path(char *cmd, char **env)
{
	char	**allpath;
	char	*path_env;
	char	*result;

	if (!cmd || !*cmd)
		return (NULL);
	result = check_absolute_path(cmd);
	if (result)
		return (result);
	path_env = my_getenv("PATH", env);
	if (!path_env)
		return (NULL);
	allpath = ft_split(path_env, ':');
	if (!allpath)
		return (NULL);
	result = search_in_path(cmd, allpath);
	ft_free_tab(allpath);
	return (result);
}

void	exec_error(char *cmd, char **s_cmd, char *path)
{
	ft_putstr_fd("pipex: command not found: ", 2);
	if (s_cmd && s_cmd[0])
		ft_putendl_fd(s_cmd[0], 2);
	else
		ft_putendl_fd(cmd, 2);
	if (s_cmd)
		ft_free_tab(s_cmd);
	if (path)
		free(path);
	exit(127);
}
