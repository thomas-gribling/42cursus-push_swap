NAME = push_swap

SRCS = srcs/
INCLUDE = include/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES = main.c \
		push_swap.c \
		ft_split.c \
		utils.c \
		tab_utils.c \
		stack.c \
		ps_functions.c \
		small_sort.c \
		sort.c \
		path_finder.c
FILES_PREFIX = $(addprefix $(SRCS), $(FILES))

OBJECTS = $(FILES:.c=.o)
OBJECTS_PREFIX = $(addprefix $(SRCS), $(OBJECTS))

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(FILES_PREFIX)
	mv $(OBJECTS) $(SRCS)
	$(CC) $(CFLAGS) $(OBJECTS_PREFIX) -o $@ -I $(INCLUDE)

clean:
	rm -rf $(OBJECTS_PREFIX)

fclean: clean
	rm -rf $(NAME)

re: fclean all