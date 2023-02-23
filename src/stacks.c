/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:16:50 by mrichard          #+#    #+#             */
/*   Updated: 2023/02/23 18:03:25 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;
	
	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0; //pq comeca em 1
	new->pos = -1; //pq comeca em 0
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

t_stack	*get_bottom(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*get_before_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

void	add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_bottom(*stack);
	tail->next = new;
}

t_stack	*add_value_to_stack(int argc, char **argv)
{
	t_stack *stack_a;
	int	n;
	int	i;

	stack_a = NULL;
	n = 0;
	i = -1;
	while (++i < argc)
	{
		n = ft_atoi(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_new((int)n);
		else
			add_bottom(&stack_a, stack_new(n));
	}
	return (stack_a);
}

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}