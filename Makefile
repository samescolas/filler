NAME = filler

CC = gcc

HEADER = includes/$(NAME).h

SRCS = $(shell ls srcs/*.c$)
OBJS = $(subst srcs/,.objs/,$(SRCS:.c=.o))

LIBFT = libft/libft.a
LIB_DEPS = $(shell ls libft/*.c$)
LINK = -L libft -lft

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(CC) .objs/*.o $(LINK) -o $@

.objs/%.o : srcs/%.c $(LIBFT)
	$(CC) -Iincludes -c -o $@ $<

$(LIBFT) : $(LIB_DEPS)
	make -C libft

.PHONY : clean fclean re

clean :
	rm -f libft/*\.o$
	rm -f .objs/*\.o$
	rm -f filler.trace

fclean : clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re : fclean all
