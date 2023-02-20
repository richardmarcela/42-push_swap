/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrichard <mrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:47:06 by mrichard          #+#    #+#             */
/*   Updated: 2023/02/20 21:05:58 by mrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

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
t_stack		*add_value_to_stack(int argc, char **argv);
int			stack_size(t_stack *stack);

//---Check_argv---

int			error_in_args(char **argv);
int			duplicated(char **argv);

//---Stacks---
t_stack		*add_value_to_stack(int argc, char **argv);
t_stack		*stack_new(int value);
void		add_bottom(t_stack **stack, t_stack *new);
t_stack		get_bottom(t_stack *stack);

#endif