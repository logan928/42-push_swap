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

#include <stdlib.h>

typedef struct s_list
{
	int		content;
	int		tail_count;
	struct s_list	*next;
} t_list;

t_list *cll_init(t_list *tail, int    f_value);
t_list *cll_add_at_end(t_list *tail, int node_value);
t_list *cll_add_at_begin(t_list *tail, int node_value);
t_list *cll_delete_last(t_list *tail);
void delete_list (t_list **tail);
t_list *cll_delete_top(t_list *tail);
int     *get_top_value(t_list *tail);
int     compare_top_two(t_list *tail);
int     compare_top_bottom(t_list *tail);
void delete_list (t_list **tail);


int     push_top(t_list **dest, t_list **src);
int     push_a (t_list **dest, t_list **src);
int     push_b (t_list **dest, t_list **src);
int     swap_a(t_list **a, t_list **b);
int     swap_b(t_list **a, t_list **b);
int     rotate_a(t_list **a, t_list **b, int forced);
int     rotate_b(t_list **a, t_list **b);
int     rev_rotate_a(t_list **a, t_list **b, int forced);
int     rev_rotate_b(t_list **a, t_list **b);

void    swap_start(t_list **tail);
t_list *rotate_list (t_list *tail);
t_list *rev_rotate_list(t_list *tail);
int     ccl_count(t_list *tail);
int search_value(t_list *tail, int num);
int     push_count(t_list *tail, int mul);
int    find_insert_pos(t_list *tail, int inst_val);
int find_min_max_pos(t_list *tail, int *min_pos, int *max_pos);

int     sort_algo(t_list **tail);
int     insert_back(t_list **a, t_list **b, int *a_min, int *a_max);

void print_list(t_list *tail); //remove

#endif
