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
int		parse_int(char *arg_str, t_list **tail);

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
	algo_select(argc, argv, &tail, &exit_code);
	delete_list(&tail);
	if (tail)
	{
		free(tail);
		tail = NULL;
	}
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
			write(2, "Error\n", 6);
			return (delete_list(tail), 0);
		}
		num = parse_int(argv[i], tail);
		if (((*tail)-> next == NULL || (*tail)-> content != num) && \
			search_value(*tail, num) == 0)
			*tail = init_cll(tail, num);
		else
		{
			write(2, "Error\n", 6);
			return (delete_list(tail), 0);
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

int	parse_int(char *arg_str, t_list **tail)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (arg_str[0] == '-' || arg_str[0] == '+')
	{
		if (arg_str[0] == '-' )
			sign = sign * -1;
		i++;
	}
	while (arg_str[i] != '\0')
	{
		res = res * 10 + (arg_str[i] - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && (-res) < INT_MIN))
		{
			write(2, "Error\n", 6);
			delete_list(tail);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (res * sign);
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
