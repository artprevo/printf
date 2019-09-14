/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingargument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:34:45 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/12 19:23:08 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static t_exec g_ptr[] =
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

void	parsingargument(t_env *env, va_list va)
{
	t_form	*form;
	char	c;
	int		i;

	form = env->form;
	while (form)
	{
		i = 0;
		if (TYPE == 1 && CONV != '%')
		{
			c = CONV;
			while (g_ptr[i].conv != 48)
			{
				if (c == g_ptr[i].conv)
					g_ptr[i].ft_pars(form, va);
				i++;
			}
		}
		form = form->next;
	}
}
