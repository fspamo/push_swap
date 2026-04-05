/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchingen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:00:17 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/04/05 01:49:39 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void    benchmarking(t_ops *ops, int strat, float disorder)
{
    ops->ra++;
    strat++;
    disorder = disorder + 0.2;
}
