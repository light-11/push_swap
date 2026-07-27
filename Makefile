NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= push_swap.c \
		  init.c \
		  ft_utils.c \
		  list_utils.c \
		  check.c \
		  simple.c \
		  medium.c \
		  medium_utils.c \
		  bench.c \
		  bench_utils.c \
		  operations_a.c \
		  operations_b.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re