/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:31:53 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/07 11:31:55 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"
#include "operations.h"

void	r_to_top(t_stacks *stacks, const size_t element_to_move)
{
	int		a_value;
	int		b_value;
	size_t	median_a;
	size_t	median_b;

	a_value = stacks->stack_a[element_to_move];
	b_value = stacks->stack_b[stacks->target_a[element_to_move]];
	median_a = stacks->size_a / 2;
	median_b = stacks->size_b / 2;
	if (stacks->size_a % 2 == 1)
		median_a += 1;
	if (stacks->size_b % 2 == 1)
		median_b += 1;
	if (element_to_move < median_a)
		while (stacks->stack_a[0] != a_value)
			ra(stacks);
	else
		while (stacks->stack_a[0] != a_value)
			rra(stacks);
	if (stacks->target_a[element_to_move] < median_b)
		while (stacks->stack_b[0] != b_value)
			rb(stacks);
	else
		while (stacks->stack_b[0] != b_value)
			rrb(stacks);
}

static void	rr_to_top(t_stacks *stacks, const size_t element_to_move)
{
	int	a_value;
	int	b_value;

	a_value = stacks->stack_a[element_to_move];
	b_value = stacks->stack_b[stacks->target_a[element_to_move]];
	while (stacks->stack_a[0] != a_value && stacks->stack_b[0] != b_value)
		rr(stacks);
	while (stacks->stack_a[0] != a_value)
		ra(stacks);
	while (stacks->stack_b[0] != b_value)
		rb(stacks);
}

static void	rrr_to_top(t_stacks *stacks, const size_t element_to_move)
{
	int	a_value;
	int	b_value;

	a_value = stacks->stack_a[element_to_move];
	b_value = stacks->stack_b[stacks->target_a[element_to_move]];
	while (stacks->stack_a[0] != a_value && stacks->stack_b[0] != b_value)
		rrr(stacks);
	while (stacks->stack_a[0] != a_value)
		rra(stacks);
	while (stacks->stack_b[0] != b_value)
		rrb(stacks);
}

void	move_cheapest_to_top(t_stacks *stacks)
{
	size_t	element_to_move;

	set_target_a(stacks);
	calc_cost(stacks);
	element_to_move = find_cheapest(stacks);
	if (stacks->rr[element_to_move])
		rr_to_top(stacks, element_to_move);
	else if (stacks->rrr[element_to_move])
		rrr_to_top(stacks, element_to_move);
	else
		r_to_top(stacks, element_to_move);
}

void	move_b_target_to_top(t_stacks *stacks)
{
	int		a_value;
	size_t	median_a;
	size_t	element_to_move;

	set_target_b(stacks);
	element_to_move = stacks->target_b;
	a_value = stacks->stack_a[element_to_move];
	median_a = stacks->size_a / 2;
	if (stacks->size_a % 2 == 1)
		median_a += 1;
	if (element_to_move < median_a)
		while (stacks->stack_a[0] != a_value)
			ra(stacks);
	else
		while (stacks->stack_a[0] != a_value)
			rra(stacks);
}
