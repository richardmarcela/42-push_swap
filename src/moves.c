/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:42:48 by marcela           #+#    #+#             */
/*   Updated: 2023/02/26 21:51:56 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate_a(t_stack **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(stack_a, 1);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(stack_a, 1);
			(*cost)++;
		}
	}
}

void	do_rotate_b(t_stack **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(stack_b, 1);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(stack_b, 1);
			(*cost)++;
		}
	}
}

void	move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	while (cost_a < 0 && cost_b < 0)
	{
		cost_a++;
		cost_b++;
		rrr(stack_a, stack_b);
	}
	while (cost_a > 0 && cost_b > 0)
	{
		cost_a--;
		cost_b--;
		rr(stack_a, stack_b);
	}
	do_rotate_a(stack_a, &cost_a);
	do_rotate_b(stack_b, &cost_b);
	pa(stack_a, stack_b, 1);
}
