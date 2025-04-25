/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondalgo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:23:31 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/25 11:23:38 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	populate_b(t_list **a, t_list **b);
void	sequence_a(t_list **a, t_list **b);
int		rotate_count(int total_count, int max_p, int min_p);

void	min_to_top(t_list **tail, t_list **tail_b)
{
	int	min_position;

	//min_position = search_value(*tail, (*tail)-> min);
	min_position = (*tail)-> min_pos;
	if (min_position > (((*tail)-> tail_count) / 2))
	{
		while (((*tail)-> tail_count) - min_position + 1)
		{
			rev_rotate_a(tail, tail_b, 1);
			min_position++;
		}
	}
	else
	{
		while (min_position -1 > 0)
		{
			rotate_a(tail, tail_b, 1);
			min_position--;
		}
	}
}

void	rotate_push_a(t_list **tail, t_list **tb, int rotate, int check_min)
{
	find_min_max_pos(*tb);
	rotate = rotate_count((*tb)-> tail_count, (*tb)-> max_pos, (*tb)-> min_pos);
	if (rotate > 1)
	{
		while (rotate > 1)
		{
			rotate_b(tail, tb, 1);
			rotate--;
		}
	}
	else
	{
		rotate *= -1;
		while (rotate + 1 > 0)
		{
			rev_rotate_b(tail, tb, 1);
			rotate--;
		}
	}
	check_min = (*tb)-> min;
	push_a(tail, tb);
	if ((*tail)-> next -> content == check_min)
		rotate_a(tail, tb, 1);
}

void	sort_algo(t_list **tail)
{
	t_list	*tail_b;
	int		rotate;
	int		check_min;

	rotate = 0;
	check_min = 0;
	tail_b = (t_list *)(malloc(sizeof(t_list)));
	if (!tail_b)
		return ;
	tail_b -> next = NULL;
	find_min_max_pos(*tail);
	populate_b(tail, &tail_b);
	while (tail_b -> tail_count > 1)
		rotate_push_a(tail, &tail_b, rotate, check_min);
	if (tail_b -> tail_count == 1)
		push_a(tail, &tail_b);
	find_min_max_pos(*tail);
	min_to_top(tail, &tail_b);
	delete_list(&tail_b);
	if (tail_b)
	{
		free(tail_b);
		tail_b = NULL;
	}
}

int	rotate_count(int total_count, int max_p, int min_p)
{
	int	rev_max_p;
	int	rev_min_p;

	rev_max_p = total_count - max_p;
	rev_min_p = total_count - min_p;
	if (max_p <= min_p && max_p <= rev_max_p && max_p <= rev_min_p)
		return (max_p);
	else if (min_p <= max_p && min_p <= rev_max_p && min_p <= rev_min_p)
		return (min_p);
	else if (rev_max_p <= max_p && rev_max_p <= min_p && rev_max_p <= rev_min_p)
		return (rev_max_p * -1);
	else if (rev_min_p <= max_p && rev_min_p <= min_p && rev_min_p <= rev_max_p)
		return (rev_min_p * -1);
	else
		return (0); 
}

/*
optimize_a
	int	last;

	success = 0;
	do 
	{
		success = 0;
		first = (*a) -> next -> content;
		second = (*a) -> next -> next -> content;
		last = (*a) -> content;
		//printf("%d %d %d \n", first, second, last);
		success += swap_a(a, b);
		if (last < first || last < second)
		{
			//success += rev_rotate_a(a, b, 0);
		}
		
	}while (success != 0);
}

void optimize_b(t_list **a, t_list **b) // Think about it
{
	int success;
	int	first;
	int	second;
	int	last;

	success = 0;
	do 
	{
		success = 0;
		first = (*b) -> next -> content;
		second = (*b) -> next -> next -> content;
		last = (*b) -> content;
		success += swap_b(a, b);
		//if (last < first || last < second)
			success += rev_rotate_b(a, b, 0);
		
	}while (success != 0);
}

*/
