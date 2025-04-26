/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:48:49 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/18 20:36:05 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **dest, t_node **src)
{
	t_node	*first;

	if (!src || !*src)
		return ;
	first = *src;
	*src = (*src)->next;
	first->next = *dest;
	*dest = first;
}

void	push_a(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	push_b(t_node **b, t_node **a)
{
	push(b, a);
	ft_printf("pb\n");
}
