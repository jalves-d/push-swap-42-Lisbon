CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap

SRCS = main.c ft_swapt.c ft_swap.c ft_psutilsm.c ft_psutils.c ft_opt.c ft_op.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	gcc $(OBJS) $(FLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean all
