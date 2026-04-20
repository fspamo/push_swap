/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:30:53 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/04/20 13:26:13 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	normalize(t_node *a)
{
	t_node	*i;
	t_node	*j;
	int		rank;

	i = a;
	while (i)
	{
		rank = 0;
		j = a;
		while (j)
		{
			if (j->value < i->value)
				rank++;
			j = j->next;
		}
		i->index = rank;
		i = i->next;
	}
}

static int	count_bits(int max)
{
	int	bits;

	bits = 0;
	while ((1 << bits) <= max)
		bits++;
	return (bits);
}

static void	radix_pass(t_node **a, t_node **b, t_ops *ops, int bit)
{
	int	j;
	int	size;

	size = input_counter(*a);
	j = 0;
	while (j < size)
	{
		if (((*a)->index >> bit) & 1)
			ra(a, ops);
		else
			pb(a, b, ops);
		j++;
	}
	while (*b)
		pa(a, b, ops);
}

void	radix(t_node **a, t_node **b, t_ops *ops)
{
	int	max_bits;
	int	i;

	normalize(*a);
	max_bits = count_bits(input_counter(*a) - 1);
	i = 0;
	while (i < max_bits)
		radix_pass(a, b, ops, i++);
}
