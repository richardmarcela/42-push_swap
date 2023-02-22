/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:20:59 by marcela           #+#    #+#             */
/*   Updated: 2023/02/22 21:22:15 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    get_position(t_stack **stack)
{
    t_stack *temp;
    int     i;

    temp = *stack;
    i = 0;
    while (temp)
    {
        temp->pos = i;
        temp = temp->next;
        i++;
    }
}