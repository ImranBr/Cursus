/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 00:28:17 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/14 00:01:27 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node *test)
{
	int	tmp;

	if (ft_lstsize(test) < 2)
		return ;
	tmp = test->value;
	test->value = test->next->value;
	test->next->value = tmp;
}

void	swap_a(t_node **a)
{
	swap(*a);
	ft_printf("sa\n");
}

void	swap_b(t_node **b)
{
	swap(*b);
	ft_printf("sb\n");
}
