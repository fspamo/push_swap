/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:02:33 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/31 14:10:38 by cbozkurt         ###   ########.fr       */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	print_stack(t_node *a)
{
	printf("A stack:\n");
	t_node	*to_print = a;
	while (to_print)
	{
		printf("value: %d\n", to_print->value);
		to_print = to_print->next;
	}
}

int	parse_flags(int argc, char **argv, char *strat, int *bench)
{
	int	offset;

	offset = 1;
	while (offset < argc && argv[offset][0] == '-' && argv[offset][1] == '-')
	{
		if (ft_strcmp(argv[offset], "--bench") == 0)
			*bench = 1;
		else
			*strat = strategy_selector(argv[offset]);
		offset++;
	}
	return (offset);
}

int	re_arange(int argc, char **argv, t_node **a)
{
	char    *joined;
	char    **numbers;
	int     i;

	joined = join_args(argc, argv);
	if (!joined)
		return (1);
	numbers = ft_split(joined, ' ');
	free(joined);
	if (!numbers)
		return (1);
	i = 0;
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i]))
		{
			while (numbers[i])
				free(numbers[i++]);
			free(numbers);
			print_error();
		}
		int value = ft_so_long_atoi(numbers[i]);
		add_back(a, new_lst(value));
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (0);
}

int	strategy_selector(char *strat)
{
	if (ft_strcmp(strat, "--simple") == 0)
		return (0);
	else if (ft_strcmp(strat, "--medium") == 0)
		return (1);
	else if (ft_strcmp(strat, "--complex") == 0)
		return (2);
	else if (ft_strcmp(strat, "--adaptive") == 0)
		return (3);
	else
		return (3);
}

int main(int argc, char **argv)
{
	t_node  *a;
	t_node  *b;
	int		strat;
	int     offset;
	int		bench;
	t_ops	ops;

	a = NULL;
	b = NULL;
	(void)b;
	ops = (t_ops){0};
	bench = 0;
	offset = parse_flags(argc, argv, &strat, &bench);
	if (argc < 2)
		print_error();
	if (argc <= offset)
		print_error();
	if (re_arange(argc - offset, argv + offset, &a))
		return (1);
	default_controls(a);
	navigation(&a, strat, &ops);
	print_stack(a);
	if (bench == 1)
		benchmarking(&ops, strat, disorder);
	return (0);
}
