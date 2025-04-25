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

void	sort_algo_3(t_list **a)
{
    if ((*a)-> min_pos == 1)
    {
        *a = rev_rotate_list(*a);
		ft_printf("%s\n", "rra");
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
        *a = rotate_list(*a);
		ft_printf("%s\n", "ra");
        swap_start(a);
		ft_printf("%s\n", "sa");
    }
    else
    {
        *a = rev_rotate_list(*a);
		ft_printf("%s\n", "rra");
    }
}

void	sort_algo_5(t_list **a)
{
    t_list	*tail_b;
    int     rotate;
    int     direction;

    rotate = 0;
    direction = 0;
	tail_b = (t_list *)(malloc(sizeof(t_list)));
	if (!tail_b)
		return ;
    tail_b -> next = NULL;
    while ((*a)-> tail_count > 3)
	{
		find_min_max_pos(*a);
        rotate = rotate_count((*a)->tail_count, (*a)->max_pos, (*a)->min_pos);


        /*
		update_check_vals(&cv, *a);
		direction = rotate_dir_a (a, &direction, cv);
		rotate_pop_a(a, b, direction);
		r_pos = find_insert_pos(*b, ((*a)-> next -> content));
		direction = 0;
		insert_b(a, b, r_pos, direction);
        */
	}
}