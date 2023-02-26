/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:56:15 by marcela           #+#    #+#             */
/*   Updated: 2023/02/26 21:51:45 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, int flag)
{
	int	temp;

	if (!stack_a || !stack_a->next)
		return ;
	temp = stack_a->value;
	stack_a->value = stack_a->next->value;
	stack_a->next->value = temp;
	temp = stack_a->index;
	stack_a->index = stack_a->next->index;
	stack_a->next->index = temp;
	if (flag)
		ft_printf("sa\n");
}

void	ra(t_stack **stack_a, int flag)
{
	t_stack	*temp;
	t_stack	*tail;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	tail = get_bottom(*stack_a);
	temp->next = NULL;
	tail->next = temp;
	if (flag)
		ft_printf("ra\n");
}

void	rra(t_stack **stack_a, int flag)
{
	t_stack	*temp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_bottom(*stack_a);
	before_tail = get_before_bottom(*stack_a);
	temp = *stack_a;
	*stack_a = tail;
	(*stack_a)->next = temp;
	before_tail->next = NULL;
	if (flag)
		ft_printf("rra\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b, int flag)
{
	t_stack	*temp;

	if (*stack_b == NULL)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = temp;
	if (flag)
		ft_printf("pa\n");
}
