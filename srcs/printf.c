/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:29:51 by jegloff           #+#    #+#             */
/*   Updated: 2019/01/17 19:55:41 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void 		print_form(t_env *env)
{
	while (env->form)
	{
		printf("id = %d\n", env->form->id);
		printf("content = %s\n", env->form->content);
		env->form = env->form->next;
	}
}

int		ft_printf(char *format, ...)
{
	t_env		*env;
	va_list		va;
	va_start	(va, format);

	//stocker l'argument correspondant a chaque t_form dans une structure t_arg
	//trouver comment definir le type d'une variable. pointeur sur fonction ? iteratif ? boucle de if ?
	env = ft_processinit(format);
	create_t_form(env);
	fill_t_form(env);
	parsingargument(env, va);
	va_end (va);
	return (0);
}
