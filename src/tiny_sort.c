/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:09:36 by marcela           #+#    #+#             */
/*   Updated: 2023/02/23 18:13:27 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    tiny_three(t_stack **stack_a)
{
    t_stack *temp;
    int highest;

    temp = *stack_a;
    highest = highest_value_position(stack_a);
    if (highest == 2 && temp->value > temp->next->value)
        ft_printf("sa\n");
    else if (highest == 0 && temp->next->value > temp->next->next->value)
        ft_printf("sa\nrra\n");
    else if (highest == 0 && temp->next->next->value > temp->next->value)
        ft_printf("ra\n");
    else if (highest == 1 && temp->next->next->value > temp->value)
        ft_printf("sa\nra\n");
    else if (highest == 1 && temp->value > temp->next->next->value)
        ft_printf("rra\n");
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