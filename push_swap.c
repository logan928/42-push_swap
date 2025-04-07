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
#include <stdio.h> // remove this at submissin. added only for debugging.

int     validate_list(int argc, char *argv[], t_list **tail);
int     validate_int(char *arg_str);
t_list  *init_cll(t_list **tail, int num);
void print_list(t_list *tail); 
int     parse_int(char *arg_str);

//handle int min and max
//handle after invalid string e.g. word at the end of the parameters.

int main(int argc, char *argv[])
{
	t_list	*tail;

	if (argc < 2)
		return (0);//Check err no
	tail = (t_list *)(malloc(sizeof(t_list)));
	tail -> next = NULL;
	if (!tail)
		return (0);//check err no
	if(!validate_list(argc, argv, &tail))
		return (0);

	int i= -1; //delete
	i = sort_algo(&tail);
//		printf("%d \n", i); 
//	printf("%d \n", tail -> content); 


//	print_list(tail);
	delete_list(&tail);
}

int	validate_list(int argc, char *argv[], t_list **tail)// change return type
{
	int	i;
	char	*arg_str;
	int	duplicate;

	i = 1;
	arg_str = "\0";
	duplicate = 0;
	while (i < argc)
	{
		arg_str = argv[i];
		i++;
		if (!validate_int(arg_str))
		{
			printf ("%d %d %s  Error\n",argc, i, arg_str);//Change this to handle error
			return (0);
		}
		int num = parse_int(arg_str);//norminette
		if (*tail) //can remove if wanted
			duplicate = search_value(*tail, num);
		if(!duplicate)
			*tail = init_cll(tail, num);
		else
		{
			printf ("%d %d %s  Error\n",argc, i, arg_str);//Change this to handle error
			return (0);
		}
	}
	return (1);//change ret type	
}

int	validate_int(char *arg_str)
{
	int	i;
	
	i= 0;
        if ((arg_str[0] == '-' || arg_str[0] == '+' ) && (arg_str[1] != '\0'))
		i++;

	while (arg_str[i] != '\0')
	{
		if(arg_str[i] < '0' ||  arg_str[i] > '9')
		{
			return (0);
		}
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
	if(arg_str[0] == '-' || arg_str[0] == '+')
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
	if((*tail) -> next == NULL)
	{
	       *tail = cll_init(*tail, num);
	       return (*tail);
	}	       
	*tail = cll_add_at_end(*tail, num);
	 if(!*tail)
       		return (NULL);
	return (*tail);       
}


void print_list(t_list *tail)//delete or comment when submitting. written only for debugging
{
	t_list *temp;

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

//validate_int doesn't handle when the string has a '\0' in the middle. 
