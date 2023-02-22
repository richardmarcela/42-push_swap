/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrichard <mrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:55:24 by mrichard          #+#    #+#             */
/*   Updated: 2023/02/22 16:31:34 by mrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//confirma se so foram inseridos numeros
int	error_in_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
			j = 0;
		else
			j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
		}
	}
	return (0);
}

int	nbr_cmp(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = i;
	if (s1[i] == '+')
		i++;
	else
		if (s2[j] == '+')
			j++;
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

//confirma se nao foram inseridos numeros duplicados
//retorna 1 se tiver, e 0 se nao tiver
int	duplicated(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		j = i - 1;
		while (argv[++j])
			if (j != i && !nbr_cmp(argv[i], argv[j]))
				return (1);
	}
	return (0);
}
