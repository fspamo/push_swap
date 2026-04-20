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

void	navigation(t_node **a, int strat, t_ops *ops)
{
	t_node	*b;
	float	disorder;

	disorder = compute_disorder(*a);
	b = NULL;
	if (strat == 0)
		bubble_sorting(a, ops);
	else if (strat == 1)
		chunk_sorting(a, &b, ops);
	else if (strat == 2)
		radix(a, &b, ops);
	else if (strat == 3)
	{
		if (disorder < 0.2)
			bubble_sorting(a, ops);
		else if (0.2 <= disorder && disorder < 0.5)
			chunk_sorting(a, &b, ops);
		else if (disorder >= 0.5)
			radix(a, &b, ops);
	}
}
