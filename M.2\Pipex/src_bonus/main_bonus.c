/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:58:04 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/05/06 05:36:09 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_commande	init(int ac, char **av, char **env)
{
	t_commande	command;

	command.env = env;
	command.av = av;
	command.fd_tmp = -1;
	command.infile = av[1];
	command.outfile = av[ac - 1];
	return (command);
}

void	cleanup_and_exit(t_commande *command, int status)
{
	if (command->pipefd[0] != -1)
		close(command->pipefd[0]);
	if (command->pipefd[1] != -1)
		close(command->pipefd[1]);
	if (command->fd_tmp != -1)
		close(command->fd_tmp);
	exit(status);
}

int	main(int ac, char **av, char **env)
{
	t_commande	command;
	int			i;

	if (ac < 5)
		return (ft_putstr_fd("Error: number of arguments", 2), EXIT_FAILURE);
	command = init(ac, av, env);
	i = 2;
	while (i)
	{
		if (i == 2)
			first_cmd(&command);
		else if (i == (ac - 2))
		{
			last_cmd(&command, i);
			break ;
		}
		else
			middle_cmd(&command, command.av[i]);
		i++;
	}
	cleanup_and_exit(&command, 0);
	return (0);
}
