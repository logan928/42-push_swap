/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cll_find_min_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:49:33 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/18 14:49:36 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	init_min_max_values(t_limits *l_set, t_list *start_node)
{
	l_set -> count = 1;
	l_set -> max = start_node -> content;
	l_set -> min = start_node -> content;
	l_set -> max_pos = 1;
	l_set -> min_pos = 1;
	l_set -> below_avg_count = 0;
	l_set -> below_avg_total = 0;
	l_set -> h_total = 0;
}

static void	update_tail(t_limits mm, t_list *tail)
{
	tail -> min = mm.min;
	tail -> min_pos = mm.min_pos;
	tail -> max = mm.max;
	tail -> max_pos = mm.max_pos;
	if (mm.below_avg_count > 1)
		tail -> check_val = (int)(mm.below_avg_total / mm.below_avg_count);
	else
		tail -> check_val = mm.below_avg_total;
	tail -> half_total = mm.h_total;
}

static void	update_min_max(t_limits *mm, int value, int count)
{
	if (value > mm -> max)
	{
		mm -> max = value;
		mm -> max_pos = count;
	}
	else if (value < mm -> min)
	{
		mm -> min = value;
		mm -> min_pos = count;
	}
	if (value <= mm -> avg)
	{
		mm -> below_avg_total += value;
		++(mm -> below_avg_count);
	}
}

int	find_min_max_pos(t_list *tail)
{
	t_list		*temp;
	t_limits	mm;

	if (!tail || !(tail -> next))
		return (0);
	temp = tail -> next;
	init_min_max_values(&mm, temp);
	mm.avg = (int)(tail -> total / tail -> tail_count);
	while (temp)
	{
		update_min_max(&mm, temp -> content, mm.count);
		if (mm.count < (tail -> tail_count) / 2)
			mm.h_total += temp -> content;
		temp = temp -> next;
		mm.count++;
		if (temp -> next == tail -> next -> next)
			break ;
	}
	update_tail(mm, tail);
	return (1);
}
