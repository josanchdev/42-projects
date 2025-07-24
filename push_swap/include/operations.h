/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:33:29 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/07 11:33:34 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "push_swap.h"

/* Stack Operations A */
void	sa(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rra(t_stacks *stacks);

/* Stack Operations B */
void	sb(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rrb(t_stacks *stacks);

/* Combined Operations */
void	ss(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rrr(t_stacks *stacks);

#endif
