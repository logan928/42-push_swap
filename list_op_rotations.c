/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:50:49 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/16 14:50:54 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	rotate_a(t_list **a, t_list **b, int forced)
{
	if (l_count(*a) > 1 && forced)
	{
		*a = rotate_list(*a);
		ft_printf("%s", "ra\n");
		return (1);
	}
	else if (l_count(*a) > 1 && cmp_btm(*a) && l_count(*b) > 1 && !cmp_btm(*b))
	{
		*a = rotate_list (*a);
		*b = rotate_list (*b);
		ft_printf("%s\n", "rr");
		return (1);
	}
	else if (l_count(*a) > 1 && cmp_btm(*a))
	{
		*a = rotate_list(*a);
		ft_printf("%s\n", "ra");
		return (1);
	}
	return (0);
}

int	rotate_b(t_list **a, t_list **b, int forced)
{
	if (l_count(*b) > 1 && forced)
	{
		*b = rotate_list(*b);
		ft_printf("%s\n", "rb");
		return (1);
	}
	else if (!cmp_btm(*b))
	{
		*b = rotate_list(*b);
		ft_printf("%s\n", "rb");
		return (1);
	}
	return (0);
}

int	rev_rotate_a(t_list **a, t_list **b, int forced)
{
	if (l_count(*a) > 1 && forced)
	{
		*a = rev_rotate_list(*a);
		ft_printf("%s\n", "rra");
		return (1);
	}
	else if (l_count(*a) > 1 && cmp_btm(*a) && l_count(*b) > 1 && !cmp_btm(*b))
	{
		*a = rev_rotate_list (*a);
		*b = rev_rotate_list (*b);
		ft_printf("%s\n", "rrr");
		return (1);
	}
	else if (l_count(*a) > 1 && cmp_btm(*a))
	{
		*a = rev_rotate_list(*a);
		ft_printf("%s\n", "rra");
		return (1);
	}
	return (0);
}

int	rev_rotate_b(t_list **a, t_list **b, int forced)
{
	if (l_count(*b) > 1 && forced)
	{
		*b = rev_rotate_list(*b);
		ft_printf("%s\n", "rrb");
		return (1);
	}
	else if (l_count(*b) > 1 && !cmp_btm(*b))
	{
		*b = rev_rotate_list(*b);
		ft_printf("%s\n", "rrb");
		return (1);
	}
	return (0);
}
