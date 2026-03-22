/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:37:25 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/22 14:52:29 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_node *a)
{
	int		highest;
	t_node	*holder;

	holder = a;
	highest = holder->value;
	while (holder)
	{
		if (highest < holder->value)
			highest = holder->value;
		holder = holder->next;
	}
	return (highest);
}

int count_bits(int max)
{
    int bits;

    bits = 0;
    while ((1 << bits) <= max)
        bits++;
    return (bits);
}

void	radix(t_node **a, t_node **b)
{
	int	size;
	int	highest;	
	int	max_bits;
	int	i;
	int	j;

	size = input_counter(*a);
	highest = find_max(*a);
	max_bits = count_bits(highest);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->value >> i) & 1)
				ra(a);
			else
				pb(a,b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
