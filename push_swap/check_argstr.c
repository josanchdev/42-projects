/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:28:13 by josanch2          #+#    #+#             */
/*   Updated: 2025/07/07 11:28:18 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

static bool	is_numeric(const char *token)
{
	if (*token >= '0' && *token <= '9')
	{
		while (*token)
		{
			if (!(*token >= '0' && *token <= '9'))
				return (false);
			token++;
		}
		return (true);
	}
	else if (*token == '-' || *token == '+')
	{
		token++;
		if (*token == '\0' || !(*token >= '0' && *token <= '9'))
			return (false);
		while (*token)
		{
			if (!(*token >= '0' && *token <= '9'))
				return (false);
			token++;
		}
		return (true);
	}
	else
		return (false);
}

static bool	is_int_overflow(const char *token)
{
	int	sign;
	int	int_value;
	int	digit;

	sign = 1;
	int_value = 0;
	if (*token == '-')
	{
		sign = -1;
		token++;
	}
	else if (*token == '+')
		token++;
	while (*token >= '0' && *token <= '9')
	{
		digit = *token - '0';
		if ((sign == 1 && (int_value > INT_MAX / 10
					|| (int_value == INT_MAX / 10 && digit > INT_MAX % 10)))
			|| (sign == -1 && (int_value > INT_MAX / 10
					|| (int_value == INT_MAX / 10 && digit > -(INT_MIN % 10)))))
			return (true);
		int_value = int_value * 10 + digit;
		token++;
	}
	return (false);
}

static bool	is_zero(const char *token)
{
	bool	is_zero;

	is_zero = (ft_strncmp(token, "0", 2) == 0
			|| ft_strncmp(token, "+0", 3) == 0
			|| ft_strncmp(token, "-0", 3) == 0);
	return (is_zero);
}

bool	is_valid_int_str(const char *str)
{
	char	**tokens;
	size_t	i;
	int		int_value;

	tokens = ft_split(str, ' ');
	i = 0;
	if (!tokens)
		return (false);
	while (tokens[i])
	{
		int_value = ft_atoi(tokens[i]);
		if ((int_value == 0 && !is_zero(tokens[i]))
			|| !is_numeric(tokens[i])
			|| is_int_overflow(tokens[i]))
		{
			free_arr(tokens);
			return (false);
		}
		i++;
	}
	free_arr(tokens);
	return (true);
}
