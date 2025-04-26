/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 01:47:47 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/25 23:26:29 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	count_line(char *av)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_mlx(&game->mlx);
	if (game->data.map)
		free_map(game->data.map);
	if (game->data.map_copy)
		free_map(game->data.map_copy);
	exit(0);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, -1, 0);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}

int	game_loop(void *param)
{
	(void)param;
	return (0);
}

// void	print_map(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i])
// 	{
// 		printf("{%i}{%s}\n", i, map[i]);
// 		i++;
// 	}
// }
