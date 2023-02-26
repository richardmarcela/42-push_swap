/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:57:17 by marcela           #+#    #+#             */
/*   Updated: 2023/02/26 18:41:29 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_stack *stack_b, int flag)
{
	int	temp;

	if (!stack_b || !stack_b->next)
		return ;
	temp = stack_b->value;
	stack_b->value = stack_b->next->value;
	stack_b->next->value = temp;
	temp = stack_b->index;
	stack_b->index = stack_b->next->index;
	stack_b->next->index = temp;
	if (flag)
		ft_printf("sb\n");
}

void	rb(t_stack **stack_b, int flag)
{
	t_stack	*temp;
	t_stack	*tail;

	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	tail = get_bottom(*stack_b);
	temp->next = NULL;
	tail->next = temp;
	if (flag)
		ft_printf("rb\n");
}

void	rrb(t_stack **stack_b, int flag)
{
	t_stack	*temp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_bottom(*stack_b);
	before_tail = get_before_bottom(*stack_b);
	temp = *stack_b;
	*stack_b = tail;
	(*stack_b)->next = temp;
	before_tail->next = NULL;
	if (flag)
		ft_printf("rrb\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b, int flag)
{
	t_stack	*temp;

	if (*stack_a == NULL)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = temp;
	if (flag)
		ft_printf("pb\n");
}
