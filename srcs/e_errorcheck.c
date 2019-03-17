/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_errorcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:15:45 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/27 23:20:47 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	t_error	g_ptr[] =
{
	{'c', &errorc},
	{'s', &errors},
	{'p', &errorp},
	{'f', &errorf},
	{'d', &errord},
	{'i', &errori},
	{'o', &erroro},
	{'u', &erroru},
	{'x', &errorx},
	{'X', &errorxx},
	{48, NULL}
};

static void	ptrerrorcheck(t_env *env, t_form *form, char c)
{
	int		i;

	i = 0;
	if (TYPE == 1)
	{
		while (g_ptr[i].conv != 48)
		{
			if (c == g_ptr[i].conv)
				g_ptr[i].ft_errorcheck(env, form);
			i++;
		}
	}
}

void		errorcheck(t_env *env)
{
	t_form	*form;
	char	c;

	form = env->form;
	while (form)
	{
		c = CONV;
		ptrerrorcheck(env, form, c);
		form = form->next;
	}
}
