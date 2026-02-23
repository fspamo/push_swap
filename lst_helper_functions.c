/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_helper_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:15:30 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/24 01:42:41 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
