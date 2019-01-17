/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingargument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:34:45 by artprevo          #+#    #+#             */
/*   Updated: 2019/01/17 19:55:40 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	parsingargument(t_env *env, va_list va)
{
	t_form	*form;
	
	form = env->form;
	while (form)
	{
		form->argument = va_arg(va, char *);
		printf("argument = %s\n", form->argument);
		form = form->next;
	}
}
