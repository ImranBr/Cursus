/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:53:35 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/17 02:16:30 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	choose_algo(t_node *a, t_node *b)
{
	int	size;

	size = ft_lstsize(a);
	if (size == 2)
	{
		if (is_sorted(a))
			return (0);
		else
			swap_a(&a);
	}
	else if (size == 3)
		take_three(&a);
	else if (size == 5)
		sort_five(&a, &b);
	else
		ft_push_median(&a, &b, size);
	free_list(a);
	free_list(b);
	return (0);
}

static int	choose_parse(t_node **a, int argc, char **argv)
{
	if (argc == 2)
	{
		if (parse_two_args(a, argv) == 1)
		{
			free_list(*a);
			print_error();
			return (1);
		}
	}
	else
	{
		if (parse_mult_args(a, argv) == 1)
		{
			free_list(*a);
			print_error();
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
	{
		print_error();
		return (0);
	}
	if (choose_parse(&a, argc, argv) == 1)
		return (0);
	if (check_double(a))
		return (print_error(), free_list(a), 1);
	if (is_sorted(a))
		return (free_list(a), 0);
	choose_algo(a, b);
	return (0);
}

int	check_double(t_node *a)
{
	t_node	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}
