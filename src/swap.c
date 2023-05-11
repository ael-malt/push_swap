/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:45:37 by ael-malt          #+#    #+#             */
/*   Updated: 2023/05/04 16:41:41 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack *stack)
{
	int		tmp;
	t_stack	*next;

	next = stack->next;
	if (stack == NULL || next == NULL)
		return ;
	tmp = stack->value;
	stack->value = next->value;
	next->value = tmp;
	tmp = stack->index;
	stack->index = next->index;
	next->index = tmp;
}

void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_printf("sa\n");
}

void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_printf("sb\n");
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_printf("ss\n");
}
