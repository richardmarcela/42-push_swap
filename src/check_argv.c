/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrichard <mrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:55:24 by mrichard          #+#    #+#             */
/*   Updated: 2023/02/20 18:17:15 by mrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//confirma se so foram inseridos numeros
int	error_in_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[++i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
	}
	return (0);
}

//confirma se nao foram inseridos numeros duplicados
//retorna 1 se tiver, e 0 se nao tiver
int	duplicated(t_stack *stack_a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack_a->size)
	{
		j = i;
		while (++j < stack_a->size)
			if (stack_a->values[i] == stack_a->values[j])
				return (1);
	}
	return (0);
}