/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:44:21 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/27 16:23:49 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*_dest;
	unsigned char	*_src;

	_dest = (unsigned char *)dest;
	_src = (unsigned char *)src;
	i = 0;
	if (_dest < _src)
	{
		while ((n > 0) && (i < n))
		{
			_dest[i] = _src[i];
			i++;
		}
	}
	else if (dest > src)
	{
		while (n > 0)
		{
			n--;
			_dest[n] = _src[n];
		}
	}
	return (dest);
}
