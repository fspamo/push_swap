/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchingen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:00:17 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/04/18 16:57:47 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	print_disorder(float disorder)
{
	write(2, "[bench] disorder: ", 18);
	put_float(disorder * 100, 2);
	write(2, "%\n", 2);
}

static void	print_ops_line1(t_ops *ops)
{
	write(2, "[bench] sa: ", 12);
	put_nbr_fd(ops->sa, 2);
	write(2, "  sb: ", 6);
	put_nbr_fd(ops->sb, 2);
	write(2, "  ss: ", 6);
	put_nbr_fd(ops->ss, 2);
	write(2, "  pa: ", 6);
	put_nbr_fd(ops->pa, 2);
	write(2, "  pb: ", 6);
	put_nbr_fd(ops->pb, 2);
	write(2, "\n", 1);
}

static void	print_ops_line2(t_ops *ops)
{
	write(2, "[bench] ra: ", 12);
	put_nbr_fd(ops->ra, 2);
	write(2, "  rb: ", 6);
	put_nbr_fd(ops->rb, 2);
	write(2, "  rr: ", 6);
	put_nbr_fd(ops->rr, 2);
	write(2, "  rra: ", 7);
	put_nbr_fd(ops->rra, 2);
	write(2, "  rrb: ", 7);
	put_nbr_fd(ops->rrb, 2);
	write(2, "  rrr: ", 7);
	put_nbr_fd(ops->rrr, 2);
	write(2, "\n", 1);
}

void	benchmarking(t_ops *ops, int strat, float disorder)
{
	int	total;

	total = ops->sa + ops->sb + ops->ss + ops->pa + ops->pb
		+ ops->ra + ops->rb + ops->rr + ops->rra + ops->rrb + ops->rrr;
	print_disorder(disorder);
	write(2, "[bench] strategy: ", 18);
	write(2, strat_name(strat), ft_strlen(strat_name(strat)));
	write(2, "\n", 1);
	write(2, "[bench] total_ops: ", 19);
	put_nbr_fd(total, 2);
	write(2, "\n", 1);
	print_ops_line1(ops);
	print_ops_line2(ops);
}
