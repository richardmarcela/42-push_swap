/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:54:35 by marcela           #+#    #+#             */
/*   Updated: 2023/02/23 19:50:46 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;
	int	i;

	size = stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < (size / 2))
	{
		if ((*stack_a)->index <= (size / 2))
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

void	do_last_shuffle(t_stack **stack_a)
{
	int	lowest_pos;
	int	size;

	lowest_pos = lowest_value_position(stack_a);
	size = stack_size(*stack_a);
	if (lowest_pos > (size / 2))
	{
		while (lowest_pos < size)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}

void    sort(t_stack **stack_a, t_stack **stack_b)
{
	push_to_b(stack_a, stack_b);
	tiny_three(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		do_last_shuffle(stack_a);
}