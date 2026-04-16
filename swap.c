/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melipola <melipola@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:46:47 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/04/16 16:54:04 by melipola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_node **a, t_ops *ops)
{
	swap(a);
	write(1, "sa\n", 3);
	ops->sa++;
}

void	sb(t_node **b, t_ops *ops)
{
	swap(b);
	write(1, "sb\n", 3);
	ops->sb++;
}

void	ss(t_node **a, t_node **b, t_ops *ops)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	ops->ss++;
}
