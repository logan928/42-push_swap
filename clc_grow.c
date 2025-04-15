/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clc_grow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:32:10 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/02 17:10:13 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*cll_init(t_list *tail, int f_value)
{
	tail -> content = f_value;
	tail -> next = tail;
	tail -> tail_count = 1;
	tail -> total = f_value;
	return (tail);
}

t_list	*cll_add_at_end(t_list *tail, int node_value)
{
	t_list	*new_node;

	new_node = (t_list *)(malloc(sizeof(t_list)));
	if (!new_node)
		return (NULL);
	new_node -> content = node_value;
	new_node -> next = tail -> next;
	new_node -> tail_count = ++(tail -> tail_count);
	new_node -> total = (tail -> total) + node_value;
	tail -> tail_count = 0;
	tail -> next = new_node;
	return (new_node);
}

t_list	*cll_add_at_begin(t_list *tail, int node_value)
{
	t_list	*new_node;

	if (!tail || !(tail -> next))
	{
		return (cll_init(tail, node_value));
	}
	new_node = (t_list *)(malloc(sizeof(t_list)));
	if (!new_node)
		return (NULL);
	new_node -> next = tail -> next;
	new_node -> content = node_value;
	new_node -> tail_count = 0;
	tail -> next = new_node;
	tail -> tail_count = ++(tail -> tail_count);
	tail -> total += node_value;
	return (tail);
}

int	*get_top_value(t_list *tail)
{
	if (!tail)
		return (NULL);
	return (&(tail -> next -> content));
}

//t_list *cll_init(int    *f_value) 
//- initializes a circular linked-list with f_value as first node value.
//t_list *cll_add_at_end(t_list *tail, int *node_value)
//	 - adds a node to the end of the cll. 
//t_list *cll_add_at_begin(t_list *tail, int *node_value)
//	 - adds a node to the begining of the cll, if its not already empty.
//t_list *cll_delete_last(t_list *tail)
//	 - deletes the last (tail) of a cll.
//	The function only deletes the last node and returns the value.
// 	Therefore, retrieving the deleted node has to be done outside the function.
//  Deleting is requried when push() operation is done.
//  First add the respective node to the other list. 
//  and then perform the deleting on this list. 
