/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:37:33 by mrichard          #+#    #+#             */
/*   Updated: 2023/02/26 21:52:32 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest)
			highest->index = stack_size;
	}
}

void	check_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && !is_sorted(*stack_a))
		sa(*stack_a, 1);
	else if (size == 3)
		tiny_three(stack_a);
	else if (size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}
