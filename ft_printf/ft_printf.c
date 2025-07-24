/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:30:19 by josanch2          #+#    #+#             */
/*   Updated: 2024/01/31 17:30:22 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, char type)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_printchar(va_arg(args, int));
	if (type == 's')
		count += ft_printstr(va_arg(args, const char *));
	if (type == 'p')
		count += ft_printptr(va_arg(args, void *));
	if (type == 'd' || type == 'i')
		count += ft_printnbr(va_arg(args, int));
	if (type == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	if (type == 'x')
		count += ft_printhex(va_arg(args, unsigned int), 0);
	if (type == 'X')
		count += ft_printhex(va_arg(args, unsigned int), 1);
	if (type == '%')
		count += ft_printpercent();
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_formats(args, format[i + 1]);
			i += 2;
		}
		else
		{
			count += ft_printchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
