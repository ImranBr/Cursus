/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:44:11 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/18 21:31:19 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
}

t_node	*create_node(int nbr)
{
	t_node	*entier;

	entier = malloc(sizeof(t_node));
	if (entier == NULL)
		return (NULL);
	entier->value = nbr;
	entier->next = NULL;
	return (entier);
}

void	free_int_tab(int *tab)
{
	free(tab);
}

int	is_sorted(t_node *test)
{
	if (!test)
		return (1);
	while (test->next)
	{
		if (test->value > test->next->value)
		{
			return (0);
		}
		test = test->next;
	}
	return (1);
}

void	ft_lstadd_back_node(t_node **last, t_node *new)
{
	if (!new || !last)
		return ;
	if (*last)
	{
		ft_lstlast(*last)->next = new;
	}
	else
		*last = new;
}
