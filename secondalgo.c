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
		find_min_max_pos(*tail);
		populate_b(tail, &tail_b);
		//total_count = (*tail) -> tail_count;

	//	swap_a(tail, &tail_b);
	//	push_b(&tail_b, tail);




	
find_min_max_pos(tail_b);

/*
//This is for pushing back from b where min or max depending on the shortest path is pushed back and then the newly pushed value needs to be positioned top or bottom. 
while (tail_b -> tail_count > 1)
{

		find_min_max_pos(tail_b);
		//print_list(tail_b);
		//print_list(*tail);

	rotate = rotate_count(tail_b -> tail_count, tail_b -> max_pos, tail_b -> min_pos);
	//printf("rotate %d \n", rotate);
	
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
	int check_min = tail_b -> min; // change this value
	push_a(tail, &tail_b);

	if ((*tail) -> next -> content == check_min)
			success += rotate_a(tail, &tail_b, 1);

}
*/
	
/*if (tail_b -> tail_count == 1)
	push_a(tail, &tail_b);
	*/


//*****************this is the final rotation to get min value which is now in the middle to the top */	


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

	if (max_p <= min_p && max_p <= rev_max_p && max_p <= rev_min_p)
		return (max_p);
	else if (min_p <= max_p && min_p <= rev_max_p && min_p <= rev_min_p)
		return (min_p);
	else if (rev_max_p <= max_p && rev_max_p <= min_p && rev_max_p <= rev_min_p)
		return (rev_max_p * -1);
	else if (rev_min_p <= max_p && rev_min_p <= min_p && rev_min_p <= rev_max_p)
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
		int 	rotate_count;

do{
		//optimize_a(a, b);// check for successful changes and loop. work the middle value problem with forced rotation
		find_min_max_pos(*a);
        total_count = (*a) -> tail_count;
		rotate_count = get_rotate_count(*a);

		printf("rotate count: %d \n", rotate_count);
		if (rotate_count > 600)
		{
			print_list(*a);
			print_list(*b);

			printf("unusual\n");
			break;
		}
        //push =  push_count(*a, 1);
		
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
		/*if ((*a) -> next -> content < middle)
			push_b(b,a);
		else
			rotate_a(a, b, 1);
			*/

		if (rotate_count > 0)
		{
			while (rotate_count > 1)
			{
				rotate_a(a, b, 1);
				rotate_count--;
			}
		}
		else
		{
			rotate_count *= -1;
			while (rotate_count > -1)
			{
				rev_rotate_a(a, b, 1);
				rotate_count--;
			}
		}
		push_b(b, a);
		print_list(*a);
		print_list(*b);
		//find_min_max_pos(*a);

	//}while (total_count != push);

}while (total_count > 3);

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



