#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/*Structures*/

typedef struct		s_env
{
	char			*str;
	char			**subs;
	struct s_form	*form;
}					t_env;

typedef	struct		s_opt
{
	int				posi;
	int				hash;
	int				lzero;
	int				space;
	int				lalign;
}					t_opt;

typedef struct		s_arg
{
	char 			*s;
	int 			*i;
	short 			*sh;
	long			*l;
}					t_arg;

typedef struct		s_form
{
	int				id;
	char			size;
	int				width;
	int				precision;
	char			conversion;
	char			*content;
	void			*argument;
	struct s_arg	*arg;
	struct s_opt	*opt;
	struct s_form	*next;
	struct s_form	*prev;
}					t_form;

/*Defines*/

/*Prototypes*/

/*printf.c*/
int			ft_printf(char *format, ...);

/*ft_init.c*/
t_env		*ft_initenv(char *str);
t_opt		*ft_initopt(char *str);
t_form		*ft_initform(char *str);
t_env   	*ft_processinit(char *str);

/*t_form.c*/
void		create_t_form(t_env *env);

/*parsingform.c*/
void		fill_t_form(t_env *env);

/*ft_charcheck.c*/
int     ft_typeconv(char c);
int     ft_isoption(char c);
int		ft_isespace(char *str, int i);

/*ft_utility.c*/
char    *ft_strnew(int size);

/*error.c*/
void		ft_error(char *str);

/*putstring.c*/
void 		ft_putstr(char *str);
void 		ft_putchar(char c);
int			ft_strlen(char *str);

/*conversion.c*/
void    parsingargument(t_env *env, va_list va);

#endif
