# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esouza <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/15 10:21:04 by esouza            #+#    #+#              #
#    Updated: 2018/07/08 15:59:20 by esouza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Source
# https://stackoverflow.com/questions/5178125/ ->
# how-to-place-object-files-in-separate-subdirectory#
# http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# https://www.gnu.org/software/make/manual/html_node/Recursion.html

NAME = esouza.filler

SRCS =	./src/main.c \
		./src/all_way_up.c \
		./src/check_input.c \
		./src/checker.c \
		./src/forward.c \
		./src/free_all.c \
		./src/get_data.c \
		./src/parser.c \
		./src/path.c \
		./src/search_place.c \
		./src/shrink_chessman.c \
      	./src/straight.c \
		./src/update_board.c \
		./src/vertically.c \
		./src/put.c \
		./src/put_horizontally.c


CC = gcc

LIBS = ./libft/libft.a

DEPENDENCY = ./includes/filler.h

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

esouza.filler: $(OBJS)
	$(CC) -o esouza.filler $(SRCS) $(LIBS)

#$(OBJS): $(SRCS) $(DEPENDENCY)
$(OBJDIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $(SRCS)

all: subsystem esouza.filler

subsystem:
	$(MAKE) -C libft

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f esouza.filler

re: fclean all
