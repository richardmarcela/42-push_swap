/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:24:43 by mrichard          #+#    #+#             */
/*   Updated: 2023/02/26 18:38:33 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	if (error_in_args(argc, argv) || duplicated(argv))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = add_value_to_stack(argc, argv);
	size = stack_size(stack_a);
	create_index(stack_a, size + 1);
	check_sort(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
