/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:09:20 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/12 14:48:47 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void navigation(t_node **a)
{
    t_node	*b;
	t_node	*temp_a;
	float	disorder;

	// temp_a = *a;
	// disorder = compute_disorder(temp_a);
    b = NULL;
	bubble_sorting(a);
    // if (disorder < 0.2)
    //     bubble_sorting(a);
    // if (disorder >= 1 && disorder <= 0)
    //     bubble_sorting(a);
    // else if (disorder >= 0.2 && disorder < 0.5)
        // chunk_based_sorting(a);
    // if (disorder >= 1 && disorder <= 0)
    //     radix(a, &b);
}
