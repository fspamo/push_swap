/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:02:33 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/25 00:51:18 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

t_node *new_lst(int value)
{
	t_node *node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

// this shouldn't be pushed in the project

void	print_stack(t_node *stack)
{
	t_node	*to_print = stack;
	while (to_print)
	{
		printf("%d \n", to_print->value);
		to_print = to_print->next;
	}
}

int	main(int argc, char **argv)
{
	t_node *a;
	t_node *b;
	int i;

	a = NULL;
	b = NULL;
	(void)b;
	if (argc < 2)
		return (0);
	
	i = 1;
	while (i < argc)
	{
		int value = ft_atoi(argv[i]);
		add_back(&a, new_lst(value));
		i++;
	}
	is_sorted(a);
	print_stack(a);
	return (0);
}
