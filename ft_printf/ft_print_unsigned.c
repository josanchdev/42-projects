/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:30:05 by josanch2          #+#    #+#             */
/*   Updated: 2024/01/31 17:30:09 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_digits(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char			*string;
	unsigned int	length;

	length = ft_count_digits(n);
	string = (char *)malloc(sizeof(char) * (length + 1));
	if (string == NULL)
		return (NULL);
	if (n == 0)
		string[0] = '0';
	string[length] = '\0';
	while (n != 0)
	{
		string[length - 1] = (n % 10) + '0';
		n = n / 10;
		length--;
	}
	return (string);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_uitoa(n);
	len = ft_printstr(num);
	free (num);
	return (len);
}
