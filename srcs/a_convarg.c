/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertargument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:34:45 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/15 16:34:34 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static t_conv g_ptr[] =
{
	{'c', &chartostr},
	{'s', &strtostr},
	{'p', &convargp},
	//		{'f', &parsargf},
	{'d', &ft_itoa},
	{'i', &ft_itoa},
	//		{'o', &parsargouxx},
	//		{'u', &parsargouxx},
	//		{'x', &parsargouxx},
	//		{'X', &parsargouxx},
	{48, NULL}
};

void	convargument(t_env *env)
{
	t_form	*form;
	char	c;
	int		i;

	form = env->form;
	while (form)
	{
		i = 0;
		if (form->type == 1)
		{
			c = form->conversion;
			while (g_ptr[i].conv != 48)
			{
				if (c == g_ptr[i].conv)
					form->result = g_ptr[i].ft_conv(form->arg);
				i++;
			}
		}
		form = form->next;
	}
}
