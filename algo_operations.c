/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:47:06 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/04 14:47:02 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_top(t_list **dest, t_list **src)
{
	int	*top_value;

	top_value = get_top_value(*src);
	if (!top_value)
		return (0);
	*dest = cll_add_at_begin (*dest, *top_value);
	if (!(*dest))
		return (0);
	*src = cll_delete_top (*src);
	if (!(*src))
		return (0);
	return (1);
}

int	push_a(t_list **dest, t_list **src)
{
	int	count;

	count = push_top(dest, src);
	ft_printf("pa\n");
	return (count);
}

int	push_b(t_list **dest, t_list **src)
{
	int	count;

	count = push_top(dest, src);
	ft_printf("pb\n");
	return (count);
}

int	swap_a(t_list **a, t_list **b)
{
	if (l_count(*a) > 1 && compare_top_two(*a) 
		&& l_count(*b) > 1 && !compare_top_two(*b))
	{
		swap_start(a);
		swap_start(b);
		ft_printf("%s\n", "ss");
		return (1);
	}
	else if (l_count (*a) > 1 && compare_top_two(*a))
	{
		swap_start(a);
		ft_printf("%s\n", "sa");
		return (1);
	}
	return (0);
}

int	swap_b(t_list **b)
{
	if (l_count (*b) > 1 && !compare_top_two(*b))
	{
		swap_start(b);
		ft_printf("%s\n", "sb");
		return (1);
	}
	return (0);
}
