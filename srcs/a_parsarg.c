/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingargument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:34:45 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/15 18:26:37 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	parsingargument(t_env *env, va_list va)
{
	t_form	*form;
	char	c;
	int		i;
	t_exec	ptr[] = 
	{
		{'c', &parsargc},
		{'s', &parsargs},
		{'p', &parsargp},
		{'f', &parsargf},
		{'d', &parsargd},
		{'i', &parsargd},
		{'o', &parsargouxx},
		{'u', &parsargouxx},
		{'x', &parsargouxx},
		{'X', &parsargouxx},
		{48, NULL}
	};

	form = env->form;
	while (form)
	{
		i = 0;
		if (form->type == 1)
		{
			c = form->conversion;
			while (ptr[i].conv != 48)
			{
				if (c == ptr[i].conv)
					ptr[i].ft_pars(form, va);
				i++;
			}
		}
		form = form->next;
	}
}
