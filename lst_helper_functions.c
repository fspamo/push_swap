/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_helper_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:15:30 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/08 18:09:16 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_node *new_lst(int value)
{
	t_node *node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void add_back(t_node **lst, t_node *new_node)
{
    t_node *temp;

    if (!lst || !new_node)
        return;
    new_node->next = NULL;
    if (*lst == NULL)
    {
        *lst = new_node;
        return;
    }
    temp = *lst;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}
