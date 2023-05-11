/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:03:57 by ael-malt          #+#    #+#             */
/*   Updated: 2023/05/04 17:14:34 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/include/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// Moves
	// swap
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);
	// push
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
	// rotate
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);
	// reverse rotate
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

// Cost
void	get_cost(t_stack **stack_a, t_stack **stack_b);
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

// Do Move
void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);

// Input check
int		input_check(char **argv);

// Position
int		get_lowest_index_pos(t_stack **stack);
void	get_target_position(t_stack **stack_a, t_stack **stack_b);

// Stack
t_stack	*get_before_last_stack(t_stack *stack);
t_stack	*get_last_stack(t_stack *stack);
t_stack	*new_stack(int value);
void	add_to_bottom_of_stack(t_stack **stack, t_stack *new);
int		get_stack_size(t_stack *stack);

// Sort
void	tiny_sort(t_stack **stack_a);
void	sort(t_stack **stack_a, t_stack **stack_b);

// Utils
void	free_stack(t_stack **stack);
void	exit_error(t_stack **stack_a, t_stack **stack_b);
t_stack	*fill_stack(int argc, char **argv);
void	assign_index(t_stack *stack_a, int stack_size);
int		is_sorted(t_stack *stack);

#endif
