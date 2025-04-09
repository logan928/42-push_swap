/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cll_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:07:19 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/03 12:41:15 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap_start(t_list **tail)//Checked
{
	int	temp;

	if(*tail && (*tail) -> next != *tail)
	{
		temp = (*tail) -> next -> next -> content;
		(*tail) -> next -> next -> content = (*tail) -> next -> content;
		(*tail) -> next -> content = temp;
	}
}

t_list *rotate_list (t_list *tail)
{
	if (!tail || !(tail -> next))
		return (NULL);
	if (tail -> next == tail)
		return (tail);
	tail -> next -> tail_count = tail -> tail_count;
	tail -> tail_count = 0;
	tail = tail -> next;

	return (tail);
}

t_list *rev_rotate_list(t_list *tail)
{
	t_list	*temp;
	
	if (!tail || !(tail -> next))
		return (NULL);
	if(tail -> next == tail)
		return (tail);
	temp = tail -> next;
	while (temp -> next != tail)
	{
		temp = temp -> next;
	}
	temp -> tail_count = tail -> tail_count;
	tail -> tail_count = 0;
	return (temp);
}

int	ccl_count(t_list *tail) //checked
{
	int	count;
	t_list	*temp;

	count = 2;	
	if (!tail || !(tail -> next))
		return (0);
	if (tail -> next == tail)
		return (1);
	temp = tail -> next;
	while (temp -> next != tail)
	{
		temp = temp -> next;
		count++;
	} 
	return (count);
}

int     push_count(t_list *tail, int mul) 
{
        int     count;
        t_list  *temp;

        count = 0;
        if (!tail || !(tail -> next))
                return (0);
        if (tail -> next == tail)
                return (1);
        temp = tail -> next;
	count = 1;
        while (temp != tail)
        {
		if(((temp -> content) - (temp -> next -> content)) * mul < 0)
			count++;
		else
			return (count);
                temp = temp -> next;
        }
        return (count);
}


int    find_insert_pos(t_list *tail, int inst_val) //Apr 2nd WIP
{
        int     count;
	int	stack_size;
        t_list  *temp;

        count = 0;
        if (!tail || !(tail -> next))
                return (0);
        if (tail -> next == tail)
                return (1);
	stack_size = tail -> tail_count;
        temp = tail;
	count = 1;
        while (stack_size > 0)
        {
		if((inst_val > (temp -> content)) && ( (temp -> next -> content) > inst_val) )
			return (count);
		temp = temp -> next;
		count++;
		stack_size--;
	//printf("tail: %d stack:%d count:%d \n", tail -> tail_count, stack_size, count);
        }
        return (count);
}

int search_value(t_list *tail, int num)
{
	int count;
	t_list *temp;
	
	if(!tail || !(tail -> next))
		return (0);
	temp = tail -> next;
	count = 1;
	do
       	{
		if (temp -> content == num)
			return (count);
		temp = temp -> next;
		count++;
	}while (temp -> next != tail -> next -> next);
	return (0);
}

int find_min_max_pos(t_list *tail, int *min_pos, int *max_pos, int *max, int *min)
{
	int count;
	t_list *temp;
	
	if(!tail || !(tail -> next))
		return (0);
	temp = tail -> next;
	count = 1;
	*max = temp -> content;
	*min = temp -> content;
	*max_pos = 1;
	*min_pos = 1;
	
	do
       	{
		if (temp -> content > *max)
		{
			*max = temp -> content;
			*max_pos = count;
		}
		else if (temp -> content < *min)
		{
			*min = temp -> content;
			*min_pos = count;
		}
		temp = temp -> next;
		count++;
	}while (temp -> next != tail -> next -> next);
	return (1);
}



int get_rotate_count(t_list *list)
{
	int	min_pos;
	int min;
	int	new_end;
	int new_start;
	t_list *temp;
	int 	count;
	int last_min_index;

	if(!list || !(list -> next))
		return (0);

	new_end = list -> tail_count;
	min = __INT_MAX__; // this way we ensure the initialization will be at least a min value
	//min = get_next_min(list, 1, new_end);//can avoid these if the tail node is updated with min max positions
	//min_pos = search_value (list, min);
	min_pos = 1;
	
	temp = list -> next;

		do {
			min = temp -> content;
			count = 1;
			min_pos = 1;
			printf("total %d... new_end.%d \n", list -> tail_count, min);

			do
			{
				if (temp -> content < min)
				{
					min = temp -> content;
					min_pos = count;
				}
				temp = temp -> next;
				count++;
				//printf("min_val: %d positioon: %d \n", count, min_pos);
			}while (count < new_end);
			
			//printf("min_valx: %d positioon: %d \n", min, min_pos);

			temp = NULL;
			new_end = min_pos;
			temp = list -> next;
			last_min_index = min_pos;
			printf("temp content: %d bew ened: %d \n", temp -> content, new_end);
			if (min_pos < 2)
			{
				break;
			}


			/*
			if (min > avg_lower)
				break;
				*/


		}while (min_pos > 2); // length > 2?

return (last_min_index);

}
