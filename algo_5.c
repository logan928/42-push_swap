/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:43:15 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/25 13:43:19 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_algo_3(t_list **a)
{
    if ((*a)-> tail_count == push_count(*a, 1))
        return ;
    if ((*a)-> min_pos == 1)
    {
        rev_rotate_a(a, NULL, 1);
        swap_start(a);
		ft_printf("%s\n", "sa");
    }
    else if ((*a)-> max_pos == 3)
    {
        swap_start(a);
		ft_printf("%s\n", "sa");
    }
    else if ((*a)-> max_pos == 1)
    {
        rotate_a(a, NULL, 1);
        if (check_sorted(a) != 1)
        {
            swap_start(a);
            ft_printf("%s\n", "sa");
        }
    }
    else
        rev_rotate_a(a, NULL, 1);
}

void	sort_algo_5(t_list **a)
{
    t_list	*tail_b;
    int     rotate;

    rotate = 0;
	tail_b = (t_list *)(malloc(sizeof(t_list)));
	if (!tail_b)
		return ;
    tail_b -> next = NULL;
    while ((*a)-> tail_count > 3)
    {
        find_min_max_pos(*a);
        rotate = (*a)-> min_pos;
        if (rotate <= (*a)-> tail_count / 2)
        {
            while (rotate > 1)
            {
                rotate_a(a, &tail_b, 1);
                rotate--;
            }
        }
        else
        {
            rotate = (*a)-> tail_count - rotate;
            while (rotate > -1)
            {
                rev_rotate_a(a, &tail_b, 1);
                rotate--;
            }
        }            
        push_b(&tail_b, a);
    }
    find_min_max_pos(*a);
    sort_algo_3(a);
    find_min_max_pos(tail_b);
    if (tail_b -> min_pos != 1)
        swap_b(a, &tail_b);
    rotate = tail_b -> tail_count;
    while (rotate > 0)
    {
        push_a(a, &tail_b);
        rotate--;
    }
 
 /*
    while (tail_b -> tail_count > 1)
    {
        rotate = find_insert_pos(*a, tail_b -> next -> content);
        while (rotate > 0)
        {
            rotate_a(a, &tail_b, 1);
            rotate--;
        }
        push_a(a, &tail_b);
    }
    if (tail_b -> tail_count == 1)
		push_a(a, &tail_b);

    
    while (1)
    {
        find_min_max_pos(*a);
        if ((*a)-> min_pos == 1)
            break;
        rotate_a(a, &tail_b, 1);
    }
    */
    
}