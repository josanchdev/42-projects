/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:33:20 by josanch2          #+#    #+#             */
/*   Updated: 2025/02/09 16:33:22 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include "stdlib.h"
# include "unistd.h"
# include "fcntl.h"
# include "stdio.h"

int		ft_strlen(char *str);
char	*ft_strstr(char *str, char *to_find);
char	*get_first_line(char *file);
char	*ft_get_next_line(char *file, char *line);
char	*reading_buff(int fd);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
