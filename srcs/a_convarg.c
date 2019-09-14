/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertargument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:34:45 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/12 14:59:15 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static t_conv g_ptr[] =
{
	{'c', &convargc},
	{'s', &convargs},
	{'p', &convargp},
	{'f', &convargf},
	{'d', &convargd},
	{'i', &convargd},
	{'o', &convargo},
	{'u', &convargu},
	{'x', &convargx},
	{'X', &convargxx},
	{48, NULL}
};

static	char	*convargpercent(char *str)
{
	char	*tmp;

	str = 0;
	tmp = ft_strnew(1);
	tmp[0] = '%';
	return (tmp);
}
void	convargument(t_env *env)
{
	t_form	*form;
	char	c;
	int		i;

	form = env->form;
	while (form)
	{
		i = 0;
		if (CONV == '%' && TYPE == 1)
		{
			RESULT = convargpercent(CONTENT);
			form = form->next;
		}
		if (TYPE == 1)
		{
			c = CONV;
			while (g_ptr[i].conv != 48)
			{
				if (c == g_ptr[i].conv)
					RESULT = g_ptr[i].ft_conv(form, &form->arg);
				i++;
			}
		}
		form = form->next;
	}
}
