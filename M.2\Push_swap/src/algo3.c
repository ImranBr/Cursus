/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:36:38 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/18 20:33:14 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **a, int top, int middle, int bottom)
{
	if (top < middle && top < bottom && middle > bottom)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (top > middle && top > bottom && middle > bottom)
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
	else if (top > middle && top < bottom && middle < bottom)
		swap_a(a);
	else if (top < middle && top > bottom && middle > bottom)
		reverse_rotate_a(a);
	else if (top > middle && top > bottom && middle < bottom)
		rotate_a(a);
	else if (top < middle && middle < bottom)
		return ;
}

void	take_three(t_node **a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*a)->value;
	middle = (*a)->next->value;
	bottom = (*a)->next->next->value;
	sort_three(a, top, middle, bottom);
}
