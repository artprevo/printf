/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_errorcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:15:45 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/15 18:44:12 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ptrerrorcheck(t_form *form, char c)
{
	int		i;
	t_error	ptr[] = 
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

	i = 0;
	if (form->type == 1)
	{
		while (ptr[i].conv != 48)
		{
			if (c == ptr[i].conv)
				ptr[i].ft_errorcheck(form);
			i++;
		}
	}
}

void	errorcheck(t_env *env)
{
	t_form	*form;
	char	c;

	form = env->form;
	while (form)
	{
		c = form->conversion;
		ptrerrorcheck(form, c);
		form = form->next;
	}
}
