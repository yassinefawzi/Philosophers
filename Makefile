SRC =	error.c \
		ft_atoi.c \
		main.c \
		runner.c \
		utils.c

OBJ =	$(SRC:.c=.o)

CC =  cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = philo

all = $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)
fclean:		clean
	$(RM) $(OBJ)
re:		fclean $(NAME)