/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:29:51 by jegloff           #+#    #+#             */
/*   Updated: 2019/02/15 18:42:12 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void 		print_form(t_env *env)
{
	while (env->form)
	{
		if (env->form->type == 1)
		{
			if (env->form->conversion == 'p')
			{
				ft_putchar('0');
				ft_putchar('x');
			}
			ft_putstr(env->form->result);
		}
		else if (env->form->type == 0)
			ft_putstr(env->form->content);
		env->form = env->form->next;
	}
}

int		ft_printf(char *format, ...)
{
	t_env		*env;
	va_list		va;
	va_start	(va, format);

	//coder itoa base (arg lli)
	//gerer p (ptr) et f (float)

	env = ft_processinit(format);
	create_t_form(env);
	if (env->form)
	{
		fill_t_form(env);
		parsingargument(env, va);
	}
	errorcheck(env);
	lastform(env);
	convargument(env);
	option(env);
	applyformat(env);
	print_form(env);
	va_end (va);
	return (0);
}
