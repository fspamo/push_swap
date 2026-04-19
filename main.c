/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melipola <melipola@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:02:33 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/04/19 22:59:55 by cbozkurt         ###   ########.fr       */
/*                                                                            */
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

int	parse_flags(int argc, char **argv, int *strat, int *bench)
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

static void	free_numbers(char **numbers, int i)
{
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
}

int	re_arange(int argc, char **argv, t_node **a)
{
	char	**numbers;
	char	*joined;
	int		i;

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
			return (free_numbers(numbers, i), print_error(), 1);
		add_back(a, new_lst(ft_so_long_atoi(numbers[i])));
		free(numbers[i++]);
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

char	*adp_printer(float disorder)
{
	char	*metric;

	if (disorder < 0.2)
		metric = ft_strdup("Adaptive / O(n²)");
	else if (0.2 <= disorder && disorder < 0.5)
		metric = ft_strdup("Adaptive / O(n√n)");
	else if (disorder >= 0.5)
		metric = ft_strdup("Adaptive / O(n log n)");
	return (metric);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_ops	ops;
	t_vars	v;

	a = NULL;
	ops = (t_ops){0};
	v = (t_vars){.bench = 0, .strat = 3, .offset = 0, .disorder = 0};
	if (argc < 2)
		return (0);
	v.offset = parse_flags(argc, argv, &v.strat, &v.bench);
	if (argc <= v.offset)
		print_error();
	if (re_arange(argc - v.offset, argv + v.offset, &a))
		return (1);
	v.disorder = compute_disorder(a);
	default_controls(a, &ops, v.bench);
	navigation(&a, v.strat, &ops);
	print_stack(a);
	if (v.bench == 1)
		benchmarking(&ops, v.strat, v.disorder);
	return (0);
}
