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

int	l_count(t_list *tail) //checked
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
	} while (temp -> next != tail -> next -> next);
	return (0);
}
