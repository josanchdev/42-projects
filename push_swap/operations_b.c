/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:30:47 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/07 11:30:48 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

void	sb(t_stacks *stacks)
{
	int	temp;

	ft_printf("sb\n");
	if (stacks->size_b < 2)
		return ;
	temp = stacks->stack_b[1];
	stacks->stack_b[1] = stacks->stack_b[0];
	stacks->stack_b[0] = temp;
}

void	pb(t_stacks *stacks)
{
	size_t	i;

	i = stacks->size_b;
	ft_printf("pb\n");
	if (stacks->size_a == 0)
		return ;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = stacks->stack_a[0];
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->size_b++;
	stacks->size_a--;
}

void	rb(t_stacks *stacks)
{
	int		temp;
	size_t	i;

	i = 0;
	ft_printf("rb\n");
	if (stacks->size_b <= 1)
		return ;
	temp = stacks->stack_b[0];
	while (i < stacks->size_b - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[stacks->size_b - 1] = temp;
}

void	rrb(t_stacks *stacks)
{
	int		temp;
	size_t	i;

	i = stacks->size_b - 1;
	ft_printf("rrb\n");
	if (stacks->size_b <= 1)
		return ;
	temp = stacks->stack_b[stacks->size_b - 1];
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = temp;
}
