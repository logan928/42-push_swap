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

#include "push_swap.h"

static void	rotate_push_b(t_list **a, t_list **b, int r_pos, int direction)
{
	if (r_pos == 0 || r_pos == (*b)-> tail_count)
	{
		push_b(b, a);
		if ((*b)-> next -> content < (*b)-> min)
			rotate_b(a, b, 0);
	}
	else if (r_pos == 1 && direction == 0)
	{
		push_b(b, a);
		swap_b(a, b);
	}
	else
	{
		while (r_pos > 0 && r_pos <= 2)
		{
			if (direction == 0)
				rotate_b(a, b, 1);
			else
				rev_rotate_b(a, b, 1);
			r_pos--;
		}
		push_b(b, a);
	}
}

static void	rotate_pop_a(t_list **a, t_list **b, int direction)
{
	int	rotate_count;

	rotate_count = 0;
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
		while (rotate_count > -1)
		{
			rev_rotate_a(a, b, 1);
			rotate_count--;
		}
	}
}

static int	rotate_dir_a(t_list **a, int *direction, min_check_vals cv)
{
	if (cv.first_check_pos == ((*a)-> tail_count - cv.last_check_pos))
	{
		if (cv.first_check_val < cv.last_check_val)
			*direction = 1;
	}
	else if (cv.first_check_pos < ((*a)-> tail_count - cv.last_check_pos))
		*direction = 1;
	if (cv.first_check_pos == 1)
		*direction = 1;
	return (*direction);
}

void	insert_b(t_list **a, t_list **b, int r_pos, int direction)
{
	if ((*b)-> tail_count > 1)
	{
		find_min_max_pos(*b);
		if (r_pos > (*b)-> tail_count / 2)
		{
			direction = 1;
			r_pos = (*b)-> tail_count - r_pos;
		}
		rotate_push_b(a, b, r_pos, direction);
	}
	else
	{
		push_b(b, a);
		swap_b(a, b);
	}
}

void	populate_b(t_list **a, t_list **b)
{
	int				direction;
	int				r_pos;
	min_check_vals	cv;

	direction = 0;
	while ((*a)-> tail_count > 1)
	{
		find_min_max_pos(*a);
		update_check_vals(&cv, *a);
		direction = rotate_dir_a (a, &direction, cv);
		rotate_pop_a(a, b, direction);
		r_pos = find_insert_pos(*b, ((*a)-> next -> content));
		direction = 0;
		insert_b(a, b, r_pos, direction);
	}
}

//rotate_limit is set for 2