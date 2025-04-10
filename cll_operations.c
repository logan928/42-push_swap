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
	tail -> next -> total = tail -> total;
	tail -> next -> min = tail -> min;
	tail -> tail_count = 0;
	tail -> total = 0;
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
	temp -> total = tail -> total;
	temp -> min = tail -> min;
	tail -> tail_count = 0;
	tail -> total = 0;
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

int find_min_max_pos(t_list *tail)
{
	int count;
	t_list *temp;
	int min_pos;
	int max_pos;
	int max;
	int min;
	int avg;
	int below_avg_total;
	int below_avg_count;
	
	if(!tail || !(tail -> next))
		return (0);
	temp = tail -> next;
	count = 1;
	max = temp -> content;
	min = temp -> content;
	max_pos = 1;
	min_pos = 1;
	below_avg_count = 0;
	below_avg_total = 0;
	avg = (int) (tail -> total / tail -> tail_count );

	do
    {
		if (temp -> content > max)
		{
			max = temp -> content;
			max_pos = count;
		}
		else if (temp -> content < min)
		{
			min = temp -> content;
			min_pos = count;
		}
		if (temp -> content < avg)
		{
			below_avg_count++;
			below_avg_total += temp -> content;
		}
		temp = temp -> next;
		count++;
	}while (temp -> next != tail -> next -> next);
	tail -> min = min;
	tail -> min_pos = min_pos;
	tail -> max = max;
	tail -> max_pos = max_pos;
	if (below_avg_count > 0)
		tail -> check_val =  (int) (below_avg_total / below_avg_count );
	else
		tail -> check_val = max;
	return (1);
}



int get_rotate_count(t_list *list) // need to update direction, also need to handle when the count of the list is two. suggestion: add a swap_a() followed by a push_b();
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

	min_pos = 1;
	
	temp = list -> next;

		do {
			min = temp -> content;
			count = 1;
			min_pos = 1;
			do
			{
				if (temp -> content < min)
				{
					min = temp -> content;
					min_pos = count;
				}
				temp = temp -> next;
				count++;
			}while (count < new_end);
			
			temp = NULL;
			new_end = min_pos;
			temp = list -> next;
			if (min > list -> check_val)
			{
				break;
			}
			last_min_index = min_pos;

			/*
			if (min > avg_lower)
				break;
				*/


		}while (min_pos > 2);

return (last_min_index);

}
