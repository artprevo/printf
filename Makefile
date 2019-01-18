NAME		=	ft_printf

CC			=	gcc
FLAGS		=	-g -Wall -Wextra -Werror -fsanitize=address

SRC_DIR		=	srcs/
INC_DIR		=	includes/
INC_LIB		=	libft/include/
OBJ_DIR		=	objs/

SRC_FILE	=	main.c\
				error.c\
				printf.c\
				putstring.c\
				ft_charcheck.c\
				ft_utility.c\

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_FILE:.c=.o))

all:			$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
	rm -rf $(LINK)
	$(CC) $(FLAGS) -I $(INC_DIR) $(OBJS) -o $(NAME)
	ln -s $(NAME) $(LINK)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(INC_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(LINK)

fclean:			clean
	rm -rf $(NAME)

re:				fclean all

.PHONY:			fclean clean re

-include $(OBJS:.o=.d)
