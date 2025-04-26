/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:45:14 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/18 20:34:30 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_first(t_node *a)
{
	int		min_pos;
	int		min_val;
	int		i;
	t_node	*current;

	if (!a)
		return (0);
	min_pos = 1;
	min_val = a->value;
	i = 1;
	current = a->next;
	while (current)
	{
		i++;
		if (current->value < min_val)
		{
			min_val = current->value;
			min_pos = i;
		}
		current = current->next;
	}
	return (min_pos);
}

void	push_min_from_a_to_b(t_node **a, t_node **b, int min_pos)
{
	int	size;

	if (!a || !(*a))
		return ;
	size = ft_lstsize(*a);
	if (min_pos > size / 2)
	{
		while (min_pos++ <= size)
			reverse_rotate_a(a);
	}
	else
	{
		while (min_pos-- > 1)
			rotate_a(a);
	}
	push_b(b, a);
}

void	sort_five(t_node **a, t_node **b)
{
	push_min_from_a_to_b(a, b, min_first(*a));
	push_min_from_a_to_b(a, b, min_first(*a));
	take_three(a);
	push_a(a, b);
	push_a(a, b);
}
