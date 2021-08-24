CFLAGS = -Wall -Werror -Wextra -g -I includes -fsanitize=address

NAME = push_swap

SRCS = srcs/main.c srcs/ft_swapt.c srcs/ft_swap.c \
	srcs/ft_psutilsm.c srcs/ft_psutils.c srcs/ft_opt.c srcs/ft_op.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	gcc $(OBJS) $(CFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean all
