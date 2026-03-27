/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:09:20 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/26 17:22:01 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void navigation(t_node **a, int strat)
{
	t_node	*b;
	/* float	disorder; */

	/* disorder = compute_disorder(*a); */
	b = NULL;
	if (strat == 0)
		bubble_sorting(a);
	else if (strat == 1)
		chunk_sorting(a, &b);
	else if (strat == 2)
		radix(a, &b);
	// DO ADAPTIVE
}
