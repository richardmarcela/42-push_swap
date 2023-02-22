/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrichard <mrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:24:43 by mrichard          #+#    #+#             */
/*   Updated: 2023/02/22 16:45:13 by mrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
	
	stack_b = NULL;
	stack_a = add_value_to_stack(argv);
	size = stack_size(stack_a);
	if (error_in_args(argv) || argc < 2 || duplicated(argv))
		exit_error(stack_a, stack_b);
	create_index(stack_a, size);
	/*free_stack(&stack_a);
	free_stack(&stack_b); */
}