/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:25:59 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/25 16:59:32 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_side(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	while (data->map[i])
	{
		len = ft_strlen(data->map[0]);
		if (data->map[i][0] != '1')
			return (1);
		if (data->map[i][len - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_top_bottom(t_data *data)
{
	int	i;
	int	last;

	i = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i] != '1' && data->map[0][i] != '\n')
			return (1);
		i++;
	}
	last = 0;
	i = 0;
	while (data->map[last])
		last++;
	last--;
	i = 0;
	while (data->map[last][i])
	{
		if (data->map[last][i] != '1' && data->map[0][i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_valid_char(t_data *data, int *p_count, int *c_count, int *e_count)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				(*e_count)++;
			else if (data->map[i][j] == 'C')
				(*c_count)++;
			else if (data->map[i][j] == 'P')
				(*p_count)++;
			else if (data->map[i][j] != '0' && data->map[i][j] != '1'
				&& data->map[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_count_char(int p_count, int e_count, int c_count)
{
	if (p_count != 1)
		return (1);
	else if (e_count != 1)
		return (1);
	else if (c_count < 1)
		return (1);
	return (0);
}

int	copy_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		i++;
	data->map_copy = malloc(sizeof(char *) * (i + 1));
	if (!data->map_copy)
		return (write(2, "error:\nallocation failed", 25), 1);
	i = 0;
	while (data->map[i])
	{
		data->map_copy[i] = ft_strdup(data->map[i]);
		if (!data->map_copy[i])
		{
			write(2, "error:\nallocation failed", 25);
			free_map(data->map_copy);
			return (1);
		}
		i++;
	}
	data->map_copy[i] = NULL;
	return (0);
}
