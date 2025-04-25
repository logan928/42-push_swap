/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cll_comparisons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:41:50 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/15 13:29:54 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_top_two(t_list *tail)
{
	if (!tail || tail == tail -> next)
		return (0);
	return (tail -> next -> content > tail -> next -> next -> content);
}

int	cmp_btm(t_list *tail)
{
	if (!tail || tail == tail -> next)
		return (0);
	return (tail -> next -> content > tail -> content);
}
