/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finale.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:03:45 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/05 16:03:59 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *find_min(t_node *a)
{
    t_node *holder;
    t_node *to_return;

    if (!a)
        return NULL;
    to_return = a;
    holder = a->next;
    while (holder)
    {
        if (holder->value < to_return->value)
            to_return = holder;
        holder = holder->next;
    }
    return to_return;
}

void	final_rotate(t_node **a)
{
	t_node	*min;
	t_node	*holder;

	holder = *a;
	min = find_min(holder);
	rotate_to_target(a, min);
}
