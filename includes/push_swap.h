/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:47:06 by mrichard          #+#    #+#             */
/*   Updated: 2023/02/26 18:28:46 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stddef.h>

/*
* Represents each element inserted in argv.	
* Value -> the number itself that came from argv.	 
* Index -> value added to each element in the stack 
* 	that starts from the biggest to the lowest.	 
* Pos -> as an index of ArrayList, starts from 0 to
*	the first element and increments until it exists.	 
* Target_pos -> position that an element needs to be 
*	placed to be in the right place.	 
* Cost_a -> represents the cost of getting to the 
*	right position in stack A.	 
* Cost_b -> represents the cost of getting the 
*	element to the top of the B stack.	 
* Next -> pointer to the next element.
*/
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

//---Utils--------------------------------------------------------------

//Returns the absolute value of a given number.
int			nb_abs(int nb);
//Returns the size of a stack..
int			stack_size(t_stack *stack);
//Checks if a stack is sorted. Returns 1 if it is, or 0 if it is not.
int			is_sorted(t_stack *stack);
//In case of any error found, free stacks and exits the program.
void		exit_error(t_stack **stack_a, t_stack **stack_b);
//Free stacks.
void		free_stack(t_stack **stack);

//---Check_argv---------------------------------------------------------

//Checks if there's any error in arguments such as letters.
int			error_in_args(int argc, char **argv);
//Checks if there's duplicated elements in arguments.
int			duplicated(char **argv);

//---Stacks-------------------------------------------------------------

//Adds an element to the bottom of a stack.
void		add_bottom(t_stack **stack, t_stack *new);
//Add numbers from argv to stack
t_stack		*add_value_to_stack(int argc, char **argv);
//Creates a stack elements with the provided value.
t_stack		*stack_new(int value);
//Returns the last element of the stack.
t_stack		*get_bottom(t_stack *stack);
//Returns the second to last element of the stack.
t_stack		*get_before_bottom(t_stack *stack);

//---Starting-----------------------------------------------------------

//Assigns an index to each value in stack a.
void		create_index(t_stack *stack_a, int stack_size);
//Chooses a sorting method depending on the number of values to be sorted.
void		check_sort(t_stack **stack_a, t_stack **stack_b, int size);

//--Tiny_sort------------------------------------------------------------

//Sorts a stack of 3 numbers in 2 or fewer moves.
void		tiny_three(t_stack **stack_a);
//Returns the highest position in a stack.
int			highest_value_index(t_stack *stack);

//---Position------------------------------------------------------------

/*
* Picks the best target position in stack A 
* for the given index of an element in stack B.
*/
int			get_target(t_stack **stack_a, int b_index,
				int target_index, int target_pos);
//Returns the lowest position in a stack.
int			lowest_value_position(t_stack **stack);
/*
* Assigns a position to each element of a stack 
* from top to bottom in ascending order.
*/
void		get_position(t_stack **stack);
//Assigns a target position in stack A to each element of stack A.
void		get_target_position(t_stack **stack_a, t_stack **stack_b);

//---Sort------------------------------------------------------------------

//Pushes all the elements of stack a into stack b, except the three last ones.
void		push_to_b(t_stack **stack_a, t_stack **stack_b);
//Sorting algorithm for a stack larger than 3.
void		sort(t_stack **stack_a, t_stack **stack_b);
/*
* After the bulk of the stack is sorted, 
* shifts stack a until the lowest value is at the top.
*/
void		do_last_shuffle(t_stack **stack_a);

//---Moves-----------------------------------------------------------------

//Rotates stack A until it is in position.
void		do_rotate_a(t_stack **stack_a, int *cost);
//Rotates stack B until it is in position.
void		do_rotate_b(t_stack **stack_b, int *cost);
/*
* Chooses which move to make to get the B stack 
* element to the correct position in stack A.
*/
void		move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);

//---Instructions_a--------------------------------------------------------

//Swap the first 2 elements at the top of stack a.
void		sa(t_stack *stack_a, int flag);
//Shift up all elements of stack a by 1.
void		ra(t_stack **stack_a, int flag);
//Shift down all elements of stack a by 1.
void		rra(t_stack **stack_a, int flag);
//Take the first element at the top of b and put it at the top of a.
void		pa(t_stack **stack_a, t_stack **stack_b, int flag);

//---Instructions_b---------------------------------------------------------

//Swap the first 2 elements at the top of stack b.
void		sb(t_stack *stack_b, int flag);
//Shift up all elements of stack b by 1.
void		rb(t_stack **stack_b, int flag);
//Shift down all elements of stack b by 1.
void		rrb(t_stack **stack_b, int flag);
//Take the first element at the top of a and put it at the top of b.
void		pb(t_stack **stack_a, t_stack **stack_b, int flag);

//---Instructions_both------------------------------------------------------

//sa and sb at the same time.
void		ss(t_stack **stack_a, t_stack **stack_b);
//ra and rb at the same time.
void		rr(t_stack **stack_a, t_stack **stack_b);
//rra and rrb at the same time.
void		rrr(t_stack **stack_a, t_stack **stack_b);

//---Cost-------------------------------------------------------------------

/*
* Calculates the cost of moving each element 
* of stack B into the correct position in stack A.
*/
void		get_cost(t_stack **stack_a, t_stack **stack_b);
/*
* Finds the element in stack B with the cheapest cost to move to stack A 
* and moves it to the correct position in stack A.
*/
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

#endif