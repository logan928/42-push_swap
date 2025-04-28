/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:10:40 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/01 15:09:04 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		validate_list(int argc, char *argv[], t_list **tail);
int		validate_int(char *arg_str);
t_list	*init_cll(t_list **tail, int num);
int		parse_int(char *arg_str);

int	main(int argc, char *argv[])
{
	t_list	*tail;
	int		exit_code;

	exit_code = 1;
	if (argc < 2)
		return (1);
	tail = (t_list *)(malloc(sizeof(t_list)));
	if (!tail)
		return (1);
	tail -> next = NULL;
	algo_select(argc, argv, tail, &exit_code);
	/*
	if (validate_list(argc, argv, &tail) == 1)
	{
		if (check_sorted(&tail) != 1)
		{
			find_min_max_pos(tail);
			if (tail -> tail_count <= 3)
				sort_algo_3(&tail);
			else if (tail -> tail_count <= 5)
				sort_algo_5(&tail);
			else
				sort_algo(&tail);
		}
		exit_code = 0;
	}
	*/
	delete_list(&tail);
	return (exit_code);
}

int	validate_list(int argc, char *argv[], t_list **tail)
{
	int		i;
	int		num;

	i = 1;
	while (i < argc)
	{
		if (validate_int(argv[i]) == 0)
		{
			ft_printf ("Error\n");//Change this to handle error
			return (0);
		}
		num = parse_int(argv[i]);
		if (((*tail)-> next == NULL || (*tail)-> content != num) && search_value(*tail, num) == 0 ) // add tail = 1 conditions
		{
			*tail = init_cll(tail, num);
		}
		else
		{
			printf ("Error\n");//Change this to handle error
			return (0);
		}
		i++;
	}
	return (1);
}

int	validate_int(char *arg_str)
{
	int	i;

	i = 0;
	if ((arg_str[0] == '-' || arg_str[0] == '+' ) && (arg_str[1] != '\0'))
		i++;
	while (arg_str[i] != '\0')
	{
		if (arg_str[i] < '0' || arg_str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	parse_int(char *arg_str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (arg_str[0] == '-' || arg_str[0] == '+')
	{
		if (arg_str[0] == '-' )
			sign = sign * -1;
		i++;
	}
	while (arg_str[i] != '\0')
	{
		result = result * 10 + (arg_str[i] - '0');
		i++;
	}
	return (result * sign);
}

t_list	*init_cll(t_list **tail, int num)
{
	if ((*tail)-> next == NULL)
	{
		*tail = cll_init(*tail, num);
		return (*tail);
	}
	*tail = cll_add_at_end(*tail, num);
	if (!*tail)
		return (NULL);
	return (*tail);
}

/*
void print_list(t_list *tail)
{	t_list *temp;

	temp = tail -> next;
	if (!temp || !(temp -> content))
	{
		printf("null detected \n");
		return;
	}
	do
	{
		printf("%d ", temp -> content);
		temp = temp -> next;
	}while(temp -> next != tail -> next -> next);
	printf("\n");

}
*/
