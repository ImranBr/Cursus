/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:53:41 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/25 23:21:16 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init(t_data *data, char *av)
{
	int	i;

	i = 0;
	ft_memset(data, 0, sizeof(t_data));
	data->nbline = count_line(av);
	if (!data->nbline)
		return (1);
	data->fd = open(av, O_RDONLY);
	if (data->fd < 0)
		return (1);
	data->map = malloc((data->nbline + 1) * sizeof(char *));
	if (!data->map)
		return (close(data->fd), 1);
	while (1)
	{
		data->line = get_next_line(data->fd);
		if (!data->line)
			break ;
		if (data->line[ft_strlen(data->line) - 1] == '\n')
			data->line[ft_strlen(data->line) - 1] = '\0';
		data->map[i] = ft_strdup(data->line);
		free(data->line);
		i++;
	}
	return (data->map[i] = NULL, close(data->fd), 0);
}

int	parse_map(t_data *data)
{
	if (is_rectangular(data))
		return (write(2, "error\nwith the map", 19), 1);
	else if (is_outline_1(data))
		return (write(2, "error\nwith the outline", 23), 1);
	else if (check_char(data))
		return (write(2, "error\nwith the char", 20), 1);
	else if (copy_map(data))
		return (write(2, "error\ncopying the map", 22), 1);
	else if (find_player(data))
		return (write(2, "error\nfinding 'P'", 18), 1);
	flood_fill(data);
	if (check_after_flood(data))
		return (write(2, "error\npath with 'C' or 'E'", 27), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (write(2, "Error:\nusage: ./so_long <map.ber>", 34), 1);
	if (ft_strlen(av[1]) < 4 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber",
			4) != 0)
		return (write(2, "Error:\nmap file must have .ber extension", 41), 1);
	if (init_game(&game, av[1]) != 0)
		return (1);
	render_map(&game.mlx, &game.data, &game.render);
	mlx_key_hook(game.mlx.window, key_hook, &game);
	mlx_hook(game.mlx.window, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx.mlx_ptr);
	return (0);
}
