/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:47:06 by mrichard          #+#    #+#             */
/*   Updated: 2023/02/22 21:27:51 by marcela          ###   ########.fr       */
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

void		exit_error(t_stack *stack_a, t_stack *stack_b);
int			get_size(t_stack *stack);
void    	free_stack(t_stack **stack);
int			stack_size(t_stack *stack);
int			is_sorted(t_stack *stack);

//---Check_argv---

int			error_in_args(int argc, char **argv);
int			duplicated(char **argv);

//---Stacks---.

t_stack		*add_value_to_stack(char **argv);
t_stack		*stack_new(int value);
void		add_bottom(t_stack **stack, t_stack *new);
t_stack		*get_bottom(t_stack *stack);

//---Starting---

void	create_index(t_stack *stack_a, int stack_size);
void	check_sort(t_stack **stack_a, t_stack **stack_b, int size);

//--Tiny_sort---

void    tiny_three(t_stack **stack_a);
int highest_value_position(t_stack **stack);

//---Position---

void    get_position(t_stack **stack);

#endif