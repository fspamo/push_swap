/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:44:20 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/22 19:59:39 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

// void	print_stack_b(t_node *b)
// {
// 	printf("B stack:\n");
// 	t_node	*to_print = b;
// 	while (to_print)
// 	{
// 		printf("value: %d\n", to_print->value);
// 		to_print = to_print->next;
// 	}
// }

void	chunk_sorting(t_node **a, t_node **b)
{
	int	size;
	int	chunk;
	int	i;

	size = input_counter(*a);
	chunk = ft_sqrt(size);
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index <= i + chunk)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

int	find_max_index(t_node *b)
{
	t_node	*holder;
	int		highest;

	if (!b)
		return (-1);
	holder = b->next;
	highest = b->index;
	while (holder)
	{
		if (holder->index > highest)
			highest = holder->index;
		holder = holder->next;
	}
	return (highest); 
}
