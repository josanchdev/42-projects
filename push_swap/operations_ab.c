/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:30:38 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/07 11:30:40 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

void	ss(t_stacks *stacks)
{
	int	temp;

	ft_printf("ss\n");
	if (stacks->size_a >= 2)
	{
		temp = stacks->stack_a[1];
		stacks->stack_a[1] = stacks->stack_a[0];
		stacks->stack_a[0] = temp;
	}
	if (stacks->size_b >= 2)
	{
		temp = stacks->stack_b[1];
		stacks->stack_b[1] = stacks->stack_b[0];
		stacks->stack_b[0] = temp;
	}
}

static void	rotate_stack(int *stack, size_t size)
{
	int		temp;
	size_t	i;

	if (size < 2)
		return ;
	temp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = temp;
}

void	rr(t_stacks *stacks)
{
	ft_printf("rr\n");
	rotate_stack(stacks->stack_a, stacks->size_a);
	rotate_stack(stacks->stack_b, stacks->size_b);
}

static void	r_rotate_stack(int *stack, size_t size)
{
	int		temp;
	size_t	i;

	if (size < 2)
		return ;
	temp = stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
}

void	rrr(t_stacks *stacks)
{
	ft_printf("rrr\n");
	r_rotate_stack(stacks->stack_a, stacks->size_a);
	r_rotate_stack(stacks->stack_b, stacks->size_b);
}
