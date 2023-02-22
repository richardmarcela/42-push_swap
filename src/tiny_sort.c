/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:09:36 by marcela           #+#    #+#             */
/*   Updated: 2023/02/22 21:30:10 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    tiny_three(t_stack **stack_a)
{
    int highest;

    highest = highest_value_position(stack_a);
    printf("%d\n", highest);
}

int highest_value_position(t_stack **stack)
{
    t_stack *temp;
    int highest_pos;
    int highest_index;

    temp = *stack;
    highest_index = temp->index;
    get_position(stack);
    highest_pos = temp->pos;
    while (temp)
    {
        if (temp->index > highest_index)
        {
            highest_index = temp->index;
            highest_pos = temp->pos;
        }
        temp = temp->next;
    }
    return (highest_pos);
}