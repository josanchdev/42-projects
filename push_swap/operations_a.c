/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:30:21 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/07 11:30:23 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

void	sa(t_stacks *stacks)
{
	int	temp;

	ft_printf("sa\n");
	if (stacks->size_a < 2)
		return ;
	temp = stacks->stack_a[1];
	stacks->stack_a[1] = stacks->stack_a[0];
	stacks->stack_a[0] = temp;
}

void	pa(t_stacks *stacks)
{
	size_t	i;

	ft_printf("pa\n");
	if (stacks->size_b == 0)
		return ;
	i = stacks->size_a;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = stacks->stack_b[0];
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->size_a++;
	stacks->size_b--;
}

void	ra(t_stacks *stacks)
{
	int		temp;
	size_t	i;

	ft_printf("ra\n");
	if (stacks->size_a <= 1)
		return ;
	i = 0;
	temp = stacks->stack_a[0];
	while (i < stacks->size_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[stacks->size_a - 1] = temp;
}

void	rra(t_stacks *stacks)
{
	int		temp;
	size_t	i;

	ft_printf("rra\n");
	if (stacks->size_a <= 1)
		return ;
	i = stacks->size_a - 1;
	temp = stacks->stack_a[stacks->size_a - 1];
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = temp;
}
