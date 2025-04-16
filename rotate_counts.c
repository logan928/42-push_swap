/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_counts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:38:31 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/15 16:35:01 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


static void	rotate(t_list *list, t_limits *rl, t_list *temp, t_list *prev_min)
{
	while  (rl -> min_pos > 1 && rl -> min_pos <= list -> tail_count)
	{
		rl -> min = temp -> content;
		rl -> min_pos = 1;
		do
		{
			if (temp -> content < rl -> min)
			{
				rl -> min = temp -> content;
				rl -> min_pos = rl -> count;
				prev_min = temp;
			}
			temp = temp -> next;
			(rl -> count)++;
		}
	    while (rl -> count < rl -> new_end);
		temp = NULL;
		rl -> new_end = rl -> min_pos;
		rl -> count = 1;
		temp = list -> next;
		if (rl -> min > list -> check_val)
			break;
		rl -> last_min_index = rl -> min_pos;
	} 
}

/*
	static void	rotate(t_list *list, t_limits *rl, t_list *temp, t_list *prev_min)
	{
		int	loop = 1;
	
		while (loop && rl->min_pos > 1 && rl->min_pos <= list->tail_count)
		{
			// Initialize for each outer loop pass
			temp = list->next;
			rl->min = temp->content;
			rl->min_pos = 1;
			rl->count = 1;
	
			while (rl->count < rl->new_end)
			{
				if (temp->content < rl->min)
				{
					rl->min = temp->content;
					rl->min_pos = rl->count;
					prev_min = temp;
				}
				temp = temp->next;
				rl->count++;
			}
	
			temp = NULL;
			rl->new_end = rl->min_pos;
			rl->count = 1;
	
			if (rl->min > list->check_val)
				break;
	
			rl->last_min_index = rl->min_pos;
		}
	}
	
*/
static void rev_rotate(t_list *list, t_limits *rl, t_list *temp, t_list *prev_min)
{
	do {
		rl -> min = temp -> content;
		do
		{
			if (temp -> content <= rl -> min)
			{
				rl -> min = temp -> content;
				rl -> min_pos = rl -> count;
				prev_min = temp;
			}
			if (temp -> content == rl -> min)
				prev_min = temp;
			temp = temp -> next;
			rl -> count++;
		}while (rl -> count <= rl -> new_end);
		temp = NULL;
		rl -> count = rl -> min_pos + 1; // can update count or can later add the min_pos to this. 
		temp = prev_min -> next; // or have a different variable to point to min_pos and get the next; 
		if (rl -> min > list -> check_val)
			break;
		rl -> last_min_index = rl -> min_pos;
	}while (rl -> min_pos > 1 && rl -> min_pos < list -> tail_count);
}

int	get_rotate_count(t_list *list)
{
	t_list			*temp;
	t_list			*prev_min;
	t_limits	rl;

	if (!list || !(list -> next))
		return (0);
	rl.new_end = list -> tail_count;
	rl.min_pos = list -> min_pos;
	rl.last_min_index = 1;
	rl.count = 1;
	temp = list -> next;
	prev_min = NULL;
	if (list -> tail_count > 1 || list -> min_pos != 1)  
		rotate(list, &rl, temp, prev_min);
	return (rl.last_min_index);
}

int get_rev_rotate_count(t_list *list) 
{
	t_list			*temp;
	t_list			*prev_min;
	t_limits	rl;

	if(!list || !(list -> next))
		return (0);
	rl.new_end = list -> tail_count;
	rl.min_pos = 1;
	rl.last_min_index = 1;
	rl.count = 1;
	prev_min = NULL; 
	temp = list -> next;
	rev_rotate(list, &rl, temp, prev_min);
return ((list -> tail_count ) - rl.last_min_index );
}
