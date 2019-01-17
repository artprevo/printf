/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_form.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:05:39 by artprevo          #+#    #+#             */
/*   Updated: 2019/01/16 18:28:45 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// static	int		ft_countsub(char *str)
// {
// 	int i;
// 	int	sub;
//
// 	sub = 0;
// 	i = 0;
// 	if (str[i] != '%')
// 		sub = 1;
// 	while (str[i])
// 	{
// 		if (str[i] == '%')
// 		{
// 			while (ft_typeconv(str[i]) == 0)
// 				i++;
// 			sub++;
// 			if (str[i + 1] && str[i + 1] != '%')
// 				sub++;
// 		}
// 		i++;
// 	}
// 	printf("sub = %d\n\n", sub);
// 	return (sub);
// }

static	t_form	*ft_addform(t_form **begin, t_form *new)
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

static	int	strform(t_form *new, char *str, int i)
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
	new->content = tmp;
	return (j);
}

static int	newform(t_env *env, char *str, int i, int id)
{
	t_form	*new;
	// char	**tab;

	if (env->form == NULL)
	{
		new = ft_initform(str);
		env->form = new;
	}
	else
		new = ft_addform(&new, ft_initform(str));
	i = strform(new, str, i);
	new->id = id;
	// tab = env->subs;
	// tab[id] = new->content;
	return (i);
}

void	create_t_form(t_env *env)
{
	// char	**tab;
	char	*str;
	int		i;
	int		id;

	str = env->str;
	// id = ft_countsub(str);
	// if (!(tab = (char **)malloc(sizeof(char *) * (id + 1))))
	// 	exit(0);
	// env->subs = tab;
	i = 0;
	id = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i = newform(env, str, i, id);
			id++;
		}
		i++;
	}
}
