/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:39:36 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/18 20:33:40 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	while (size > 1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		size--;
	}
}

int	*create_tab(t_node *a, int size)
{
	int	i;
	int	*tab;

	tab = malloc(sizeof(int) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (a && i < size)
	{
		tab[i] = a->value;
		a = a->next;
		i++;
	}
	tab[size] = '\0';
	return (tab);
}

int	max_first(t_node *a)
{
	int		i;
	int		max_pos;
	int		max_value;
	t_node	*current_node;

	if (!a)
		return (0);
	i = 1;
	max_pos = 1;
	max_value = a->value;
	current_node = a->next;
	while (current_node)
	{
		i++;
		if (current_node->value > max_value)
		{
			max_value = current_node->value;
			max_pos = i;
		}
		current_node = current_node->next;
	}
	return (max_pos);
}

void	push_max_from_b_to_a(t_node **a, t_node **b, int max_pos)
{
	int	size;

	if (!b || !(*b))
		return ;
	size = ft_lstsize(*b);
	if (max_pos > size / 2)
	{
		while (max_pos++ <= size)
			reverse_rotate_b(b);
	}
	else
	{
		while (max_pos-- > 1)
			rotate_b(b);
	}
	push_a(a, b);
}
