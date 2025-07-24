/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:33:39 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/07 11:33:41 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define EXIT_SUCCESS 0
# define EXIT_MALLOC_FAILURE 1
# define EXIT_INVALID_INT_INPUT 2
# define EXIT_DUPLICATES 3

typedef struct s_stacks
{
	size_t	size_a;
	size_t	size_b;
	int		*stack_a;
	int		*stack_b;
	size_t	*target_a;
	size_t	target_b;
	int		*cost;
	int		*rr;
	int		*rrr;
}	t_stacks;

/* Main function */
int		main(int argc, char **argv);

#endif
