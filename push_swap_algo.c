/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:40:11 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/03 19:28:10 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	local_operations(int top, int second, int last)
{
	int sequence;

	sequence = 0;
	
	return (sequence);
}

int	old_sort_algo(t_list **tail)
{
	t_list *tail_a;
	t_list	*tail_b;
	int	success;
	int	push;
	int	total_count;

	tail_b = (t_list *)(malloc(sizeof(t_list)));
	if (!tail_b)
		return (0);
	tail_b -> next = NULL;
	tail_a = *tail;

	success = 0;
do{
do{
	total_count = ccl_count(*tail);

	do {
		success = swap_a(tail, &tail_b);
		//success += rotate_a(tail, &tail_b);
		success += rev_rotate_a(tail, &tail_b, 0);
	//	print_list(*tail);
	}
	while (success != 0);

	push =  push_count(*tail, 1);
//	printf("total vs push %d..%d \n", total_count, push);//remove
	if (push != total_count)
	{
		int i = 0;
		while (push > 1)
		{
			i = push_b (&tail_b, tail);
			if (i == 0)
			{
				printf("isomething went wrong %d\n", i);//remove
				break;
			}
			success += i;
			if ((*tail) -> next -> content > (*tail) -> content)
				break; 
			push--;
		}
	//		print_list(*tail);//remove
	//		print_list(tail_b);//remove

	}
}while (success !=0);

push = 0;
success = 0;
//------------------------operations in b starts here...................
//
do{
        total_count = ccl_count(tail_b);
	printf("%d\n", total_count);

        do {
                success = swap_b(tail, &tail_b);
                //success += rotate_b(tail, &tail_b);
                success += rev_rotate_b(tail, &tail_b);
          //      print_list(tail_b);
	//	print_list(*tail);
        }
        while (success != 0);
        
        push =  push_count(tail_b, -1);
        //printf("total vs push in b %d..%d \n", total_count, push);//remove
        if (push != total_count)
        {       
                int i = 0;
                while (push > 1)
                {
                        i = push_a (tail, &tail_b);
                        if (i == 0)
                        {
                                printf("isomething went wrong %d\n", i);//remove
                                break;
                        }
                        success += i;
                        if ((tail_b) -> next -> content < (tail_b) -> content)
                                break;
                        push--;
                }
          //              print_list(*tail);//remove
           //             print_list(tail_b);//remove

        }
}while (success !=0);

int j = push_count(tail_b, -1);

//printf("apush %d...atot %d...bpush %d, btot %d \n", push_count(*tail, 1), ccl_count(*tail) , j, ccl_count (tail_b));

if((push_count(*tail, 1) == ccl_count(*tail)) && (push_count(tail_b, -1) == ccl_count(tail_b)))
{
		while(j > 0)
		{
		//	printf("inside ...\n");
			j = push_a(tail, &tail_b);
			j--;
		}
}

if (push_count(*tail, 1) == ccl_count(*tail) && ccl_count (tail_b)==0)
{
//	printf("....\n");
	break;
}
}while (push_count(*tail, 1) != ccl_count(*tail) || ccl_count (tail_b)!=0);

//---------------------------------operataions in b stops .........................
//	printf("%d %d %d \n",(*tail) -> content, (*tail) -> next -> content, (*tail) -> next -> next -> content);//use the logic for rotate vs rev_rotaet

	delete_list(&tail_b);//position of delet_list and following delete tail needs to be checked. 
	if(tail_b)
	{
		free(tail_b);
		tail_b = NULL;
	}
	return (success);

}
