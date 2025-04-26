/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:32:22 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/26 00:01:51 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->x = j;
				data->y = i;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	fill(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || data->map_copy[y] == NULL
		|| data->map_copy[y][x] == '\0')
		return ;
	else if (data->map_copy[y][x] == '1')
		return ;
	else if (data->map_copy[y][x] == 'R')
		return ;
	data->map_copy[y][x] = 'R';
	fill(data, x - 1, y);
	fill(data, x + 1, y);
	fill(data, x, y - 1);
	fill(data, x, y + 1);
}

void	flood_fill(t_data *data)
{
	find_player(data);
	fill(data, data->x, data->y);
}

int	complet_to_flood(t_data *data, int *i, int *j, int *exit_found)
{
	if (data->map_copy[*i][*j] == 'C')
	{
		data->x = *j;
		data->y = *i;
		return (1);
	}
	if (data->map_copy[*i][*j] == 'E')
		return (1);
	if (data->map_copy[*i][*j] == 'R' && data->map[*i][*j] == 'E')
		*exit_found = 1;
	*j = *j + 1;
	return (0);
}

int	check_after_flood(t_data *data)
{
	int	i;
	int	j;
	int	exit_found;

	i = 0;
	while (data->map_copy[i])
	{
		j = 0;
		while (data->map_copy[i][j])
		{
			if (complet_to_flood(data, &i, &j, &exit_found))
				return (1);
		}
		i++;
	}
	if (!exit_found)
		return (1);
	return (0);
}
