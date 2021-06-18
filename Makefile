# -*- Makefile -*-

SRCS_PS = $(wildcard ./srcs/push_swap/*.c)

SRCS_CH = $(wildcard ./srcs/checker/*.c)

OBJS_PS = $(SRCS_PS:%.c=%.o)

OBJS_CH = $(SRCS_CH:%.c=%.o)

PS = push_swap

CHECK = checker

LIBFT = libft/libft.a

INCLUDES = -I includes

CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rcsv
RM = rm -rf

%.o: %.c
	$(CC) $(FLAGS) -c $< $(INCLUDES) -o $@ 

all: $(PS) $(CHECK)

ps:  $(PS)

$(PS): $(LIBFT) $(OBJS_PS)
	$(AR) push_swap.a $(OBJS_PS)
	$(CC) $(FLAGS) $(OBJS_PS) $(LIBFT) -o $(PS)

check: $(CHECK)

$(CHECK): $(LIBFT) $(OBJS_CH)
	$(CC) $(FLAGS) $(OBJS_CH) $(LIBFT) push_swap.a -o $(CHECK)

$(LIBFT):
	make -C libft

clean:
	$(RM) $(OBJS_CH)
	$(RM) $(OBJS_PS)
	make clean -C libft

fclean: clean
	$(RM) push_swap.a
	$(RM) $(PS) $(CHECK)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re ps check