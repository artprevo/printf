NAME		=	ft_printf

CC			=	gcc
FLAGS		=	-g -Wall -Wextra -Werror -fsanitize=address

SRC_DIR		=	srcs/
INC_DIR		=	includes/
INC_LIB		=	libft/include/
OBJ_DIR		=	objs/

SRC_FILE	=	main5.c\
				u_error.c\
				f_t_form.c\
				printf.c\
				init.c\
				o_opt.c\
				o_ptropt.c\
				o_ptropt2.c\
				u_putstring.c\
				u_charcheck.c\
				u_utility.c\
				u_itoa.c\
				u_itoabase.c\
				f_lastform.c\
				f_parsform.c\
				f_applyformat.c\
				percentform.c\
				a_parsarg.c\
				a_convarg.c\
				a_ptrconvarg1.c\
				a_ptrconvarg2.c\
				a_ptrparsarg1.c\
				a_ptrparsarg2.c\
				e_errorcheck.c\
				e_ptrerror1.c\
				e_ptrerror2.c\
				e_initialerrorcheck.c\
				conversion_float.c\
				u_utility_double.c\
				freeall.c\

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
