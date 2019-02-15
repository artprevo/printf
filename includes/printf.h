#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h> //pour intptr_t

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

typedef union		u_arg
{
	char			c;
	char 			*s;
	int				i;
	long long int	li;
	intptr_t		p;
	double			f;
	long double		lf;
}					t_arg;

typedef struct		s_form
{
	char			size;
	int				width;
	int				precision;
	int				type;
	char			conversion;
	char			*content;
	char			*result;
	t_arg			arg;
	struct s_opt	*opt;
	struct s_form	*next;
	struct s_form	*prev;
}					t_form;

typedef struct      s_exec
{
	char            conv;
	void            (*ft_pars)(t_form *form, va_list va);
}                   t_exec;

typedef struct		s_conv
{
	char			conv;
	char			*(*ft_conv)();
}					t_conv;

typedef struct		s_error
{
	char			conv;
	void			(*ft_errorcheck)(t_form *form);
}					t_error;

/*Defines*/

/*Prototypes*/

/*printf.c*/
int			ft_printf(char *format, ...);

/*e_errorcheck.c*/
void		errorcheck(t_env *env);

/*e_ptrerror1.c*/
void    errorc(t_form *form);
void    errors(t_form *form);
void    errorp(t_form *form);
void    errorf(t_form *form);
void    errord(t_form *form);

/*e_ptrerror2.c*/
void    errori(t_form *form);
void    erroro(t_form *form);
void    erroru(t_form *form);
void    errorx(t_form *form);
void    errorxx(t_form *form);

/*ft_init.c*/
t_env		*ft_initenv(char *str);
t_opt		*ft_initopt(char *str);
t_form		*ft_initform(char *str);
t_env   	*ft_processinit(char *str);

/*t_form.c*/
void		create_t_form(t_env *env);
int			newform(t_env *env, char *str, int i, int type);
t_form		*ft_addform(t_form **begin, t_form *new);

/*parsingform.c*/
void		fill_t_form(t_env *env);

/*ft_charcheck.c*/
int     ft_typeconv(char c);
int     ft_isoption(char c);
int		ft_isespace(char *str, int i);

/*u_utility.c*/
char    *ft_strnew(int size);
char	*chartostr(int d);
char    *ft_strcpy(char *dst, char *src);
char    *ft_strdup(char *s1);
char    *ft_strdup_free(char *content, int r);

/*u_utility2.c*/
char	*strtostr(char *str);
char	*convargp(intptr_t *ptr);
char    *ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

/*error.c*/
void		ft_error(char *str);

/*putstring.c*/
void 		ft_putstr(char *str);
void 		ft_putchar(char c);
int			ft_strlen(char *str);
void		ft_putnbr(int n);

/*conversion.c*/
void    parsingargument(t_env *env, va_list va);

/*lastform.c*/
void	lastform(t_env *env);

/*convertargument.c*/
void	convargument(t_env *env);

/*a_ptrparsarg1.c*/
void	parsargd(t_form *form, va_list va);
void	parsargc(t_form *form, va_list va);
void	parsargs(t_form *form, va_list va);
void	parsargp(t_form *form, va_list va);
void	parsargf(t_form *form, va_list va);

/*a_ptrparsarg2.c*/
void	parsargouxx(t_form *form, va_list va);

/*u_itoa.c*/
char	*ft_itoa(int n);

/*o_opt.c*/
void    option(t_env *env);

/*o_ptropt.c*/
void    oposi(t_form *form, char *str, int width);
void    ohash(t_form *form, char *str, int width);
void    olzero(t_form *form, char *str, int width);
void    ospace(t_form *form, char *str, int width);
void    olalign(t_form *form, char *str, int width);

/*o_ptropt2.c*/
void    oposineg(t_form *form, char *str, int width);
void    oposizero(t_form *form, char *str, int width);
void    onegspace(t_form *form, char *str, int width);
void    ozerospace(t_form *form, char *str, int width);

/*applyformat.c*/
void	applyformat(t_env *env);

#endif
