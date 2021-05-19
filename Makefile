# -*- Makefile -*-

SRCS = $(wildcard ./srcs/*.c)

OBJS = $(SRCS:%.c=%.o)

NAME = push_swap

LIBFT = libft/libft.a

INCLUDES = -I includes

CC = gcc
FLAGS = -Wall -Wextra -Werror
#AR = ar rcsv
RM = rm -rf

%.o: %.c
	$(CC) $(FLAGS) -c $< $(INCLUDES) -o $@ 

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(INCLUDES) -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re