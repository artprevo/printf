/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:29:51 by jegloff           #+#    #+#             */
/*   Updated: 2019/09/12 19:42:11 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				print_form(t_env *env)
{
	t_form	*form;
	int		i;

	i = 0;
	form = 0;
	if (env->form)
		form = env->form;
	while (form)
	{
		if (TYPE == 1 && RESULT != NULL)
		{
			if (CONV == 'c' && form->arg.c == '\0')
				i += (ft_strlen(RESULT) + 1);
			else
				i += ft_strlen(RESULT);
			ft_putstr(RESULT);
		}
		else if (TYPE == 0 && CONTENT != NULL)
		{
			ft_putstr(CONTENT);
			i += ft_strlen(CONTENT);
		}
		form = form->next;
	}
	return (i);
}

static void		processing(t_env *env)
{
	errorcheck(env);
	lastform(env, 0, 0, env->str);
	convargument(env);
	option(env);
	applyformat(env);
}

int				ft_printf(char *format, ...)
{
	t_env		*env;
	va_list		va;
	int			i;

	va_start(va, format);
	if (ft_strlen(format) == 0)
		return (0);
	if (initialerrorcheck(format) == 0)
		return (0);
	if (ft_strcmp("BARTEXIT", format) == 1)
		return (-1);
	env = ft_processinit(format);
	create_t_form(env);
	if (env->form)
	{
		fill_t_form(env);
		parsingargument(env, va);
	}
	processing(env);
	i = print_form(env);
	va_end(va);
	tafreetatoucompri(env);
	return (i);
}
