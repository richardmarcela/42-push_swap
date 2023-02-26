/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:20:59 by marcela           #+#    #+#             */
/*   Updated: 2023/02/26 18:30:22 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	lowest_value_position(t_stack **stack)
{
	t_stack	*temp;
	int		lowest_index;
	int		lowest_pos;

	temp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = temp->pos;
	while (temp)
	{
		if (temp->index < lowest_index)
		{
			lowest_index = temp->index;
			lowest_pos = temp->pos;
		}
		temp = temp->next;
	}	
	return (lowest_pos);
}

void	get_position(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

int	get_target(t_stack **stack_a, int b_index, int target_index, int target_pos)
{
	t_stack	*temp_a;

	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->index > b_index && temp_a->index < target_index)
		{
			target_index = temp_a->index;
			target_pos = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->index < target_index)
		{
			target_index = temp_a->index;
			target_pos = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;
	int		target_pos;

	temp_b = *stack_b;
	get_position(stack_a);
	get_position(stack_b);
	target_pos = 0;
	while (temp_b)
	{
		target_pos = get_target(stack_a, temp_b->index, INT_MAX, target_pos);
		temp_b->target_pos = target_pos;
		temp_b = temp_b->next;
	}
}
