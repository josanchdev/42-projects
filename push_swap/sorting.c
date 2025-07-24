/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:31:32 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/07 11:31:33 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"
#include "operations.h"
#include "utils.h"

bool	is_sorted(const t_stacks *stacks)
{
	size_t	i;

	i = 0;
	while (i < stacks->size_a - 1)
	{
		if (stacks->stack_a[i] > stacks->stack_a[i + 1])
			return (false);
		i++;
	}
	return (true);
}

bool	is_circularly_sorted(const t_stacks *stacks)
{
	size_t	min_index;
	size_t	i;
	size_t	size_a;

	min_index = find_idx(stacks, 'a', find_min_val(stacks, 'a'));
	i = min_index;
	size_a = stacks->size_a;
	while (i != (min_index - 1))
	{
		if (stacks->stack_a[i % size_a] > stacks->stack_a[(i + 1) % size_a])
			return (false);
		i = (i + 1) % size_a;
	}
	return (true);
}

void	sort_three(t_stacks *stacks)
{
	int	max_value;

	if (stacks->size_a > 3)
		return ;
	max_value = find_max_val(stacks, 'a');
	if (stacks->stack_a[0] == max_value)
		ra(stacks);
	else if (stacks->stack_a[1] == max_value)
		rra(stacks);
	if (stacks->stack_a[0] > stacks->stack_a[1])
		sa(stacks);
}

void	sort_stack(t_stacks *stacks)
{
	int		min_value;
	size_t	idx_of_min_val;
	size_t	median_a;

	min_value = find_min_val(stacks, 'a');
	idx_of_min_val = find_idx(stacks, 'a', min_value);
	median_a = stacks->size_a / 2;
	if (stacks->size_a % 2 == 1)
		median_a += 1;
	if (idx_of_min_val < median_a)
		while (stacks->stack_a[0] != min_value)
			ra(stacks);
	else
		while (stacks->stack_a[0] != min_value)
			rra(stacks);
}

void	sort_more_than_three(t_stacks *stacks)
{
	if (stacks->size_a > 3)
		pb(stacks);
	if (is_circularly_sorted(stacks))
		sort_stack(stacks);
	if (stacks->size_a > 3 && !(is_sorted(stacks)))
		pb(stacks);
	if (is_circularly_sorted(stacks))
		sort_stack(stacks);
	while (stacks->size_a > 3 && !(is_sorted(stacks)))
	{
		move_cheapest_to_top(stacks);
		pb(stacks);
		if (is_circularly_sorted(stacks))
			sort_stack(stacks);
	}
	sort_three(stacks);
	while (stacks->size_b)
	{
		move_b_target_to_top(stacks);
		pa(stacks);
	}
	sort_stack(stacks);
}
