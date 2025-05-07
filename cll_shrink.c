/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cll_shrink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:26:00 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/15 12:28:03 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*cll_delete_last(t_list *tail)
{
	t_list	*temp;

	if (!tail)
		return (NULL);
	temp = tail -> next;
	if (tail -> next == tail)
	{
		free(tail);
		tail = NULL;
		return (tail); 
	}
	while (temp -> next != tail)
		temp = temp -> next;
	temp -> next = tail -> next;
	temp -> tail_count = --(tail -> tail_count);
	temp -> total = tail -> total - tail -> content;
	free(tail);
	return (temp);
}

t_list	*cll_delete_top(t_list *tail)
{
	t_list	*temp;

	if (!tail)
		return (NULL);
	temp = tail -> next;
	if (tail -> next == tail)
	{
		free(tail);
		tail = NULL;
		return (tail);
	}
	tail -> next = temp -> next;
	--(tail -> tail_count);
	tail -> total -= temp -> content;
	free (temp);
	temp = NULL;
	return (tail);
}

void	delete_list(t_list **tail)
{
	t_list	*temp;
	int		count;
	int		i;

	if (!(*tail) || !((*tail)-> next))
		return ;
	count = (*tail)-> tail_count;
	i = 1;
	while (i < count)
	{
		temp = (*tail)-> next;
		(*tail)-> next = temp -> next;
		free (temp);
		temp = NULL;
		i++;
	}
	free (*tail);
	*tail = NULL;
}
