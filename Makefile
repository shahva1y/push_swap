NAME = push_swap
NAME_BONUS = checker

SRCS =	main.c\
		\
		instructions/push.c\
		instructions/swap.c\
		instructions/rotate.c\
		\
		algorithms/ft_simple_sort.c\
		algorithms/ft_quick_sort.c\
		algorithms/ft_merge_sort.c\
		algorithms/ft_insert_sort.c\
		algorithms/ft_push_swap_sort.c\
		\
		utils/sort_utils.c\
		utils/valid_utils.c\
		utils/parse_utils.c\
		utils/rotate_utils.c\
		utils/quick_sort_utils.c\
		utils/merge_sort_utils.c\
		utils/insert_sort_utils.c\
		utils/stack_utils.c\
		utils/free_utils.c\

SRCS_BONUS =	bonus/checker.c\
				\
				bonus/ft_execute_commands.c\
				\
				utils/valid_utils.c\
				utils/parse_utils.c\
				utils/stack_utils.c\
				utils/free_utils.c\
				utils/sort_utils.c\
				\
				bonus/instructions/push.c\
                bonus/instructions/swap.c\
                bonus/instructions/rotate.c\

LIB = libft.a
LIB_SRC = ./libft

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)
HEADER = push_swap.h
HEADER_BONUS = ./bonus/bonus.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

.PHONY	: all clean fclean re bonus

all		: $(LIB) $(NAME)

$(NAME)	: $(OBJS) $(LIB_SRC)/$(LIB)
	$(CC) $(OBJS) $(LIB_SRC)/$(LIB) -o $(NAME)

$(LIB)	:
	make all -C $(LIB_SRC)

%.o		: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(MAKE) clean -C $(LIB_SRC)
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean	: clean
	$(MAKE) fclean -C $(LIB_SRC)
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

bonus	:
	make NAME='$(NAME_BONUS)' SRCS='$(SRCS_BONUS)' HEADER='$(HEADER_BONUS)' all

re		: fclean all