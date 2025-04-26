/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:43:54 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/15 02:04:07 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;

	if (!*stack || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	ft_lstadd_back_node(stack, first);
}

void	rotate_a(t_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}
