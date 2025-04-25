/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_b_updates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:43:56 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/22 12:44:01 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_checks(min_check_vals *cv, t_list *t, int count, int first_found)
{
	t_list	*temp;

	temp = t -> next;
	while (count <= t -> tail_count)
	{
		if (temp -> content < t -> check_val)
		{
			if (first_found == 0)
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

void	update_check_vals(min_check_vals *cv, t_list *t)
{
	int		count;
	t_list	*temp;
	int		first_found; 

	if (!t || !t->next) 
		return ;
	temp = t -> next;
	count = 1;
	first_found = 0;
	update_checks(cv, t, count, first_found);
}
