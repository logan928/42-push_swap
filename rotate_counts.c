/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_counts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:38:31 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/15 16:35:01 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list *list, t_limits *rl, t_list *temp, t_list *pr_min)
{
	while (rl -> min_pos > 1 && rl -> min_pos <= list -> tail_count)
	{
		rl -> min = temp -> content;
		rl -> min_pos = 1;
		while (rl -> count <= rl -> new_end)
		{
			if (temp -> content < rl -> min)
			{
				rl -> min = temp -> content;
				rl -> min_pos = rl -> count;
				pr_min = temp;
			}
			temp = temp -> next;
			(rl -> count)++;
		}
		temp = NULL;
		rl -> new_end = (rl -> min_pos) - 1;
		rl -> count = 1;
		temp = list -> next;
		if (rl -> min > list -> check_val)
			break ;
		rl -> last_min_index = rl -> min_pos;
	}
}

static void	rev_rotate(t_list *list, t_limits *rl, t_list *temp, t_list *pr_min)
{
	while (rl -> min_pos > 1 && rl -> min_pos < list -> tail_count)
	{
		rl -> min = temp -> content;
		while (rl -> count <= rl -> new_end)
		{
			if (temp -> content <= rl -> min)
			{
				rl -> min = temp -> content;
				rl -> min_pos = rl -> count;
				pr_min = temp;
			}
			if (temp -> content == rl -> min)
				pr_min = temp;
			temp = temp -> next;
			(rl -> count)++;
		}
		temp = NULL;
		rl -> count = rl -> min_pos + 1; 
		temp = pr_min -> next; 
		if (rl -> min > list -> check_val)
			break ;
		rl -> last_min_index = rl -> min_pos;
	}
}

int	get_rotate_count(t_list *list)
{
	t_list		*temp;
	t_list		*pr_min;
	t_limits	rl;

	if (!list || !(list -> next))
		return (0);
	rl.new_end = list -> min_pos;
	rl.min_pos = list -> min_pos;
	rl.last_min_index = 1;
	rl.count = 1;
	temp = list -> next;
	pr_min = NULL;
	if (list -> tail_count > 1 || list -> min_pos != 1)
		rotate(list, &rl, temp, pr_min);
	return (rl.last_min_index);
}

int	get_rev_rotate_count(t_list *list)
{
	t_list		*temp;
	t_list		*pr_min;
	t_limits	rl;

	if (!list || !(list -> next))
		return (0);
	rl.new_end = list -> tail_count;
	rl.min_pos = list -> min_pos;
	rl.last_min_index = 1;
	rl.count = 1;
	pr_min = NULL; 
	temp = list -> next;
	if (list -> min_pos == list -> tail_count)
		return (0);
	if (list -> tail_count > 1 || list -> min_pos != list -> tail_count)
		rev_rotate(list, &rl, temp, pr_min);
	return ((list -> tail_count) - rl.last_min_index);
}

int	find_insert_pos(t_list *tail, int i_val)
{
	int		count;
	int		stack_size;
	t_list	*temp;

	count = 0;
	if (!tail || !(tail -> next))
		return (0);
	if (tail -> next == tail)
		return (1);
	stack_size = tail -> tail_count;
	temp = tail -> next;
	count = 1;
	while (stack_size > 1)
	{
		if ((i_val < (temp -> content)) && ((temp -> next -> content) < i_val))
			return (count);
		temp = temp -> next;
		count++;
		stack_size--;
	}
	return (count);
}
