# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 10:48:13 by josanch2          #+#    #+#              #
#    Updated: 2024/02/17 10:48:14 by josanch2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf_base.c		\
		ft_print_unsigned.c		\
		ft_printf.c		\
		ft_utils.c 	\
	
NAME = libftprintf.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

LIBFT_PATH = ./Libft
LIBFT =	$(LIBFT_PATH)/libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJS_DIR)%.o: %.c ft_printf.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@clang $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJECTS_PREFIXED) $(LIBFT)
	@mv ./Libft/libft.a $(NAME)
	@ar r $(NAME) $(OBJECTS_PREFIXED)
	@echo "Printf Done !"

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJS_DIR)

fclean:	clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)
	
re:	fclean all

.PHONY:	all bonus clean fclean re libft

