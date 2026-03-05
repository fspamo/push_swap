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

// code this after the the_hunter

t_node *find_the_target(t_node *a, int target_val)
{
	t_node	*holder;
	t_node	*the_best_pos;

	holder = a;
	while (holder)
	{

	}
	return (the_best_pos);
}

// in order to make it run, finish rotate to target func
 
void the_hunter(t_node **a, t_node **b)
{
    t_node *target;
    int target_val;

	while (*b)
    {
		target_val = (*b)->value;

		target = find_the_target(*a, hunt); // target is the value we want to return from find_best_pos

		rotate_to_target(a, target);
		pa(a, b); 
	}
}

// make the selected node to our node's head 

void	rotate_the_target(t_node **a, t_node *target)
{
	int len;

	len = 0;
}
