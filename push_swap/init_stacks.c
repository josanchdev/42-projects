/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:30:02 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/07 11:30:04 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

void	exit_free_stacks(int exit_code, const char *err_msg, t_stacks *s)
{
	free(s->stack_a);
	free(s->stack_b);
	free(s->target_a);
	free(s->cost);
	free(s->rr);
	free(s->rrr);
	free(s);
	ft_printf("%s", err_msg);
	exit(exit_code);
}

void	init_stacks(t_stacks *s, int *stack_a, size_t size)
{
	size_t	i;

	i = 0;
	s->size_a = size;
	s->size_b = 0;
	s->stack_a = ft_calloc(size, sizeof(int));
	s->stack_b = ft_calloc(size, sizeof(int));
	s->cost = ft_calloc(size, sizeof(int));
	s->target_a = ft_calloc(size, sizeof(size_t));
	s->target_b = SIZE_MAX;
	s->rr = ft_calloc(size, sizeof(int));
	s->rrr = ft_calloc(size, sizeof(int));
	if (!s->stack_a || !s->stack_b || !s->cost || !s->target_a || !s->rr
		|| !s->rrr)
		exit_free_stacks(EXIT_MALLOC_FAILURE, "Error\n", s);
	while (i < size)
	{
		s->stack_a[i] = stack_a[i];
		i++;
	}
	free(stack_a);
}

void	check_args_init_stacks(int argc, char **argv, t_stacks *stacks)
{
	int		*stack_a;
	size_t	size_stack_a;

	stack_a = check_and_get_args(argc, argv, stacks);
	size_stack_a = count_args(argc, argv);
	init_stacks(stacks, stack_a, size_stack_a);
}
