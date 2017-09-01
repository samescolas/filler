NAME = filler

CC = gcc

HEADER = includes/$(NAME).h

SRCS = $(shell ls srcs/*.c$)
OBJS = $(subst srcs/,.objs/,$(SRCS:.c=.o))

LIBFT = libft/libft.a
LIB_DEPS = $(wildcard libft/*.c$)
LINK = -L libft -lft

DIRS = .objs

all : $(NAME)

$(DIRS) :
	mkdir -p $(DIRS)

$(NAME) : $(DIRS) $(OBJS) $(HEADER)
	$(CC) .objs/*.o $(LINK) -o $@

.objs/%.o : srcs/%.c $(LIBFT)
	$(CC) -Iincludes -c -o $@ $<

$(LIBFT) : $(LIB_DEPS)
	make -C libft

.PHONY : clean fclean re $(DIRS)

clean :
	rm -f libft/*\.o$
	rm -f .objs/*\.o$
	rm -f filler.trace

fclean : clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re : fclean all
