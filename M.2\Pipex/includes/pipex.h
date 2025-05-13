/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:32:10 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/05/06 04:11:31 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_commande
{
	int		pipefd[2];
	int		fd_tmp;
	char	**env;
	char	**av;
	char	*infile;
	char	*outfile;
}			t_commande;

char		*ft_strjoin2(char const *s1, char const *s2);
char		*get_cmd(t_commande *command, char *s1);
char		**get_path(t_commande *command);
void		first_cmd(t_commande *command);
void		last_cmd(t_commande *command, int i);
void		middle_cmd(t_commande *command, char *cmd_str);
void		ft_failure(char **cmd, char *file);
void		ft_check_cmd(char **cmd);
void		exec_child(t_commande *command, char **cmd);
void		setup_redirection(int in, int out);
int			open_file_or_exit(char *filename, int flags, int mode, char **cmd);
void		open_pipe_or_exit(int pipefd[2]);

#endif