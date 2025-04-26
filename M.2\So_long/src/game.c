/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:06:01 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/25 22:48:55 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game, char *map_path)
{
	ft_memset(game, 0, sizeof(t_game));
	if (init(&game->data, map_path) != 0)
		return (write(2, "Error:\nmap initialization failed", 33), 1);
	if (parse_map(&game->data))
		return (free_map(game->data.map), 1);
	game->moves = 0;
	game->collectibles = count_collectibles(&game->data);
	if (init_mlx(&game->mlx, &game->data) != 0)
		return (free_map(game->data.map), free_map(game->data.map_copy), 1);
	return (0);
}

int	count_collectibles(t_data *data)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	handle_exit_logic(t_game *game, char dest, int *on_exit)
{
	if (dest == 'E' && game->collectibles == 0)
	{
		ft_printf("Congratulations! You won in %d moves.\n", game->moves + 1);
		close_window(game);
		return (0);
	}
	if (dest == 'C')
		game->collectibles--;
	if (*on_exit)
	{
		game->data.map[game->data.y][game->data.x] = 'E';
		*on_exit = 0;
	}
	else
		game->data.map[game->data.y][game->data.x] = '0';
	if (dest == 'E')
		*on_exit = 1;
	return (1);
}

void	handle_player_move_logic(t_game *game, int new_x, int new_y)
{
	char		dest;
	static int	on_exit = 0;

	if (new_x < 0 || new_y < 0 || !game->data.map[new_y]
		|| !game->data.map[new_y][new_x])
		return ;
	dest = game->data.map[new_y][new_x];
	if (dest == '1')
		return ;
	if (!handle_exit_logic(game, dest, &on_exit))
		return ;
	game->data.map[new_y][new_x] = 'P';
	game->data.x = new_x;
	game->data.y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(&game->mlx, &game->data, &game->render);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	find_player(&game->data);
	new_x = game->data.x + dx;
	new_y = game->data.y + dy;
	handle_player_move_logic(game, new_x, new_y);
}
