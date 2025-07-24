/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:29:19 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/07 11:29:20 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

char	*concatenate_args(int argc, char **argv)
{
	char	*concat_str;
	char	*arg_with_space_added;
	char	*temp;
	int		i;

	concat_str = "";
	i = 1;
	while (i < argc)
	{
		arg_with_space_added = ft_strjoin(argv[i], " ");
		if (!arg_with_space_added && i != 1)
		{
			free(concat_str);
			return (NULL);
		}
		temp = concat_str;
		concat_str = ft_strjoin(concat_str, arg_with_space_added);
		free(arg_with_space_added);
		if (i != 1)
			free(temp);
		if (!concat_str)
			return (NULL);
		i++;
	}
	return (concat_str);
}

static int	*parse_str_to_int_arr(const char *str, const size_t num_tokens)
{
	char	**tokens;
	size_t	i;
	int		*int_array;

	tokens = ft_split(str, ' ');
	i = 0;
	if (!tokens)
		return (NULL);
	int_array = ft_calloc(num_tokens, sizeof(int));
	if (!int_array)
	{
		free_arr(tokens);
		return (NULL);
	}
	while (i < num_tokens)
	{
		int_array[i] = ft_atoi(tokens[i]);
		i++;
	}
	free_arr(tokens);
	return (int_array);
}

static bool	has_duplicates(const int *array, const size_t length)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!array || length <= 0)
		return (true);
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length)
		{
			if (array[i] == array[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static char	*check_args_pre(int argc, char **argv, t_stacks *stacks)
{
	char	*arg_str;

	if (argc < 2)
		exit_free_stacks(EXIT_SUCCESS, "", stacks);
	arg_str = concatenate_args(argc, argv);
	if (!arg_str)
		exit_free_stacks(EXIT_MALLOC_FAILURE, "Error\n", stacks);
	if (!is_valid_int_str(arg_str))
	{
		free(arg_str);
		exit_free_stacks(EXIT_INVALID_INT_INPUT, "Error\n", stacks);
	}
	return (arg_str);
}

int	*check_and_get_args(int argc, char **argv, t_stacks *stacks)
{
	char	*arg_str;
	size_t	num_tokens;
	int		*int_arr;

	arg_str = check_args_pre(argc, argv, stacks);
	num_tokens = count_tokens_in_str(arg_str);
	int_arr = parse_str_to_int_arr(arg_str, num_tokens);
	free(arg_str);
	if (!int_arr)
		exit_free_stacks(EXIT_MALLOC_FAILURE, "Error\n", stacks);
	if (has_duplicates(int_arr, num_tokens))
	{
		free(int_arr);
		exit_free_stacks(EXIT_DUPLICATES, "Error\n", stacks);
	}
	return (int_arr);
}
