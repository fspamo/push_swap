/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:31:11 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/04/07 00:26:46 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	put_nbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		put_nbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	put_float(float n, int fd)
{
	int	int_part;
	int	dec_part;

	int_part = (int)(n * 100);
	dec_part = int_part % 100;
	int_part = int_part / 100;
	put_nbr_fd(int_part, fd);
	write(fd, ".", 1);
	if (dec_part < 10)
		write(fd, "0", 1);
	put_nbr_fd(dec_part, fd);
}

char	*strat_name(int strat, t_node *a)
{
	if (strat == 0)
		return ("Simple / O(n^2)");
	else if (strat == 1)
		return ("Medium / O(n*sqrt(n))");
	else if (strat == 2)
		return ("Complex / O(n log n)");
	return (adp_printer(a));
}
