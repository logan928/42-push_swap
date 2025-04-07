#include <stdio.h>
#include "push_swap.h"


void optimize_a(t_list **a, t_list **b);
void populate_b(t_list **a, t_list **b);
void sequence_a(t_list **a, t_list **b);


// if it is 3 numbers write a function that does 1. swap 2. rotate or rev_rotate depending on the position of the highest value. then loop. I believe this will work even without using teh second list for when the count is 4. 

int     sort_algo(t_list **tail)
{
        t_list  *tail_b;
        int     success;
        int     push;
        int     total_count;
		int	a_min;
		int	a_max;
		int		min_position;

        tail_b = (t_list *)(malloc(sizeof(t_list)));
        if (!tail_b)
                return (0);
        tail_b -> next = NULL;

	populate_b(tail, &tail_b);
	if ((*tail) -> tail_count > 0)
	{
		a_min = (*tail) -> next -> content;
		a_max = (*tail) -> content;
	}
	else
	{
		a_min = (*tail) -> content;
		a_max = (*tail) -> content;
	}
	
	//printf("tail_min1: %d tail_max: %d\n", a_min, a_max);// remove
	
	total_count = (tail_b) -> tail_count;
	//printf(".....count b %d \n", total_count);
	
	while (total_count > 0)
	{
		insert_back(tail, &tail_b, &a_min, &a_max); // This needs to be reworked
		//print_list(*tail);
		total_count--;	
		//printf("tail_min1: %d tail_max: %d\n", a_min, a_max);// remove
	}
	min_position = search_value(*tail, a_min);
	//printf("%d..\n", a_min);

	total_count = (*tail) -> tail_count;
	if (min_position > (total_count/2))
	{
		while (total_count - min_position + 1)
		{
			rev_rotate_a(tail, &tail_b, 1);
			min_position++;
		}
	}
	else
	{
		while (min_position -1 > 0)
		{
			rotate_a(tail, &tail_b, 1);
			min_position++;
		}
		
	}
//print_list(*tail);
	delete_list(&tail_b);//position of delet_list and following delete tail needs to be checked.
        if(tail_b)
        {
                free(tail_b);
                tail_b = NULL;
        }
        return (success);

}


void populate_b(t_list **a, t_list **b)
{
	int total_count;
	int push;

do{
		optimize_a(a, b);// check for successful changes and loop. work the middle value problem with forced rotation
        total_count = (*a) -> tail_count;
        push =  push_count(*a, 1);
	
        if (push != total_count)
        {
                int i = 0;
                while (push > 0)
                {
                        i = push_b (b, a);
			//optimize_b (a, b); this will not optimize  to counter cases of 3, 4, 5
			//Opportunity to reduce instructions by optimising b after each push. 
			//only optimize not the exact insertion. 
                        if (i == 0)
                        {
                                printf("isomething went wrong %d\n", i);//remove
                                break;
                        }
                  
                        if ((*a) -> next -> content > (*a) -> content)
                                break;
                        push--;
               	}
        }
}while (total_count != push);

}

int	insert_back(t_list **a, t_list **b, int *a_min, int *a_max)//WIP 03rd April
{
	int position;
	int	top_num;
	int	size_a;
	int	success;

	size_a = (*a) -> tail_count;
	top_num = (*b) -> next -> content;
	//printf("top of b...%d...top of a...%d \n", top_num, (*a) -> next -> content);
	if(top_num < (*a) -> next -> content && top_num > (*a) -> content)
	{
		if (top_num < *a_min)
			*a_min = top_num;
		else if (top_num > *a_max)
			*a_max = top_num;
		//printf(".......inside...\n");
	}
	else if (top_num < *a_min)
	{
		//printf("second ...\n");
		position = search_value(*a, *a_min); //check whether it is already the 
		if (position < (size_a/2))
		{
			while (position > 1)
			{
				success = rotate_a(a, b, 1);//optimize can achieve with a logical OR
				position--;
			}
		}
		else 
		{
			while ((size_a - position) + 1 > 0)
			{
				success = rev_rotate_a(a, b, 1);
				position++;
			}
		}		
		*a_min = top_num;
		//return (position);//write the rotaing code
	}
	else if (top_num > *a_max)
	{
		//printf("third ...\n");
		position = search_value(*a, top_num);
		if (position < (size_a/2))
		{
			while (position > 0)
			{
				success = rotate_a(a, b, 1);
				position--;
			}
		}
		else
		{
			while ((size_a - position) > 0)
			{
				success = rev_rotate_a(a, b, 1);
				position++;
			}
		}
		*a_max = top_num;
		//return (*a);
	}
	else
	{
		//printf("fourth ...\n");
		position = find_insert_pos(*a, top_num);
		//return (position);
		//printf("size_a ....%d...inserting at..%d \n\n",size_a, position);
		if (position < (size_a/2))
                {
                        while (position > 1)
                        {
                                success = rotate_a(a, b, 1);
                                position--;
                        }
                }
                else
                {
                        while ((1 + size_a - position) > 0)
                        {
                                success = rev_rotate_a(a, b, 1);
                                position++;
                        }
                }

                //return (*a);

	}

	//print_list(*a);
	return (push_a(a, b));		

}



