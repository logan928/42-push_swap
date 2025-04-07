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

t_list *cll_init(t_list *tail, int	f_value)
{
	//t_list *tail = (t_list *)(malloc(sizeof(t_list)));
	//if(!tail)
	//	return (NULL);
	tail -> content = f_value;
	tail -> next = tail;
	tail -> tail_count = 1;
	return (tail);
}

t_list *cll_add_at_end(t_list *tail, int node_value)
{
	t_list *new_node = (t_list *)(malloc(sizeof(t_list)));
	if(!new_node)
		return (NULL);
	new_node -> content = node_value;
	new_node -> next = tail -> next;
	new_node -> tail_count = ++(tail -> tail_count);
	tail -> tail_count = 0;
	tail -> next = new_node;
	return (new_node);
}

t_list *cll_add_at_begin(t_list *tail, int node_value)
{
	//t_list *new_node = (t_list *)(malloc(sizeof(t_list)));
//	if(!new_node)
//		return (NULL);
//	new_node -> content = node_value;

	if(!tail || !(tail -> next))
	{
		//new_node -> next = new_node;
		//return (new_node);
	//printf("Im here \n");
		return (cll_init(tail, node_value));
	}
	t_list *new_node = (t_list *)(malloc(sizeof(t_list)));
	if(!new_node)
		return (NULL);
	new_node -> next = tail -> next;
	new_node -> content = node_value;
	new_node -> tail_count = 0;
	tail -> next = new_node;
	tail -> tail_count = ++(tail -> tail_count);
	//printf("debug...%d \n", tail -> next -> content);
	return (tail);	
}

t_list *cll_delete_last(t_list *tail)
{
	t_list *temp;

	if (!tail)
		return (NULL);
	temp = tail -> next;
       	if(tail -> next == tail)
	{
		free(tail);
		tail = NULL;
		return (tail); 
	}	
	while(temp -> next != tail)
	{
		temp = temp -> next;
	}
	temp -> next = tail -> next;
	temp -> tail_count = --(tail -> tail_count);
	free(tail);
	return (temp);

}

t_list *cll_delete_top(t_list *tail)
{
	t_list *temp;

	if(!tail)
		return (NULL);
	temp = tail -> next;
	if (tail -> next == tail)
	{
		free(tail);
		tail = NULL;
		return (tail);
	}
	tail -> next = temp -> next;
	--(tail -> tail_count);
	free (temp);
	temp = NULL;
	return (tail);
}

int	*get_top_value(t_list *tail)
{
	if (!tail)
		return (NULL);
	return (&(tail -> next -> content));
}

int	compare_top_two(t_list *tail)//checked
{
        if (!tail || tail == tail -> next)
                return (0);
	return (tail -> next -> content > tail -> next -> next -> content);
}

int     compare_top_bottom(t_list *tail)
{
       if (!tail || tail == tail -> next)
                return (0);
       
	return (tail -> next -> content > tail  -> content);
}

void delete_list (t_list **tail)
{
	t_list *temp;
	
	if(!(*tail) || !((*tail) -> next))
		return;
	temp = (*tail) -> next;
	while(temp != *tail)
	{
		(*tail) -> next = temp -> next;
		free (temp);
		temp = NULL;
		temp = (*tail) -> next;
	}
	free (*tail);
	*tail = NULL;
}
//t_list *cll_init(int    *f_value) - initializes a circular linked-list with the data passed taken as first node value.
//t_list *cll_add_at_end(t_list *tail, int *node_value) - adds a node to the end of the cll. 
//t_list *cll_add_at_begin(t_list *tail, int *node_value) - adds a node to the begining of the cll, if its not already empty.
//t_list *cll_delete_last(t_list *tail) - deletes the last (tail) of a cll.The function only deletes the last node and returns the value. Therefore, retrieving the deleted node has to be done outside the function. Deleting is requried when swap() operation is done.It would be a good practice to first add the respective node to the other list and then perform the deleting on this list. 
