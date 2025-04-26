/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cll_comparisons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:41:50 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/15 13:29:54 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int	compare_top_two(t_list *tail)
{
	if (!tail || tail == tail -> next)
		return (0);
	return (tail -> next -> content > tail -> next -> next -> content);
}

int	cmp_btm(t_list *tail)
{
	if (!tail || tail == tail -> next)
		return (0);
	return (tail -> next -> content > tail -> content);
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

int	check_sorted(t_list **tail)
{
	if ((*tail)-> tail_count == push_count(*tail, 1))
		return (1);
	return (0);
}
