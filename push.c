/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:45:32 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/04/16 00:12:56 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h> 

void	push(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	pa(t_node **a, t_node **b, t_ops *ops)
{
	push(b, a);
	write(1, "pa\n", 3);
	ops->pa++;
}

void	pb(t_node **a, t_node **b, t_ops *ops)
{
	push(a, b);
	write(1, "pb\n", 3);
	ops->pb++;
}
