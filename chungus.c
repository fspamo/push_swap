/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chungus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:44:20 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/04/16 00:33:19 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_position(t_node *b, int highest)
{
	t_node	*holder;
	int		position;

	holder = b;
	position = 0;
	while (holder)
	{
		if (holder->index == highest)
			return (position);
		position++;
		holder = holder->next;
	}
	return (-1);
}

void	chunker(t_node **a, t_node **b, t_ops *ops)
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
			pb(a, b, ops);
			rb(b, ops);
			i++;
		}
		else if ((*a)->index <= i + chunk)
		{
			pb(a, b, ops);
			i++;
		}
		else
			ra(a, ops);
	}
}

static void	move_max_to_top(t_node **b, t_ops *ops)
{
	int	max;
	int	pos;
	int	size;
	int	steps;

	max = find_max_index(*b);
	pos = find_position(*b, max);
	size = input_counter(*b);
	steps = size - pos;
	if (pos <= size / 2)
		while (pos-- > 0)
			rb(b, ops);
	else
	{
		steps = size - pos;
		while (steps-- > 0)
			rrb(b, ops);
	}
}

void	chunk_sorting(t_node **a, t_node **b, t_ops *ops)
{
	chunk_core_indexer(*a);
	chunker(a, b, ops);
	while (*b)
	{
		move_max_to_top(b, ops);
		pa(a, b, ops);
	}
}
