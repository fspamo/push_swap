/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melipola <melipola@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 23:50:39 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/04/16 16:52:22 by melipola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	r_rotate(t_node **a)
{
	t_node	*prev;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
}

void	rra(t_node **a, t_ops *ops)
{
	r_rotate(a);
	write(1, "rra\n", 4);
	ops->rra++;
}

void	rrb(t_node **b, t_ops *ops)
{
	r_rotate(b);
	write(1, "rrb\n", 4);
	ops->rrb++;
}

void	rrr(t_node **a, t_node **b, t_ops *ops)
{
	r_rotate(b);
	r_rotate(a);
	write(1, "rrr\n", 4);
	ops->rrr++;
}
