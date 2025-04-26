/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:19:02 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/18 21:36:42 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		result = result * 10 + (str[i] - '0');
		if ((result * sign) < INT_MIN || (result * sign) > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

int	valid_number(const char *str, t_node *a)
{
	if (!str || !str[0] || check_number(str) || check_double(a))
	{
		ft_printf("%s\n", str);
		print_error();
		return (1);
	}
	return (0);
}

int	parse_mult_args(t_node **a, char **argv)
{
	int	i;
	int	nbr;

	i = 1;
	while (argv[i])
	{
		if (check_number(argv[i]))
			return (1);
		nbr = ft_atoi(argv[i]);
		ft_lstadd_back(a, nbr);
		i++;
	}
	return (0);
}

int	if_only_spaces(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		else
			return (0);
	}
	return (1);
}

int	parse_two_args(t_node **a, char **argv)
{
	char	**split;
	int		i;
	int		nbr;

	split = ft_split(argv[1], ' ');
	if (!split)
		return (1);
	i = 0;
	if (argv[1][i] == '\0' || if_only_spaces(argv))
		print_error();
	while (split[i])
	{
		if (check_number(split[i]))
		{
			free_split(split);
			return (1);
		}
		nbr = ft_atoi(split[i]);
		ft_lstadd_back(a, nbr);
		i++;
	}
	free_split(split);
	return (0);
}
