/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:09:20 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/22 15:25:10 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void navigation(t_node **a)
{
	t_node	*b;
	float	disorder;

	disorder = compute_disorder(*a);
	b = NULL;
	if (disorder < 0.2)
		bubble_sorting(a);
	else if (disorder >= 0.2 && disorder < 0.5)
		radix(a, &b);
	else if (disorder >= 0.5)
		radix(a, &b);
}
