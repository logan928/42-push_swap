/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:47:06 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/04 14:47:02 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	push_top(t_list **dest, t_list **src)
{

	int *top_value;

	top_value = get_top_value(*src);
	if (!top_value)
		return (0);
	*dest = cll_add_at_begin (*dest, *top_value);
	if (!(*dest))
		return (0);
	*src = cll_delete_top (*src);
       if (!(*src))
       		return (0);
	//printf("%s\n",print_str);//change
	
 	return (1);	
}// Check for empty/NULL guards before pushing. Also what if the list is already empty check?
 //
int	push_a (t_list **dest, t_list **src)
{
	int count;

	count = push_top(dest, src);//change
	printf("pa\n");
	return (count);
}

int	push_b (t_list **dest, t_list **src)
{
	int count;

	count = push_top(dest, src);//change
	printf("pb\n");
	return (count);
}

int	swap_a(t_list **a, t_list **b)
{
	if (ccl_count(*a) > 1 && compare_top_two(*a) && ccl_count(*b) >1 && !compare_top_two(*b))
	{
		swap_start(a);
		swap_start(b);
		printf("%s\n", "ss");//change
		return (1);
	}
	else if (ccl_count (*a) > 1 && compare_top_two(*a))
	{
		swap_start(a);
		printf("%s\n", "sa");//change
		return (1);
	}
	return (0);	
}

int     swap_b(t_list **a, t_list **b)
{
/*	if (ccl_count(*b) > 1 && !compare_top_two(*b) && ccl_count(*a) >1 && compare_top_two(*a))
        {
                swap_start(a);
                swap_start(b);
                printf("%s\n", "ss");//change
                return (1);
        }
*/
	if (ccl_count (*b) > 1 && !compare_top_two(*b))
        {
		swap_start(b);
               	printf("%s\n", "sb");//change
                return (1);
        }
        return (0);
}

int     rotate_a(t_list **a, t_list **b, int forced)
{
        if (ccl_count(*a) > 1 && forced)
        {
		*a = rotate_list(*a);
                printf("%s\n", "ra");//chagne
                return (1);
        }
	else if (ccl_count(*a) > 1 && compare_top_bottom(*a) && ccl_count(*b) > 1 && !compare_top_bottom(*b))
        {
                *a = rotate_list (*a);
		*b = rotate_list (*b);
		printf("%s\n", "rr");//change
                return (1);
        }
        else if (ccl_count(*a) > 1 &&  compare_top_bottom(*a))
        {
		//printf("Before rotation: %p\n", (void*)*a);//remove
		*a = rotate_list(*a);
                printf("%s\n", "ra");//chagne
		//printf("After rotation: %p\n", (void*)*a);//remove
                return (1);
        }
        return (0);
}

int     rotate_b(t_list **a, t_list **b)
{
/*        if (compare_top_bottom(*a) && !compare_top_bottom(*b))
        {
                *a = rotate_list (*a);
		*b = rotate_list (*b);
		printf("%s\n", "rr");//chagne
                return (1);
        }
*/
        if (!compare_top_bottom(*b))
        {
		*b = rotate_list(*b);
                printf("%s\n", "rb");//change
                return (1);
        }
        return (0);
}


int     rev_rotate_a(t_list **a, t_list **b, int forced)
{
        if (ccl_count(*a) > 1 &&  forced)
        {
		*a = rev_rotate_list(*a);
                printf("%s\n", "rra");//change
                return (1);
	}
	else if (ccl_count(*a) > 1 && compare_top_bottom(*a) && ccl_count(*b) > 1 && !compare_top_bottom(*b))
        {
                *a = rev_rotate_list (*a);
		*b = rev_rotate_list (*b);
		printf("%s\n", "rrr");//change
                return (1);
        }
        else if (ccl_count(*a) > 1 &&  compare_top_bottom(*a))
        {
		*a = rev_rotate_list(*a);
                printf("%s\n", "rra");//change
                return (1);
        }
        return (0);
}

int     rev_rotate_b(t_list **a, t_list **b)
{
/*        if (ccl_count(*a) > 1 && compare_top_bottom(*a) && ccl_count(*b) > 1 && !compare_top_bottom(*b))
        {
                *a = rev_rotate_list (*a);
		*b = rev_rotate_list (*b);
		printf("%s\n", "rrr");//change
                return (1);
        }
*/
        if (ccl_count(*b) > 1 && !compare_top_bottom(*b))
        {
		*b = rev_rotate_list(*b);
                printf("%s\n", "rrb");//change
                return (1);
        }
        return (0);
}
