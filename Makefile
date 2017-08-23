# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sescolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/13 09:59:58 by sescolas          #+#    #+#              #
#    Updated: 2017/08/10 12:01:30 by sescolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

HEADER = $(NAME).h

SRCS = 	$(shell ls srcs/*.c$)
SRCS += $(shell ls libft/*.c)

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@ar rc $@ $(OBJS)

$(OBJS): $(SRCS) $(HEADER)
	$(CC) $(CFLAGS) -c $(subst .o,.c,$@) -o $@

.PHONY: clean fclean re print

print:
	@echo $(SRCS)

clean:
	rm -f *.o$
	rm -f libft/*.o$
	rm -f libft/libft.a

fclean: clean
	rm -f $(NAME)

re: fclean all
