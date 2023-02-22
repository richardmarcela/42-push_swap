/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrichard <mrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:37:33 by mrichard          #+#    #+#             */
/*   Updated: 2023/02/22 16:58:51 by mrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size)
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
	/* printf("INDEX DE 1: %d\n", stack_a->index);
	printf("INDEX DE 2: %d\n", stack_a->next->index);
	printf("INDEX DE 3: %d\n", stack_a->next->next->index);
	printf("INDEX DE 4: %d\n", stack_a->next->next->next->index);
	printf("INDEX DE 5: %d\n", stack_a->next->next->next->next->index);
	printf("INDEX DE 6: %d\n", stack_a->next->next->next->next->next->index);
	printf("INDEX DE 7: %d\n", stack_a->next->next->next->next->next->next->index); */
}