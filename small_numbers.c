/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 01:04:42 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/01 00:58:21 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_numbers(t_node	**a)
{
	if ((*a) && (*a)->next && (*a)->value > (*a)->next->value)
		sa(a);
}

void	three_numbers(t_node **a)
{
	int first = (*a)->value;
	int second = (*a)->next->value;
	int third = (*a)->next->next->value;

	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

int	find_min_five(t_node *a)
{
	t_node	*holder;
	int		min;
	int 	recent;
	int 	i;

	holder = a;
	min = holder->value;
	i = 0;
	recent = 0;
	while (holder)
	{
		if (holder->value < min)
		{
			min = holder->value;
			recent = i;
		}
		holder = holder->next;
		i++;
	}
	return (recent);
}

void	push_min_to_b(t_node **a, t_node **b)
{
	int	pos;
	int	i;
	int	size;

	pos = find_min_five(*a);
	size = input_counter(*a);

	if (pos <= size / 2)
	{
		while (pos-- > 0)
		{
			ra(a);
		}
	}
	else 
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a);
	}
	pb(a, b);
}

void	five_or_less(t_node **a, t_node **b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);

	three_numbers(a);
	pa(b, a);
	pa(b, a);
}
