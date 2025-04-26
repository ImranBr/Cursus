/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:09:52 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/14 00:01:42 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*before_last;

	if (!*stack || (*stack)->next == NULL)
		return ;
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	reverse_rotate_a(t_node **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_node **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}
