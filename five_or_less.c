/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 02:11:04 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/04/20 13:23:48 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min_to_b(t_node **a, t_node **b, t_ops *ops)
{
	t_node	*temp;
	int		min;
	int		pos;
	int		i;

	temp = *a;
	min = temp->value;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	temp = *a;
	pos = 0;
	i = 0;
	while (temp->value != min)
	{
		pos++;
		temp = temp->next;
	}
	while (i++ < pos)
		ra(a, ops);
	pb(a, b, ops);
}

void	two_numbers(t_node *a, t_ops *ops)
{
	if (a->value > a->next->value)
		sa(&a, ops);
}

void	three_numbers(t_node **a, t_ops *ops)
{
	t_node	*top;

	top = *a;
	if (top->value > top->next->value && top->value > top->next->next->value)
		ra(a, ops);
	else if (top->next->value > top->value
		&& top->next->value > top->next->next->value)
		rra(a, ops);
	top = *a;
	if (top->value > top->next->value)
		sa(a, ops);
}

void	four_numbers(t_node **a, t_node **b, t_ops *ops)
{
	push_min_to_b(a, b, ops);
	three_numbers(a, ops);
	pa(a, b, ops);
}

void	five_numbers(t_node **a, t_node **b, t_ops *ops)
{
	push_min_to_b(a, b, ops);
	push_min_to_b(a, b, ops);
	three_numbers(a, ops);
	pa(a, b, ops);
	pa(a, b, ops);
}
