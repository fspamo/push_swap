/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 01:53:45 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/05 04:00:34 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_the_target(t_node *a, int target_val)
{
	t_node	*holder;
	t_node	*best_pos;

	holder = a;
	best_pos = NULL;
	while (holder)
	{
		if (holder->value > target_val)
			if (best_pos == NULL || holder->value < best_pos->value)
				best_pos = holder;
		holder = holder->next;
	}
	if (best_pos == NULL)
	{
		holder = a;
		best_pos = a;
		while (holder)
		{
			if (holder->value < best_pos->value)
				best_pos = holder;
			holder = holder->next;
		}
	}
	return (best_pos);
}

int	get_position(t_node *stack, t_node *target)
{
	t_node	*holder;
	int		pos;

	holder = stack;
	pos = 0;
	while (holder)
	{
		if (holder == target)
			return (pos);
		holder = holder->next;
		pos++;
	}
	return (-1);
}

void	rotate_to_target(t_node **a, t_node *target)
{
	int	pos;
	int	size;

	pos = get_position(*a, target);
	size = input_counter(*a);
	if (pos <= size / 2)
	{
		while (*a != target)
			ra(a);
	}
	else
	{
		while (*a != target)
			rra(a);
	}
}

void	the_hunter(t_node **a, t_node **b)
{
	t_node	*target;
	int		target_val;

	while (*b)
	{
		target_val = (*b)->value;
		if (!target)
			return;
		target = find_the_target(*a, target_val);
		rotate_to_target(a, target);
		pa(a, b);
	}
}
