/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:47:06 by mrichard          #+#    #+#             */
/*   Updated: 2023/02/23 18:03:11 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stddef.h>

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

//---Utils---

void	exit_error(t_stack **stack_a, t_stack **stack_b);
void    	free_stack(t_stack **stack);
int			stack_size(t_stack *stack);
int			is_sorted(t_stack *stack);
int	nb_abs(int nb);

//---Check_argv---

int			error_in_args(int argc, char **argv);
int			duplicated(char **argv);

//---Stacks---.

t_stack	*add_value_to_stack(int argc, char **argv);
t_stack		*stack_new(int value);
void		add_bottom(t_stack **stack, t_stack *new);
t_stack		*get_bottom(t_stack *stack);
t_stack	*get_before_bottom(t_stack *stack);

//---Starting---

void		create_index(t_stack *stack_a, int stack_size);
void		check_sort(t_stack **stack_a, t_stack **stack_b, int size);

//--Tiny_sort---

void    	tiny_three(t_stack **stack_a);
int			highest_value_position(t_stack **stack);

//---Position---

void    	get_position(t_stack **stack);
int get_target(t_stack **stack_a, int b_index, int target_index, int target_pos);
void    get_target_position(t_stack **stack_a, t_stack **stack_b);
int	lowest_value_position(t_stack **stack);

//---Sort---

void	push_to_b(t_stack **stack_a, t_stack **stack_b);
void    sort(t_stack **stack_a, t_stack **stack_b);
void	do_last_shuffle(t_stack **stack_a);

//---Moves---
void    do_rotate_a(t_stack **stack_a, int *cost);
void    do_rotate_b(t_stack **stack_b, int *cost);
void    move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);


//---Instructions_a---

void    sa(t_stack *stack_a);
void    ra(t_stack **stack_a);
void    rra(t_stack **stack_a);
void	pa(t_stack **stack_a, t_stack **stack_b);

//---Instructions_b---

void    sb(t_stack *stack_b);
void    rb(t_stack **stack_b);
void    rrb(t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

//---Instructions_both---

void    ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//---Cost---

void    get_cost(t_stack **stack_a, t_stack **stack_b);
void    do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

#endif