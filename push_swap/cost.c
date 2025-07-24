/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:28:27 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/07 11:28:28 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"

static void	calc_costs_r(t_stacks *stacks)
{
	size_t	i;
	size_t	median_a;
	size_t	median_b;

	i = 0;
	median_a = stacks->size_a / 2;
	median_b = stacks->size_b / 2;
	if (stacks->size_a % 2 == 1)
		median_a += 1;
	if (stacks->size_b % 2 == 1)
		median_b += 1;
	while (i < stacks->size_a)
	{
		if (i < median_a)
			stacks->cost[i] = i;
		else
			stacks->cost[i] = stacks->size_a - i;
		if (stacks->target_a[i] < median_b)
			stacks->cost[i] += stacks->target_a[i];
		else
			stacks->cost[i] += stacks->size_b - stacks->target_a[i];
		i++;
	}
}

static void	calc_costs_rr(t_stacks *s)
{
	size_t		i;
	size_t		rr_to_top;
	long long	rest_r_to_top;
	long long	nr_moves;

	i = 0;
	while (i < s->size_a)
	{
		if (i < s->target_a[i])
			rr_to_top = i;
		else
			rr_to_top = s->target_a[i];
		rest_r_to_top = i - s->target_a[i];
		if (rest_r_to_top < 0)
			rest_r_to_top *= -1;
		nr_moves = rr_to_top + rest_r_to_top;
		if (nr_moves < s->cost[i])
		{
			s->cost[i] = nr_moves;
			s->rr[i] = 1;
		}
		i++;
	}
}

static void	calc_costs_rrr(t_stacks *s)
{
	size_t		i;
	size_t		rrr_to_top;
	long long	rest_rr_to_top;
	long long	nr_moves;

	i = 0;
	while (i < s->size_a)
	{
		if ((s->size_a - i) < (s->size_b - s->target_a[i]))
			rrr_to_top = s->size_a - i;
		else
			rrr_to_top = s->size_b - s->target_a[i];
		rest_rr_to_top = (s->size_a - i) - (s->size_b - s->target_a[i]);
		if (rest_rr_to_top < 0)
			rest_rr_to_top *= -1;
		nr_moves = rrr_to_top + rest_rr_to_top;
		if (nr_moves < s->cost[i])
		{
			s->cost[i] = nr_moves;
			s->rr[i] = 0;
			s->rrr[i] = 1;
		}
		i++;
	}
}

void	calc_cost(t_stacks *stacks)
{
	size_t	i;

	i = 0;
	while (i < stacks->size_a)
	{
		stacks->rr[i] = 0;
		stacks->rrr[i] = 0;
		i++;
	}
	calc_costs_r(stacks);
	calc_costs_rr(stacks);
	calc_costs_rrr(stacks);
}

size_t	find_cheapest(const t_stacks *stacks)
{
	size_t	i;
	size_t	idx_cheapest;

	i = 0;
	idx_cheapest = 0;
	while (i < stacks->size_a)
	{
		if (stacks->cost[i] < stacks->cost[idx_cheapest])
			idx_cheapest = i;
		i++;
	}
	return (idx_cheapest);
}
