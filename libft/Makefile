override	NAME = libft.a

override	SRCS =	ft_isalpha.c		ft_toupper.c\
					ft_isdigit.c		ft_tolower.c\
	   				ft_isalnum.c		ft_strchr.c\
	   				ft_isascii.c		ft_strrchr.c\
	   				ft_isprint.c		ft_strncmp.c\
	   				ft_strlen.c			ft_memchr.c\
	   				ft_memset.c			ft_memcmp.c\
	   				ft_bzero.c			ft_strnstr.c\
	   				ft_memcpy.c			ft_atoi.c\
	   				ft_memmove.c		ft_strcmp.c\
	   				ft_strlcpy.c\
	   				ft_strlcat.c\
	   				\
	   				ft_calloc.c\
	   				ft_strdup.c\
	   				\
	   				ft_substr.c\
	   				ft_strjoin.c\
	   				ft_strtrim.c\
	   				ft_split.c\
	   				ft_itoa.c\
	   				ft_strmapi.c\
	   				ft_striteri.c\
	   				ft_putchar_fd.c\
	   				ft_putstr_fd.c\
	   				ft_putendl_fd.c\
	   				ft_putnbr_fd.c\

SRCS_B = ft_lstnew.c\
		 ft_lstadd_front.c\
		 ft_lstsize.c\
		 ft_lstlast.c\
		 ft_lstadd_back.c\
		 ft_lstdelone.c\
		 ft_lstclear.c\
		 ft_lstiter.c\
		 ft_lstmap.c\

OBJS = $(SRCS:%.c=%.o)
OBJS_B = $(SRCS_B:%.c=%.o)
override	HEADER = libft.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

.PHONY	: all clean fclean re bonus

all		: $(NAME)

$(NAME)	: $(OBJS) $(HEADER)
	ar rc $(NAME) $(OBJS)

%.o		: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	: 
	rm -f $(OBJS) $(OBJS_B)

fclean	: clean
	rm -f $(NAME)

re		: fclean all

bonus	:
	@make OBJS='$(OBJS_B)' all
