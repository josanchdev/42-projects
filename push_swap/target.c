/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:32:10 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/07 11:32:11 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"
#include "utils.h"

void	set_target_a(t_stacks *stk)
{
	size_t	i;
	size_t	j;
	size_t	target;

	i = 0;
	while (i < stk->size_a)
	{
		target = SIZE_MAX;
		j = 0;
		while (j < stk->size_b)
		{
			if (stk->stack_b[j] < stk->stack_a[i]
				&& (target == SIZE_MAX
					|| stk->stack_b[j] > stk->stack_b[target]))
				target = j;
			j++;
		}
		if (target == SIZE_MAX)
			stk->target_a[i] = find_idx(stk, 'b', find_max_val(stk, 'b'));
		else
			stk->target_a[i] = target;
		i++;
	}
}

void	set_target_b(t_stacks *stk)
{
	size_t	j;
	size_t	target;

	target = SIZE_MAX;
	j = 0;
	while (j < stk->size_a)
	{
		if (stk->stack_a[j] > stk->stack_b[0]
			&& (target == SIZE_MAX
				|| stk->stack_a[j] < stk->stack_a[target]))
			target = j;
		j++;
	}
	if (target == SIZE_MAX)
		stk->target_b = find_idx(stk, 'a', find_min_val(stk, 'a'));
	else
		stk->target_b = target;
}
