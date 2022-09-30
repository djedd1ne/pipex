LIBFT = cd Libft && make
LIB = Libft/libft.a

INCLUDES = -I./includes
SRC = pipex_utils.c \
      pipex.c

OBJ = $(SRC:%.c=%.o)

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIB):
	$(LIBFT)

%.o:%.cc
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(LIB) $(OBJ) -o $@ 

clean :
	rm -rf $(OBJ)
	cd Libft && make clean

fclean : clean
	rm -rf $(NAME)
	cd libft && make fclean

re : fclean all

.PHONY: all clean fclean re
