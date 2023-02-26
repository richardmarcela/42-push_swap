/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:09:36 by marcela           #+#    #+#             */
/*   Updated: 2023/02/26 21:52:32 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_three(t_stack **stack_a)
{
	int	highest;

	if (is_sorted(*stack_a))
		return ;
	highest = highest_value_index(*stack_a);
	if ((*stack_a)->index == highest)
		ra(stack_a, 1);
	else if ((*stack_a)->next->index == highest)
		rra(stack_a, 1);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(*stack_a, 1);
}

int	highest_value_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}
