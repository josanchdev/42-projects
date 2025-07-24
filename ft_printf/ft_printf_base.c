/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:30:36 by josanch2          #+#    #+#             */
/*   Updated: 2024/01/31 17:30:38 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned long int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	if (len == 0)
		len = 1;
	return (len);
}

int	ft_printptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += ft_printstr("0x0");
		return (count);
	}
	count += ft_printstr("0x");
	ft_put_base((unsigned long int)ptr, 16, 0);
	count += ft_hex_len((unsigned long int)ptr);
	return (count);
}

int	ft_printhex(unsigned int n, int uppercase)
{
	int	count;

	count = 0;
	ft_put_base(n, 16, uppercase);
	count += ft_hex_len((unsigned long int)n);
	return (count);
}

void	ft_put_base(unsigned long int num, int base, int upperCase)
{
	if (num >= (unsigned long int)base)
	{
		ft_put_base(num / base, base, upperCase);
		ft_put_base(num % base, base, upperCase);
	}
	else
	{
		if (num <= 9)
			ft_printchar(num + '0');
		else
		{
			if (upperCase == 1)
			{
				ft_printchar(num - 10 + 'A');
			}
			else
				ft_printchar(num - 10 + 'a');
		}
	}
}
