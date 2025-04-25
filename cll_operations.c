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

void	swap_start(t_list **tail)
{
	int	temp;

	if (*tail && (*tail)-> next != *tail)
	{
		temp = (*tail)-> next -> next -> content;
		(*tail)-> next -> next -> content = (*tail)-> next -> content;
		(*tail)-> next -> content = temp;
	}
}

t_list	*rotate_list(t_list *tail)
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

t_list	*rev_rotate_list(t_list *tail)
{
	t_list	*temp;

	if (!tail || !(tail -> next))
		return (NULL);
	if (tail -> next == tail)
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

int	l_count(t_list *tail)
{
	int		count;
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

int	search_value(t_list *tail, int num)
{
	int		count;
	t_list	*temp;

	if (!tail || !(tail -> next))
		return (0);
	temp = tail -> next;
	count = 1;
	while (temp -> next != tail -> next -> next)
	{
		if (temp -> content == num)
			return (count);
		temp = temp -> next;
		count++;
	}
	return (0);
}
/*
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
*/
