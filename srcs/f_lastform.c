/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastform2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 19:17:00 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/12 18:04:44 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		filllast(t_form *new, char *str, int i)
{
	int		j;
	char	*tmp;

	j = i;
	while (str[i] != '\0')
		i++;
	tmp = ft_strnew(i - j + 1);
	i = 0;
	while (str[j] != '\0')
		tmp[i++] = str[j++];
	tmp[i] = '\0';
	new->type = 0;
	new->content = tmp;
}

static	void	createlast(t_env *env, char *str, int i)
{
	t_form *new;

	if (env->form == NULL)
	{
		new = ft_initform(str);
		env->form = new;
	}
	else
		new = ft_addform(&env->form, ft_initform(str));
	filllast(new, str, i);
}

static	int		checkpair(int i)
{
	while (i != 1)
	{
		if ((i % 2) != 0)
			return (0);
		i = i/2;
	}
	return (1);
}

static	int		checklast(t_env *env, char *str, int i)
{
	int	k;
	int	j;
	t_form	*form;

	form = env->form;
	j = 0;
	while (form)
	{
		if (TYPE == 1)
		{
			if (CONV == '%')
				j++;
			j++;
		}
		form = form->next;
	}
	k = 0;
	while (i >= 0)
	{
		if (str[i] == '%')
			k++;
		i--;
	}
	if (k == j)
		return (1);
	if (checkpair(k) == 0)
		return (0);
	return (1);
}

void			lastform(t_env *env, int i, int k, char *str)
{
	i = ft_strlen(str);
	while (str[i] != '%')
	{
		i--;
		if (i == 0 && str[i] != '%')
		{
			k = 1;
			break ;
		}
	}
	if (k == 1)
		createlast(env, str, i);
	else
	{
		if (checkpercentform(env, str, i) == 0 && checklast(env, str, i) == 1)
		{
			while (ft_typeconv(str[i]) != 1)
				i++;
			if (i != 0)
				i++;
		}
		else
			i++;
		createlast(env, str, i);
	}
}
