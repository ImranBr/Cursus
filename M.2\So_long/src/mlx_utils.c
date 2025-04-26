/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:05:30 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/25 23:23:03 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mlx(t_mlx *mlx)
{
	int	i;

	if (!mlx)
		return ;
	if (mlx->textures)
	{
		i = 0;
		while (i < 5)
		{
			if (mlx->textures[i])
				mlx_destroy_image(mlx->mlx_ptr, mlx->textures[i]);
			i++;
		}
		free(mlx->textures);
	}
	if (mlx->window)
		mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
}

int	init_mlx(t_mlx *mlx, t_data *data)
{
	ft_memset(mlx, 0, sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (write(2, "Error:\n mlx initialization failed", 34), 1);
	mlx->map_width = ft_strlen(data->map[0]);
	mlx->map_height = 0;
	while (data->map[mlx->map_height])
		mlx->map_height++;
	if (mlx->map_height > 16 || mlx->map_width > 31)
		return (free_mlx(mlx), write(2, "Error:\nMap too big", 19), 1);
	mlx->tile_size = 64;
	mlx->width = mlx->map_width * mlx->tile_size;
	mlx->height = mlx->map_height * mlx->tile_size;
	if (mlx->width > 1920)
		mlx->width = 1920;
	if (mlx->height > 1080)
		mlx->height = 1080;
	mlx->window = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height,
			"so_long");
	if (!mlx->window)
		return (free_mlx(mlx), write(2, "Error:\nwindow creation", 30), 1);
	if (load_textures(mlx) != 0)
		return (free_mlx(mlx), write(2, "Error:\ntexture loading", 30), 1);
	return (0);
}

int	load_textures(t_mlx *mlx)
{
	int	img_width;
	int	img_height;
	int	i;

	mlx->textures = malloc(5 * sizeof(void *));
	if (!mlx->textures)
		return (1);
	ft_memset(mlx->textures, 0, 5 * sizeof(void *));
	mlx->textures[0] = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/floor.xpm",
			&img_width, &img_height);
	mlx->textures[1] = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/wall.xpm",
			&img_width, &img_height);
	mlx->textures[2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"textures/collect.xpm", &img_width, &img_height);
	mlx->textures[3] = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/exit.xpm",
			&img_width, &img_height);
	mlx->textures[4] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"textures/player.xpm", &img_width, &img_height);
	i = -1;
	while (++i < 5)
		if (!mlx->textures[i])
			return (1);
	return (0);
}

void	render_map_line(t_mlx *mlx, t_data *data, t_render *render)
{
	render->x = 0;
	while (data->map[render->y][render->x])
	{
		render->pixel_x = render->x * mlx->tile_size;
		render->pixel_y = render->y * mlx->tile_size;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->textures[0],
			render->pixel_x, render->pixel_y);
		if (data->map[render->y][render->x] == '1')
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->textures[1],
				render->pixel_x, render->pixel_y);
		else if (data->map[render->y][render->x] == 'C')
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->textures[2],
				render->pixel_x, render->pixel_y);
		else if (data->map[render->y][render->x] == 'E')
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->textures[3],
				render->pixel_x, render->pixel_y);
		else if (data->map[render->y][render->x] == 'P')
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->textures[4],
				render->pixel_x, render->pixel_y);
		render->x++;
	}
}

void	render_map(t_mlx *mlx, t_data *data, t_render *render)
{
	render->y = 0;
	while (data->map[render->y])
	{
		render_map_line(mlx, data, render);
		render->y++;
	}
}
