/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:29:05 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/18 20:35:34 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_median(t_node *a, int size)
{
	int	*tab;
	int	med;

	if (!a || size <= 0)
		return (0);
	tab = create_tab(a, size);
	if (!tab)
		return (0);
	ft_sort_int_tab(tab, size);
	if (size >= 151)
		med = tab[size / 15];
	else if (size >= 50)
		med = tab[size / 7];
	else if (size < 50)
		med = tab[size / 5];
	free_int_tab(tab);
	return (med);
}

void	ft_push_median(t_node **a, t_node **b, int size)
{
	int	med;

	while (ft_lstsize(*a) > 3)
	{
		size = ft_lstsize(*a);
		while (size > 3)
		{
			med = ft_median(*a, size);
			if ((*a)->value <= med)
			{
				push_b(b, a);
				size--;
			}
			else
				rotate_a(a);
		}
	}
	take_three(a);
	algo_number(a, b);
}

void	algo_number(t_node **a, t_node **b)
{
	while (*b)
		push_max_from_b_to_a(a, b, max_first(*b));
}
