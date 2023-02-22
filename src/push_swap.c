/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:24:43 by mrichard          #+#    #+#             */
/*   Updated: 2023/02/22 21:26:59 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
	
	stack_b = NULL;
	stack_a = add_value_to_stack(argv);
	size = stack_size(stack_a);
	if (error_in_args(argc, argv) || argc < 2 || duplicated(argv))
		exit_error(stack_a, stack_b);
	create_index(stack_a, size + 1);
	if (!is_sorted(stack_a))
		check_sort(&stack_a, &stack_b, size);
	/*free_stack(&stack_a);
	free_stack(&stack_b); */
}