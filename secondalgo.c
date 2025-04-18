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
		int 	max_p;
		int 	min_p;
		int		max_b;
		int		min_b;
		int		rotate;
		int 	middle; 
		int		max_pa;
		int 	min_pa;
		int		max_a;
		int		min_a;


		tail_b = (t_list *)(malloc(sizeof(t_list)));
        if (!tail_b)
                return (0);
        tail_b -> next = NULL;
		find_min_max_pos(*tail);
		populate_b(tail, &tail_b);



//This is for pushing back from b where min or max depending on the shortest path is pushed back and then the newly pushed value needs to be positioned top or bottom. 
while (tail_b -> tail_count > 1)
{

		find_min_max_pos(tail_b);
		//print_list(tail_b);
		//print_list(*tail);
	
	rotate = rotate_count(tail_b -> tail_count, tail_b -> max_pos, tail_b -> min_pos);
	
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
	{
			success += rotate_a(tail, &tail_b, 1);
	}
	
	//print_list(tail_b);

}

	
if (tail_b -> tail_count == 1)
	push_a(tail, &tail_b);




//*****************this is the final rotation to get min value which is now in the middle to the top */	



//print_list(*tail);
	//print_list(tail_b);
	
	find_min_max_pos(*tail);
	min_position = search_value(*tail, (*tail) -> min);
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
			min_position--;
			if (min_position > 100)
				break;
		}
		
	}

	

//	printf("final list \n");
	//print_list(*tail);
	//print_list(tail_b);
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



