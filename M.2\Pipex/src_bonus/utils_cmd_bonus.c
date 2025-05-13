/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 03:34:44 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/05/06 05:36:38 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	open_pipe_or_exit(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		perror("pipe ko");
		exit(EXIT_FAILURE);
	}
}

int	open_file_or_exit(char *filename, int flags, int mode, char **cmd)
{
	int	fd;

	fd = open(filename, flags, mode);
	if (fd < 0)
	{
		perror(filename);
		free_split(cmd);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	setup_redirection(int in, int out)
{
	dup2(in, STDIN_FILENO);
	close(in);
	dup2(out, STDOUT_FILENO);
	close(out);
}

void	exec_child(t_commande *command, char **cmd)
{
	char	*file;

	ft_check_cmd(cmd);
	file = get_cmd(command, cmd[0]);
	if (!file)
	{
		perror("file");
		free_split(cmd);
		exit(EXIT_FAILURE);
	}
	execve(file, cmd, command->env);
	ft_failure(cmd, file);
}
