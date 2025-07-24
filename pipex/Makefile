NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra -I./include

RM = rm -rf

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = 	src/pipex.c\
		src/utils.c\
		src/path_utils.c\

SRCS_BONUS = 	src/pipex_bonus.c\
				src/utils.c\
				src/path_utils.c\

$(NAME) : $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT) :
	make all -C $(LIBFT_DIR)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

clean :
	$(RM) $(NAME)
	make clean -C $(LIBFT_DIR)

re : fclean all

bonus : $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_BONUS) $(LIBFT) -o $(NAME)
