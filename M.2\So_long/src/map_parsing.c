/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 23:42:41 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/25 22:49:06 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(t_data *data)
{
	int	i;
	int	first_line_len;
	int	current_len;

	if (!data->map || !data->map[0])
		return (1);
	i = 0;
	first_line_len = ft_strlen(data->map[i]);
	while (data->map[i] != NULL)
	{
		current_len = ft_strlen(data->map[i]);
		if (current_len != first_line_len)
			return (1);
		i++;
	}
	return (0);
}

int	is_outline_1(t_data *data)
{
	if (check_top_bottom(data))
		return (1);
	else if (check_side(data))
		return (1);
	return (0);
}

int	check_char(t_data *data)
{
	int	p_count;
	int	c_count;
	int	e_count;

	p_count = 0;
	c_count = 0;
	e_count = 0;
	if (check_valid_char(data, &p_count, &c_count, &e_count))
		return (1);
	if (check_count_char(p_count, e_count, c_count))
		return (1);
	return (0);
}
