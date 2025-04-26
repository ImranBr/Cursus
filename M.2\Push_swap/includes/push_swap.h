/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:50:45 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/16 17:05:27 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		check_number(const char *str);
int		valid_number(const char *str, t_node *a);
int		is_sorted(t_node *test);
int		min_first(t_node *a);
int		max_first(t_node *a);
int		check_double(t_node *a);
int		ft_median(t_node *a, int size);
int		*create_tab(t_node *a, int size);
int		parse_mult_args(t_node **a, char **argv);
int		parse_two_args(t_node **a, char **argv);
t_node	*free_list(t_node *a);
void	ft_lstadd_back(t_node **last, int nbr);
void	ft_lstadd_back_node(t_node **last, t_node *new);
void	print_error(void);
void	swap_a(t_node **a);
void	swap_b(t_node **b);
void	push_a(t_node **a, t_node **b);
void	push_b(t_node **b, t_node **a);
void	rotate_a(t_node **a);
void	rotate_b(t_node **b);
void	reverse_rotate_a(t_node **a);
void	reverse_rotate_b(t_node **b);
void	free_int_tab(int *tab);
void	sort_three(t_node **a, int top, int middle, int bottom);
void	take_three(t_node **a);
void	push_min_from_a_to_b(t_node **a, t_node **b, int min_pos);
void	sort_five(t_node **a, t_node **b);
void	print_stack_a(t_node *stack);
void	print_stack_b(t_node *stack);
void	ft_sort_int_tab(int *tab, int size);
void	ft_push_median(t_node **a, t_node **b, int size);
void	algo_number(t_node **a, t_node **b);
void	push_max_from_b_to_a(t_node **a, t_node **b, int max_pos);
void	free_split(char **split);

#endif