/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:52:49 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/27 20:24:57 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	tafreetatoucompri(t_env *env)
{
	t_form	*form;
	t_form	*tmp;

	if (env->form)
	{
		form = env->form;
		while (form)
		{
			free(CONTENT);
			free(RESULT);
			free(form->opt);
			tmp = form->next;
			free(form);
			form = tmp;
		}
		free(env);
	}
}
