# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artprevo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/18 19:24:05 by artprevo          #+#    #+#              #
#    Updated: 2019/09/14 17:10:24 by artprevo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = 
PRINTFSRC = u_error.c\
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
			percentform.c\
			u_itoabase.c\
			f_lastform.c\
			f_parsform.c\
			f_applyformat.c\
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

OBJS2 = $(PRINTFSRC:.c=.o)
OBJS = $(OBJS2)

all: $(NAME)

$(NAME): $(addprefix objs/, $(OBJS2))
	@printf "\033[0;35m> Compiling libftprintf.a\033[0m"
	@ar rc $(NAME) $(addprefix objs/, $(OBJS))
	@printf "\033[0;32m > OK\n\033[0m"

$(addprefix objs/, $(OBJS2)): $(addprefix srcs/, $(PRINTFSRC))
	@test -d objs || mkdir objs
	@printf "\033[0;35m.\033[0m"
	@gcc $(FLAGS) -c $(addprefix srcs/, $(addsuffix .c, $(basename $(notdir $@)))) -o objs/$(notdir $@) -I includes/

clean:
	@rm -rdf objs/

fclean: clean
	@rm -f $(NAME)

mainclean:
	@rm -f a.out

cleanall: mainclean fclean

re: fclean all
