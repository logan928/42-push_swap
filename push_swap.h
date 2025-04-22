/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:33:03 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/04 15:19:21 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_list
{
	int				content;
	int				tail_count;
	long long int	total;
	int				min;
	int				max;
	int				min_pos;
	int				max_pos;
	int				check_val;
	int				half_total;
	struct s_list	*next;
}	t_list;

typedef struct min_max_values
{
	int min_pos;
	int max_pos;
	int min;
	int max;
	int avg;
	int	h_total;
	long long int below_avg_total;
	int below_avg_count;
	int	new_end;
	int	count;
	int	last_min_index;

}	t_limits;

typedef struct  check_vals
{
	int first_check_val;
	int	first_check_pos;
	int	last_check_val;
	int	last_check_pos;
} min_check_vals;


int		ft_printf(const char *format, ...);
t_list	*cll_init(t_list *tail, int f_value);
t_list	*cll_add_at_end(t_list *tail, int node_value);
t_list	*cll_add_at_begin(t_list *tail, int node_value);
t_list	*cll_delete_last(t_list *tail);
void	delete_list(t_list **tail);
t_list	*cll_delete_top(t_list *tail);
int		*get_top_value(t_list *tail);
int		compare_top_two(t_list *tail);
int		cmp_btm(t_list *tail);
void	delete_list(t_list **tail);
void	optimize_a(t_list **a, t_list **b);

int		push_top(t_list **dest, t_list **src);
int		push_a(t_list **dest, t_list **src);
int		push_b(t_list **dest, t_list **src);
int		swap_a(t_list **a, t_list **b);
int		swap_b(t_list **a, t_list **b);
int		rotate_a(t_list **a, t_list **b, int forced);
int		rotate_b(t_list **a, t_list **b, int forced);
int		rev_rotate_a(t_list **a, t_list **b, int forced);
int		rev_rotate_b(t_list **a, t_list **b, int forced);

void	swap_start(t_list **tail);
t_list	*rotate_list(t_list *tail);
t_list	*rev_rotate_list(t_list *tail);
int		l_count(t_list *tail);
int		search_value(t_list *tail, int num);
int		push_count(t_list *tail, int mul);
int		find_insert_pos(t_list *tail, int inst_val);
int		find_min_max_pos(t_list *tail);
int		get_rotate_count(t_list *list);
int		get_rev_rotate_count(t_list *list);
void	update_checks(min_check_vals *cv, t_list *tail, int count, int first_found);
void	update_check_vals(min_check_vals *cv, t_list *tail);

void		sort_algo(t_list **tail);
void	populate_b(t_list **a, t_list **b);
int		insert_back(t_list **a, t_list **b, int *a_min, int *a_max);

void	print_list(t_list *tail);

#endif
