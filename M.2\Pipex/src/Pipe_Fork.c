/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipe_Fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:36:30 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/05/06 04:10:49 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_file_error(t_commande *command, char **cmd)
{
	perror(command->infile);
	free_split(cmd);
	close(command->pipefd[0]);
	close(command->pipefd[1]);
	exit(EXIT_FAILURE);
}

void	first_cmd(t_commande *command)
{
	int		fd_infile;
	char	**cmd;
	pid_t	child;

	open_pipe_or_exit(command->pipefd);
	cmd = ft_split(command->av[2], ' ');
	fd_infile = open(command->infile, O_RDONLY);
	if (fd_infile < 0)
		handle_file_error(command, cmd);
	child = fork();
	if (child == 0)
	{
		setup_redirection(fd_infile, command->pipefd[1]);
		close(command->pipefd[0]);
		exec_child(command, cmd);
	}
	close(fd_infile);
	close(command->pipefd[1]);
	free_split(cmd);
	command->fd_tmp = command->pipefd[0];
	command->pipefd[0] = -1;
	command->pipefd[1] = -1;
}

void	middle_cmd(t_commande *command, char *cmd_str)
{
	char	**cmd;
	pid_t	child;

	open_pipe_or_exit(command->pipefd);
	cmd = ft_split(cmd_str, ' ');
	child = fork();
	if (child == 0)
	{
		setup_redirection(command->fd_tmp, command->pipefd[1]);
		close(command->pipefd[0]);
		exec_child(command, cmd);
	}
	close(command->pipefd[1]);
	close(command->fd_tmp);
	free_split(cmd);
	command->fd_tmp = command->pipefd[0];
	command->pipefd[0] = -1;
	command->pipefd[1] = -1;
}

void	last_cmd(t_commande *command, int i)
{
	int		fd_outfile;
	char	**cmd;
	pid_t	child;

	cmd = ft_split(command->av[i], ' ');
	fd_outfile = open_file_or_exit(command->outfile,
			O_WRONLY | O_CREAT | O_TRUNC, 0644, cmd);
	child = fork();
	if (child == 0)
	{
		setup_redirection(command->fd_tmp, fd_outfile);
		exec_child(command, cmd);
	}
	free_split(cmd);
	close(fd_outfile);
	close(command->fd_tmp);
	while (waitpid(-1, NULL, 0) != -1)
		;
}
