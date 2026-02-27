/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:02:33 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/25 00:51:18 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	print_stack(t_node *stack)
{
	t_node	*to_print = stack;
	while (to_print)
	{
		printf("%d \n", to_print->value);
		to_print = to_print->next;
	}
}

int main(int argc, char **argv)
{
    t_node  *a;
    t_node  *b;
    char    *joined;
    char    **numbers;
    int     i;

    a = NULL;
    b = NULL;
    (void)b;

    if (argc < 2)
    {
        write(1, "Error\n", 6);
        return (1);
    }
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
        int value = ft_atoi(numbers[i]);
        add_back(&a, new_lst(value));
        free(numbers[i]);
        i++;
    }
    free(numbers);
    is_sorted(a);
    print_stack(a);
    return (0);
}
