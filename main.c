/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:02:33 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/04 23:03:37 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	print_stack(t_node *a)
{
	printf("A stack:\n");
	t_node	*to_print = a;
	while (to_print)
	{
		printf("%d lis value: %d\n", to_print->value, to_print->in_lis);
		to_print = to_print->next;
	}
}

int	re_arange(int argc, char **argv, t_node **a)
{
    char    *joined;
    char    **numbers;
    int     i;

    joined = join_args(argc, argv);
    if (!joined)
        return (1);
    numbers = ft_split(joined, ' ');
    free(joined);
    if (!numbers)
        return (1);
    i = 0;
    while (numbers[i])
    {
        int value = ft_so_long_atoi(numbers[i]);
        add_back(a, new_lst(value));
        free(numbers[i]);
        i++;
    }
    free(numbers);
	return (0);
}

int main(int argc, char **argv)
{
    t_node  *a;
    t_node  *b;

    a = NULL;
    b = NULL;
    (void)b;

    if (argc < 2)
    {
		write(1, "Error\n", 6);
		return (1);
    }
	if (re_arange(argc, argv, &a))
		return (1);
	default_controls(a);
	navigation(&a);
	print_stack(a);
    return (0);
}
