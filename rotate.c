/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:15:04 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/08 17:47:24 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rotate(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return;

	first = *a;
	*a = first->next;

	last = *a;
	while (last->next)
		last = last->next;

	last->next = first;
	first->next = NULL;
}

void ra(t_node **a, t_ops *ops)
{
    rotate(a);
    write(1, "ra\n", 3);
    ops->ra++;
}

void	rb(t_node **b, t_ops *ops)
{
	rotate(b);
	write(1, "rb\n", 3);
	ops->rb++;
}

void	rr(t_node **b, t_node **a, t_ops *ops)
{
	rotate(b);
	rotate(a);
	write(1, "rr\n", 3);
	ops->rr++;
}
