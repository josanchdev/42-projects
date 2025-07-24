# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/14 00:00:00 by josanch2          #+#    #+#              #
#    Updated: 2025/07/14 00:00:00 by josanch2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME = libft.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Directories
STR_DIR = str/
MEM_DIR = mem/
NBR_DIR = nbr/
LST_DIR = lst/
PRINTF_DIR = printf/
GNL_DIR = get_next_line/
OBJS_DIR = objs/

# Source files organized by category
STR_SRCS = ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strcmp.c ft_strlcpy.c \
           ft_strlcat.c ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c \
           ft_strtrim.c ft_striteri.c ft_split.c ft_strmapi.c ft_strlen.c

MEM_SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
           ft_memcmp.c ft_calloc.c

NBR_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
           ft_toupper.c ft_tolower.c ft_atoi.c ft_itoa.c ft_putchar_fd.c \
           ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

LST_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
           ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
           ft_lstmap.c

PRINTF_SRCS = ft_printf_base.c ft_print_unsigned.c ft_printf.c ft_utils.c

GNL_SRCS = get_next_line.c

# Full paths to source files
STR_SRCS_FULL = $(addprefix $(STR_DIR), $(STR_SRCS))
MEM_SRCS_FULL = $(addprefix $(MEM_DIR), $(MEM_SRCS))
NBR_SRCS_FULL = $(addprefix $(NBR_DIR), $(NBR_SRCS))
LST_SRCS_FULL = $(addprefix $(LST_DIR), $(LST_SRCS))
PRINTF_SRCS_FULL = $(addprefix $(PRINTF_DIR), $(PRINTF_SRCS))
GNL_SRCS_FULL = $(addprefix $(GNL_DIR), $(GNL_SRCS))

# All source files
ALL_SRCS = $(STR_SRCS_FULL) $(MEM_SRCS_FULL) $(NBR_SRCS_FULL) $(LST_SRCS_FULL) $(PRINTF_SRCS_FULL) $(GNL_SRCS_FULL)

# Object files
OBJS = $(ALL_SRCS:.c=.o)
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[0;33m
NC = \033[0m # No Color

# Main rule
all: $(NAME)

# Create the library
$(NAME): $(OBJS_PREFIXED)
	@echo "$(BLUE)Creating library $(NAME)...$(NC)"
	@$(AR) $(NAME) $(OBJS_PREFIXED)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(NC)"

# Compile object files
$(OBJS_DIR)str/%.o: str/%.c libft.h
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling: $(notdir $<)$(NC)"
	@$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJS_DIR)mem/%.o: mem/%.c libft.h
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling: $(notdir $<)$(NC)"
	@$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJS_DIR)nbr/%.o: nbr/%.c libft.h
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling: $(notdir $<)$(NC)"
	@$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJS_DIR)lst/%.o: lst/%.c libft.h
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling: $(notdir $<)$(NC)"
	@$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJS_DIR)printf/%.o: printf/%.c libft.h
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling: $(notdir $<)$(NC)"
	@$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJS_DIR)get_next_line/%.o: get_next_line/%.c libft.h get_next_line/get_next_line.h
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling: $(notdir $<)$(NC)"
	@$(CC) $(CFLAGS) -I. -c $< -o $@

# Clean object files
clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@$(RM) -r $(OBJS_DIR)
	@echo "$(GREEN)✓ Object files cleaned!$(NC)"

# Clean everything
fclean: clean
	@echo "$(RED)Cleaning library...$(NC)"
	@$(RM) $(NAME)
	@echo "$(GREEN)✓ Library cleaned!$(NC)"

# Rebuild everything
re: fclean all

# Declare phony targets
.PHONY: all clean fclean re help
