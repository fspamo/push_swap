/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 01:57:56 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/29 15:42:11 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int  total_length(int argc, char **argv)
{
	int i;
	int len;

	i = 1;
	len = 0;
	while (i < argc)
	{
		len += ft_strlen(argv[i]);
		if (i < argc - 1)
			len += 1; 
		i++;
	}
	return (len);
}

char *join_args(int argc, char **argv)
{
	char    *joined;
	int     i;
	int     j;
	int     k;

	joined = malloc(sizeof(char) * (total_length(argc, argv) + 1));
	if (!joined)
		return (NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			joined[k++] = argv[i][j++];

		if (i < argc - 1)
			joined[k++] = ' ';
		i++;
	}
	joined[k] = '\0';
	return (joined);
}
