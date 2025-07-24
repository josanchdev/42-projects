/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:31:04 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/07 11:31:06 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

int	find_max_val(const t_stacks *stacks, const char x)
{
	int		max;
	size_t	i;
	int		*stack_x;
	size_t	size_x;

	max = INT_MIN;
	i = 0;
	if (x == 'a')
	{
		stack_x = stacks->stack_a;
		size_x = stacks->size_a;
	}
	else
	{
		stack_x = stacks->stack_b;
		size_x = stacks->size_b;
	}
	while (i < size_x)
	{
		if (stack_x[i] > max)
			max = stack_x[i];
		i++;
	}
	return (max);
}

int	find_min_val(const t_stacks *stacks, const char x)
{
	int		min;
	size_t	i;
	int		*stack_x;
	size_t	size_x;

	min = INT_MAX;
	i = 0;
	if (x == 'a')
	{
		stack_x = stacks->stack_a;
		size_x = stacks->size_a;
	}
	else
	{
		stack_x = stacks->stack_b;
		size_x = stacks->size_b;
	}
	while (i < size_x)
	{
		if (stack_x[i] < min)
			min = stack_x[i];
		i++;
	}
	return (min);
}

size_t	find_idx(const t_stacks *stacks, const char x, int value)
{
	size_t	i;
	int		*stack_x;
	size_t	size_x;

	i = 0;
	if (x == 'a')
	{
		stack_x = stacks->stack_a;
		size_x = stacks->size_a;
	}
	else
	{
		stack_x = stacks->stack_b;
		size_x = stacks->size_b;
	}
	while (i < size_x)
	{
		if (stack_x[i] == value)
			return (i);
		i++;
	}
	return (SIZE_MAX);
}
