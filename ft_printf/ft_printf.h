/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:30:28 by josanch2          #+#    #+#             */
/*   Updated: 2024/01/31 17:30:31 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "Libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_print_arg(va_list args, const char *format);
int		ft_printchar(int c);
int		ft_printstr(const char *str);
char	get_char_representation(int remainder, int upperCase);
void	ft_putnbr_base_recursive(int number, int base, int upperCase);
int		ft_printnbr(int n);
char	*ft_uitoa(unsigned int n);
int		ft_count_digits(unsigned int n);
int		ft_print_unsigned(unsigned int n);
int		ft_printpercent(void);
void	ft_put_base(unsigned long int num, int base, int upperCase);
int		ft_printptr(void *ptr);
int		ft_printhex(unsigned int n, int uppercase);
#endif
