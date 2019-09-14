/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 19:31:20 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/28 19:31:51 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <inttypes.h>

# define SIZE		(form->size)
# define WIDTH		(form->width)
# define PRECI		(form->precision)
# define TYPE		(form->type)
# define CONV		(form->conversion)
# define CONTENT	(form->content)
# define RESULT		(form->result)
# define POSI		(form->opt->posi)
# define HASH		(form->opt->hash)
# define LZERO		(form->opt->lzero)
# define SPACE		(form->opt->space)
# define LALIGN		(form->opt->lalign)

typedef struct		s_env
{
	char			*str;
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
	char			*s;
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

typedef struct		s_exec
{
	char			conv;
	void			(*ft_pars)(t_form *form, va_list va);
}					t_exec;

typedef struct		s_conv
{
	char			conv;
	char			*(*ft_conv)(t_form *form, t_arg *arg);
}					t_conv;

typedef struct		s_error
{
	char			conv;
	void			(*ft_errorcheck)(t_env *env, t_form *form);
}					t_error;
/*
** printf.c
*/
int					ft_printf(char *format, ...)
 __attribute__((format(printf,1,2)));

/*
** freall.c
*/
void				tafreetatoucompri(t_env *env);

/*
** percentform.c
*/
int					initpercentform(t_form *new, char *str, int i, int j);
int					checkpercentform(t_env *env, char *str, int i);

/*
** e_errorcheck.c
*/
void				errorcheck(t_env *env);

/*
** e_ptrerror1.c
*/
void				errorc(t_env *env, t_form *form);
void				errors(t_env *env, t_form *form);
void				errorp(t_env *env, t_form *form);
void				errorf(t_env *env, t_form *form);
void				errord(t_env *env, t_form *form);

/*
** e_ptrerror2.c
*/
void				errori(t_env *env, t_form *form);
void				erroro(t_env *env, t_form *form);
void				erroru(t_env *env, t_form *form);
void				errorx(t_env *env, t_form *form);
void				errorxx(t_env *env, t_form *form);

/*
** ft_init.c
*/
t_env				*ft_initenv(char *str);
t_opt				*ft_initopt(char *str);
t_form				*ft_initform(char *str);
t_env				*ft_processinit(char *str);

/*
** t_form.c
*/
void				create_t_form(t_env *env);
int					newform(t_env *env, char *str, int i, int type);
t_form				*ft_addform(t_form **begin, t_form *new);

/*
** parsingform.c
*/
void				fill_t_form(t_env *env);

/*
** ft_charcheck.c
*/
int					ft_typeconv(char c);
int					ft_isoption(char c);
int					ft_isnumber(char c);
char				ft_tolower(char c);
int					ft_typenumb(char c);

/*
** u_utility.c
*/
char				*ft_strnew(int size);
char				*ft_strcpy(char *dst, char *src);
char				*ft_strdup(char *s1);
char				*ft_strdup_free(char *content, int r);
char				*chartostr(char c);

/*
** u_itoabase.c
*/
char				*itoabase(unsigned long long int nb, int base);
char				*lltoa(long long val, int base);

/*
** error.c
*/
void				ft_error(t_env *env);

/*
** putstring.c
*/
void				ft_putstr(char *str);
void				ft_putchar(char c);
int					ft_strlen(char *str);
void				ft_putnbr(int n);
int					ft_strcmp(char *str, char *tmp);

/*
** conversion.c
*/
void				parsingargument(t_env *env, va_list va);

/*
** conversion_float
*/
char				*conv_float(double f, int preci);

/*
** utility_double
*/
char				*ft_dtoa(int n, double f);
double				ft_pow(double nb, int len);

/*
** lastform.c
*/
void				lastform(t_env *env, int i, int k, char *str);

/*
** convertargument.c
*/
void				convargument(t_env *env);

/*
** a_ptrparsarg1.c
*/
void				parsargd(t_form *form, va_list va);
void				parsargc(t_form *form, va_list va);
void				parsargs(t_form *form, va_list va);
void				parsargp(t_form *form, va_list va);
void				parsargf(t_form *form, va_list va);

/*
** a_ptrparsarg2.c
*/
void				parsargouxx(t_form *form, va_list va);

/*
** a_ptrconvarg1.c
*/
char				*convargc(t_form *form, t_arg *arg);
char				*convargs(t_form *form, t_arg *arg);
char				*convargd(t_form *form, t_arg *arg);
char				*convargp(t_form *form, t_arg *arg);

/*
** a_ptrconvarg2.c
*/
char				*convargo(t_form *form, t_arg *arg);
char				*convargu(t_form *form, t_arg *arg);
char				*convargx(t_form *form, t_arg *arg);
char				*convargxx(t_form *form, t_arg *arg);
char				*convargf(t_form *form, t_arg *arg);

/*
** u_itoa.c
*/
char				*ft_itoa(int n);

/*
** o_opt.c
*/
void				option(t_env *env);

/*
** o_ptropt.c
*/
void				oposi(t_form *form, char *str, int width);
void				ohash(t_form *form, char *str, int width);
void				olzero(t_form *form, char *str, int width);
void				ospace(t_form *form, char *str, int width);
void				olalign(t_form *form, char *str, int width);

/*
** o_ptropt2.c
*/
void				oposineg(t_form *form, char *str, int width);
void				oposizero(t_form *form, char *str, int width);
void				onegspace(t_form *form, char *str, int width);
void				ozerospace(t_form *form, char *str, int width);

/*
** applyformat.c
*/
void				applyformat(t_env *env);

/*
** e_initialerrorcheck.c
*/
int					initialerrorcheck(char *str);

#endif
