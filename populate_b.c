/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:19:31 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/19 14:19:34 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"


void populate_b(t_list **a, t_list **b)
{

	int push;
	int max_pa;
		int min_pa;
		int		max_a;
		int		min_a;
		double middle;
		int 	rotate_count;
		int		direction;

    while ((*a) -> tail_count > 1)
    {
		find_min_max_pos(*a);
 
	//printf("count: %d, total: %lld, half-total: %d, min-val: %d, min-pos: %d check-val %d\n", (*a) -> tail_count, (*a) -> total, (*a) -> half_total, (*a) -> min, (*a) -> min_pos, (*a) -> check_val);
	//print_list(*a);
	//print_list(*b);

		direction = 0;

		if ((long long int)((*a) -> half_total) < ((long long int)((*a) -> total)/2))
		{
			//printf("1\n");
			direction = 1;
		}
		if ( ((*a) -> min_pos) < ((int)((*a) -> tail_count)/4) )
		{
			//printf("2\n");
			direction = 1;
		}

		if ( ((*a) -> min_pos) > ((int)((*a) -> tail_count) * 4/5) )
		{
			//printf("3\n");
			direction = 0;
		}
		
		if (direction == 1)
		{
			rotate_count = get_rotate_count(*a);
			while (rotate_count > 1)
			{
				rotate_a(a, b, 1);
				rotate_count--;
			}
		}
		else
		{
			rotate_count = get_rev_rotate_count(*a);
			//printf("rotating...: %d ######################### \n", rotate_count);
			while (rotate_count > -1)
			{
				rev_rotate_a(a, b, 1);
				rotate_count--;
			}
		}


		//printf("rotate count: %d \n", rotate_count);
		if (rotate_count > 50)
		{
			print_list(*a);
			print_list(*b);

			printf("unusual\n");
			break;
		}
        //push =  push_count(*a, 1);
		
		//printf("...%lf\n", middle);


		push_b(b, a);
		//print_list(*b);
		
		if ((*b) -> tail_count > 1  )
		{
			find_min_max_pos(*b);
			//rotate_b(a, b, 1);
		}

		if ((*b) -> tail_count > 1 && (*b) -> next -> content < (*b) -> check_val )
		{
			//find_min_max_pos(*b);
			rotate_b(a, b, 1);
		}

		//if ((*b) -> tail_count > 1 ) //
			//rotate_b(a, b, 1);
		//swap_a(a, b);
		swap_b(a, b);
		//print_list(*b);

		

}

}