void optimize_a(t_list **a, t_list **b)
{
	int success;
	int	first;
	int	second;
	int	last;

	success = 0;
	first = (*a) -> next -> content;
	second = (*a) -> next -> next -> content;
	last = (*a) -> content;
	
	//all branches include a swap. might as well move it to the top

	//printf("%d %d %d \n", first, second, last);
	do 
	{
		success = 0;
		if (last > first && last > second)
			success += swap_a(a, b);
		else if (last < first && last < second)
		{
			success += swap_a(a, b);
			success += rev_rotate_a(a, b, 0);	
		}
		else if (first > second && first > last)
		{
			success += swap_a(a, b); //redo force rev_rotate and then swap. 
			success += rev_rotate_a(a, b, 0);
		}
		else 
		{
			success += swap_a(a, b);
			success += rev_rotate_a(a, b, 0);
		}
	}while (success != 0);
}

/*
 
	*tail = cll_add_at_end(*tail, 57);
        total_count = ccl_count(*tail);
	printf("%d....tail count%d\n", total_count, (*tail) -> tail_count);

		*tail = cll_add_at_end(*tail, 57);
        total_count = ccl_count(*tail);
	printf("%d....tail count%d\n", total_count, (*tail) -> tail_count);

	*tail = cll_add_at_end(*tail, -8);
        total_count = ccl_count(*tail);
	printf("%d....tail count%d\n", total_count, (*tail) -> tail_count);


	*tail = cll_add_at_begin(*tail, 1);
        total_count = ccl_count(*tail);
	printf("%d....tail count%d\n", total_count, (*tail) -> tail_count);


	*tail = cll_add_at_begin(*tail, 0);
        total_count = ccl_count(*tail);
	printf("%d....tail count%d\n", total_count, (*tail) -> tail_count);

	*tail = cll_delete_last(*tail);
        total_count = ccl_count(*tail);
	printf("%d....tail count%d\n", total_count, (*tail) -> tail_count);
        
	
	*tail = cll_delete_top(*tail);
        total_count = ccl_count(*tail);
	printf("%d....tail count%d\n", total_count, (*tail) -> tail_count);
 */

 /*      
        rotate_a(a,b,1 );
        printf("third last %d\n", search_value(*a, 0));
        rotate_a(a, b, 1);
        printf("third last %d\n", search_value(*a, 0));
        rotate_a(a, b, 1);
        printf("third last %d\n", search_value(*a, 0));
        rotate_a(a, b, 1);
        printf("third last %d\n", search_value(*a, 0));
        rotate_a(a, b, 1);
        printf("third last %d\n", search_value(*a, 0));
        rotate_a(a, b, 1);
        printf("third last %d\n", search_value(*a, 0));
        rotate_a(a, b, 1);
        printf("third last %d\n", search_value(*a, 0));
        rotate_a(a, b, 1);
        printf("third last %d\n", search_value(*a, 0));


        printf("------------reversing\n");

      rev_rotate_a(a, b, 1);
        printf("third last %d\n", search_value(*a, 0));
        rev_rotate_a(a, b, 1);
        printf("third last %d\n", search_value(*a, 0));
        rev_rotate_a(a, b, 1);
        printf("third last %d\n", search_value(*a, 0));
        rev_rotate_a(a, b, 1);
        printf("third last %d\n", search_value(*a, 0));
        rev_rotate_a(a, b, 1);
        printf("third last %d\n", search_value(*a, 0));
        rev_rotate_a(a, b, 1);
        printf("third last %d\n", search_value(*a, 0));
        rev_rotate_a(a, b, 1);
        printf("third last %d\n", search_value(*a, 0));
        rev_rotate_a(a, b, 1);
        printf("third last %d\n", search_value(*a, 0));
*/

/*      find_insert_pos(*a, 14);
        find_insert_pos(*a, 20);
        find_insert_pos(*a, 25);
        find_insert_pos(*a, 2);
        find_insert_pos(*a, -1);
*/
/*      printf("first %d\n", search_value(*a, 13));
        printf("second %d\n", search_value(*a, 15));
        printf("third %d\n", search_value(*a, 19));
        printf("third last %d\n", search_value(*a, 0));
        printf("second last%d\n", search_value(*a,1));
        printf(" last %d\n", search_value(*a, 10));
        printf("not exist  %d\n", search_value(*a,2) );
*/
