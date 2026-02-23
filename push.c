/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:45:32 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/24 02:00:09 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h> 

void    push(t_node **src, t_node **dest)
{
    t_node  *temp;

    if (!src || !*src)
        return;

    temp = *src;
    *src = (*src)->next;

    temp->next = *dest;
    *dest = temp;
}

void    pa(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void    pb(t_node **b, t_node **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
