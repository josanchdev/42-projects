/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:30:55 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/07 11:30:59 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include "sorting.h"
#include "operations.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
	{
		ft_printf("Error\n");
		exit(EXIT_MALLOC_FAILURE);
	}
	check_args_init_stacks(argc, argv, stacks);
	if (!is_sorted(stacks))
	{
		if (stacks->size_a == 2)
			sa(stacks);
		else if (stacks->size_a == 3)
			sort_three(stacks);
		else if (is_circularly_sorted(stacks))
			sort_stack(stacks);
		else
			sort_more_than_three(stacks);
	}
	exit_free_stacks(EXIT_SUCCESS, "", stacks);
}
