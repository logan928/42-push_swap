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

static void	update_checks(min_check_vals *cv, t_list *tail, int count, int first_found)
{
	t_list	*temp;

	temp = tail -> next;
	while (count <= tail -> tail_count)
	{
		if (temp -> content < tail -> check_val)
		{
			if (first_found ==0)
			{
				cv->first_check_val = temp -> content;
				cv -> first_check_pos = count;
				first_found = 1;
			}
			cv -> last_check_pos = count;
			cv -> last_check_val = temp -> content;

		}
		temp = temp -> next;
		count++;
	}
}

static void	update_check_vals(min_check_vals *cv, t_list *tail)
{
	int count;
	t_list	*temp;
	int	first_found; 

	if (!tail || !tail->next) 
		return;
	temp = tail -> next;
	count = 1;
	first_found = 0;
	update_checks(cv, tail, count, first_found);
}

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
		min_check_vals cv;

    while ((*a) -> tail_count > 1)
    {
		find_min_max_pos(*a);
		update_check_vals(&cv, *a);

		direction = 0;
		if (cv.first_check_pos == ((*a) -> tail_count - cv.last_check_pos) )
		{
			if (cv.first_check_val < cv.last_check_val)
				direction = 1;
		}
		else if (cv.first_check_pos < ((*a) -> tail_count - cv.last_check_pos))
			direction = 1;
		if (cv.first_check_pos == 1)
			direction = 1;
		
		//print_list(*a);
	//printf("fcv: %d fcp: %d, lcv: %d, lcp %d \n", cv.first_check_val, cv.first_check_pos, cv.last_check_val, cv.last_check_pos);

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

		
		int r = find_insert_pos(*b, ((*a) -> next -> content ));
		//printf("value : %d position: %d \n",  (*a) -> next -> content, r);
		//print_list(*b);
		
		int direction = 0;
		int rotate_limit = 2;

		if ((*b) -> tail_count > 1 )
		{
			find_min_max_pos(*b);
			if ( r > (*b) -> tail_count /2)
			{
				
				direction = 1;
				r = (*b) -> tail_count - r;
						//printf("value : %d position: %d \n",  (*a) -> next -> content, r);
			}
			if (r == 0 || r == (*b) -> tail_count)
			{
				push_b(b, a);
				if((*b) -> next -> content < (*b ) -> min)
					rotate_b(a, b, 0);
			}
			else if ( r == 1 && direction == 0)
			{
				push_b(b, a);
				//rotate_b(a, b, 0);
				swap_b(a, b);
			}
			else
			{
				if (direction == 0)
				{
					while (r > 0 && r <= rotate_limit)
					//while (r > 0 )
					{
						rotate_b( a, b, 1);
						
						r--;
					}
				}
				else
				{
					while (r > 0 && r <= rotate_limit)
					{
						rev_rotate_b(a, b, 1);
						r--;
					}
				}
				push_b(b,a);
			}

		}
		else
		{
			push_b(b, a);
			swap_b(a, b);
		}

		//print_list(*b);

		//printf("------------------------- \n");
		

}

}

