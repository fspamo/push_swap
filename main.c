/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:02:33 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/26 17:51:36 by cbozkurt         ###   ########.fr       */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <string.h>
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
		int value = ft_so_long_atoi(numbers[i]);
		add_back(a, new_lst(value));
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (0);
}

int	startegy_selector(char *strat)
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
	{
		print_error();
		return (-1);
	}

}

int main(int argc, char **argv)
{
	t_node  *a;
	t_node  *b;

	a = NULL;
	b = NULL;
	(void)b;
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (re_arange(argc, argv, &a))
		return (1);
	default_controls(a);
	navigation(&a, startegy_selector(argv[1]));
	print_stack(a);
	return (0);
}
