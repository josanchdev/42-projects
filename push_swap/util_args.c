/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:33:14 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/07 11:33:17 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

void	free_arr(char **array)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	count_tokens_in_str(const char *string)
{
	size_t		num_tokens;
	char		**tokens;

	num_tokens = 0;
	tokens = ft_split(string, ' ');
	if (!tokens)
		return (num_tokens);
	while (tokens[num_tokens] != NULL)
		num_tokens++;
	free_arr(tokens);
	return (num_tokens);
}

int	count_args(int argc, char **argv)
{
	char	*arg_str;
	size_t	num_tokens;

	arg_str = concatenate_args(argc, argv);
	num_tokens = count_tokens_in_str(arg_str);
	free(arg_str);
	return (num_tokens);
}
