/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 23:50:39 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/24 23:58:00 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	r_rotate(t_node **a)
{
	t_node	*prev;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return;

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

void	rra(t_node **a)
{
	r_rotate(a);
	write(1, "ra\n", 3);
}

void	rrb(t_node **b)
{
	r_rotate(b);
	write(1, "rb\n", 3);
}

void	rrr(t_node **b, t_node **a)
{
	r_rotate(b);
	r_rotate(a);
	write(1, "rr\n", 3);
}
