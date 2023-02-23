/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:42:48 by marcela           #+#    #+#             */
/*   Updated: 2023/02/23 18:16:24 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    do_rotate_a(t_stack **stack_a, int *cost)
{
    while (*cost)
    {
        if (*cost > 0)
        {
            ra(stack_a);
            (*cost)--;
        }
        else if (*cost < 0)
        {
            rra(stack_a);
            (*cost)++;
        }
    }
}

void    do_rotate_b(t_stack **stack_b, int *cost)
{
    while (*cost)
    {
        if (*cost > 0)
        {
            rb(stack_b);
            (*cost)--;
        }
        else if (*cost < 0)
        {
            rrb(stack_b);
            (*cost)++;
        }
    }
}

void    move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
    while (cost_a < 0 && cost_b < 0)
    {
        cost_a++;
        cost_b++;
        rrr(stack_a, stack_b);
    }
    while (cost_a > 0 && cost_b > 0)
    {
        cost_a--;
        cost_b--;
        rr(stack_a, stack_b);
    }
    do_rotate_a(stack_a, &cost_a);
    do_rotate_b(stack_b, &cost_b);
    pa(stack_a, stack_b);
}