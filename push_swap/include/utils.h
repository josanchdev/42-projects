/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:33:56 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/07 11:33:58 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"

/* Argument validation and parsing */
bool	is_valid_int_str(const char *str);
int		*check_and_get_args(int argc, char **argv, t_stacks *stacks);
char	*concatenate_args(int argc, char **argv);

/* Utility functions */
void	free_arr(char **array);
int		count_tokens_in_str(const char *string);
int		count_args(int argc, char **argv);

/* Stack utilities */
int		find_max_val(const t_stacks *stacks, const char x);
int		find_min_val(const t_stacks *stacks, const char x);
size_t	find_idx(const t_stacks *stacks, const char x, int value);

/* Memory management */
void	exit_free_stacks(int exit_code, const char *err_msg, t_stacks *stacks);
void	check_args_init_stacks(int argc, char **argv, t_stacks *stacks);

#endif
