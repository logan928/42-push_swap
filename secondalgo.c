#include <stdio.h>
#include "push_swap.h"


void optimize_a(t_list **a, t_list **b);
void populate_b(t_list **a, t_list **b);
void sequence_a(t_list **a, t_list **b);
void optimize_b(t_list **a, t_list **b);
int rotate_count(int total_count, int max_p, int min_p);


// if it is 3 numbers write a function that does 1. swap 2. rotate or rev_rotate depending on the position of the highest value. then loop. I believe this will work even without using teh second list for when the count is 4. 

int     sort_algo(t_list **tail)
{
        t_list  *tail_b;
        int     success;
        int     push;
        int     total_count;
		int		a_min;
		int		a_max;
		int		min_position;
		int max_p;
		int min_p;
		int		max_b;
		int		min_b;
		int		rotate;
		int middle; 
		int max_pa;
		int min_pa;
		int		max_a;
		int		min_a;


		tail_b = (t_list *)(malloc(sizeof(t_list)));
        if (!tail_b)
                return (0);
        tail_b -> next = NULL;


		printf("...%d", middle);
		populate_b(tail, &tail_b);
		total_count = (*tail) -> tail_count;

/*
	//make a only have 1 elements
	if (total_count > 1)
	{
		while (total_count >1)
		{
			success = push_b(&tail_b, tail);
			if (!success)
			{
				printf("another error \n");
				 return (0);
			}
			total_count--;
		}
		
	}
		
*/
	if ((*tail) -> tail_count > 0)// no need for this. since there is only one element. 
	{
		a_min = (*tail) -> next -> content;
		a_max = (*tail) -> content;
	}
	else
	{
		a_min = (*tail) -> content;
		a_max = (*tail) -> content;
	}
	//print_list(*tail);


//printf("tail_min1: %d tail_max: %d\n", a_min, a_max);// remove
	
	total_count = (tail_b) -> tail_count;
	//printf("tail_content ..%d \n", tail_b -> tail_count	);
	//printf(".....count b %d \n", total_count);




	min_p = 1;
	max_p = 1;




	print_list(tail_b);

	//printf("%d b count:\n", tail_b -> tail_count);
	
	//printf ("max...%d min....%d \n", max_p, min_p);

	//find min and push to a. 
//need to optimize this ... not checking the closest path for simplicity 

// the minimum value needs to be under the largest value
//######################################################################################3
	
find_min_max_pos(tail_b, &min_p, &max_p, &max_b, &min_b);


if (min_p < total_count - min_p)
{
	while (min_p > 1)
	{
		rotate_b(tail, &tail_b, 1);
		min_p--;
	}
}
else 
{
	while ((total_count - min_p) + 1 > 0)
	{
		rev_rotate_b(tail, &tail_b, 1);
		min_p++;
	}
	
}

success += push_a(tail, &tail_b);
	success += rotate_a(tail, &tail_b, 1);
print_list(tail_b);

while (tail_b -> tail_count > 1)
{
	find_min_max_pos(tail_b, &min_p, &max_p, &max_b, &min_b);


	rotate = rotate_count(total_count, max_p, min_p);


	if (rotate > 1)
	{
		while (rotate > 1)
		{
			rotate_b(tail, &tail_b, 1);
			rotate--;
		}
	}
	else
	{
		rotate *= -1;
		while(rotate + 1 > 0)
		{
			rev_rotate_b(tail, &tail_b, 1);
			rotate--;
		}
	}
	push_a(tail, &tail_b);
	if ((*tail) -> next -> content == min_b)
		success += rotate_a(tail, &tail_b, 1);

}
	
if (tail_b -> tail_count == 1)
	push_a(tail, &tail_b);




	//print_list(tail_b);
	
	/*
	
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

	*/
	print_list(*tail);
	delete_list(&tail_b);//position of delet_list and following delete tail needs to be checked.
        if(tail_b)
        {
                free(tail_b);
                tail_b = NULL;
        }
        return (success);

}

int rotate_count(int total_count, int max_p, int min_p)
{
	int rev_max_p;
	int rev_min_p;

	rev_max_p = total_count - max_p;
	rev_min_p = total_count - min_p;

	if (max_p < min_p && max_p < rev_max_p && max_p < rev_min_p)
		return (max_p);
	else if (min_p < max_p && min_p < rev_max_p && min_p < rev_min_p)
		return (min_p);
	else if (rev_max_p < max_p && rev_max_p < min_p && rev_max_p < rev_min_p)
		return (rev_max_p * -1);
	else if (rev_min_p < max_p && rev_min_p < min_p && rev_min_p < rev_max_p)
		return (rev_min_p * -1);
	else
		return (0); // what does this do??

}

void populate_b(t_list **a, t_list **b)
{
	int total_count;
	int push;
	int max_pa;
		int min_pa;
		int		max_a;
		int		min_a;
		double middle;
	//double mean;

do{
		//optimize_a(a, b);// check for successful changes and loop. work the middle value problem with forced rotation
		find_min_max_pos(*a, &min_pa, &max_pa, &max_a, &min_a);
        total_count = (*a) -> tail_count;
        push =  push_count(*a, 1);
		middle = (max_a + min_a)/2;
		//mean = get_mean(*a);
		//printf("...%lf\n", middle);

	/*
        if (push != total_count)
        {
        		int i = 0;
                while (push > 0)
                {
                        i = push_b (b, a);
						//optimize_b(a, b);
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
		*/
		if ((*a) -> next -> content < middle)
			push_b(b,a);
		else
			rotate_a(a, b, 1);

	//}while (total_count != push);
	print_list(*a);
}while (total_count > 3);

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
	do 
	{
		success = 0;
		first = (*a) -> next -> content;
		second = (*a) -> next -> next -> content;
		last = (*a) -> content;
		//printf("%d %d %d \n", first, second, last);
		success += swap_a(a, b);
		if (last < first || last < second)
		{
			//success += rev_rotate_a(a, b, 0);
		}
		
	}while (success != 0);
}

void optimize_b(t_list **a, t_list **b) // Think about it
{
	int success;
	int	first;
	int	second;
	int	last;

	success = 0;
	do 
	{
		success = 0;
		first = (*b) -> next -> content;
		second = (*b) -> next -> next -> content;
		last = (*b) -> content;
		success += swap_b(a, b);
		//if (last < first || last < second)
			success += rev_rotate_b(a, b, 0);
		
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
