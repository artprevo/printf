/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_form.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:05:39 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/06 12:16:12 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_form		*ft_addform(t_form **begin, t_form *new)
{
	t_form	*tmp;

	tmp = *begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
	return (new);
}

static int	inbetweenform(t_form *new, char *str, int i)
{
	int		j;
	char	*tmp;

	j = i;
	while (str[i] != '%')
		i++;
	tmp = ft_strnew(i - j + 1);
	i = 0;
	while (str[j] != '%')
		tmp[i++] = str[j++];
	new->type = 0;
	new->content = tmp;
	if (ft_strlen(tmp) == 1)
		return (0);
	return (j);
}

static int	strform(t_form *new, char *str, int i)
{
	int		j;
	char	*tmp;

	j = i;
	while (ft_typeconv(str[i]) == 0)
	{
		if (i != j && str[i] == '%')
			ft_error("bad type conversion.");
		i++;
	}
	tmp = ft_strnew(i - j + 1);
	i = 0;
	while (ft_typeconv(str[j]) == 0)
	{
		tmp[i] = str[j];
		i++;
		j++;
	}
	tmp[i++] = str[j];
	new->type = 1;
	new->content = tmp;
	return (j);
}

int			newform(t_env *env, char *str, int i, int type)
{
	t_form	*new;
	int		j;

	j = 0;
	if (env->form == NULL)
	{
		new = ft_initform(str);
		env->form = new;
	}
	else
		new = ft_addform(&new, ft_initform(str));
	if (type == 1)
		i = strform(new, str, i);
	else
		j = inbetweenform(new, str, i);
	if (j != 0)
		return (j);
	return (i);
}

void		create_t_form(t_env *env)
{
	char	*str;
	int		i;
	int		j;

	str = env->str;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (i != 0)
				j = newform(env, str, j, 0);
			i = newform(env, str, i, 1);
			j = i + 1;
		}
		i++;
	}
}
