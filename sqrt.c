/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:14:09 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/22 20:03:08 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int n)
{
	int	left;
	int	right;
	int	result;
	int	mid;

	mid = 0;
	left = 0;
	right = n;
	result = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (mid * mid == n)
			return (mid);
		else if (mid * mid < n)
		{
			result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return (result);
}
