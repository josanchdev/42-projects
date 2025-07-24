/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:33:47 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/07 11:33:50 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "push_swap.h"

/* Sorting algorithms */
bool	is_sorted(const t_stacks *stacks);
bool	is_circularly_sorted(const t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_stack(t_stacks *stacks);
void	sort_more_than_three(t_stacks *stacks);

/* Target calculation */
void	set_target_a(t_stacks *stacks);
void	set_target_b(t_stacks *stacks);

/* Cost calculation */
void	calc_cost(t_stacks *stacks);
size_t	find_cheapest(const t_stacks *stacks);

/* Movement helpers */
void	r_to_top(t_stacks *stacks, const size_t element_to_move);
void	move_cheapest_to_top(t_stacks *stacks);
void	move_b_target_to_top(t_stacks *stacks);

#endif
