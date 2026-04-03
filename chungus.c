/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:44:20 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/22 19:59:39 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

// void	print_stack_b(t_node *b)
// {
// 	printf("B stack:\n");
// 	t_node	*to_print = b;
// 	while (to_print)
// 	{
// 		printf("value: %d\n", to_print->value);
// 		to_print = to_print->next;
// 	}
// }

void chunker(t_node **a, t_node **b, t_ops *ops)
{
    int size;
    int chunk;
    int i;
    size = input_counter(*a);
    chunk = ft_sqrt(size);
    i = 0;
    while (*a)
    {
        if ((*a)->index <= i)
        {
            pb(a, b, ops);
            rb(b, ops);
            i++;
        }
        else if ((*a)->index <= i + chunk)
        {
            pb(a, b, ops);
            i++;
        }
        else
            ra(a, ops);
    }
}

void chunk_sorting(t_node **a, t_node **b, t_ops *ops)
{
    int max;
    int pos;
    int size;
    int steps;
    chunk_core_indexer(*a);
    chunker(a, b, ops);
    while (*b)
    {
        max = find_max_index(*b);
        pos = find_position(*b, max);
        size = input_counter(*b);
        if (pos <= size / 2)
            while (pos > 0)
            {
                rb(b, ops);
                pos--;
            }
        else
        {
            steps = size - pos;
            while (steps > 0)
            {
                rrb(b, ops);
                steps--;
            }
        }
        pa(a, b, ops);
    }
}
