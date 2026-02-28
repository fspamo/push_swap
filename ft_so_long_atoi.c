/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_atoi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:42:06 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/28 19:10:22 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long int	ft_so_long_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long int	final;

	i = 0;
	final = 0;
	sign = 1;
	while (((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
			&& (nptr[i] != '\0'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = -1;
	while ((nptr[i] >= '0' && nptr[i] <= '9') && (nptr[i] != '\0'))
	{
		if (final > (LONG_MAX - (nptr[i] - '0')) / 10)
			print_error();
		final = (nptr[i] - '0') + final * 10;
		i++;
	}
	if (sign * final > INT_MAX || sign * final < INT_MIN)
		print_error();
	return (sign * final);
}
