/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastform2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 19:17:00 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/03 19:56:10 by artprevo         ###   ########.fr       */
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

void			lastform(t_env *env)
{
	int		i;
	char	*str;

	str = env->str;
	i = 0;
	while (str[i])
		i++;
	while (str[i] != '%')
	{
		i--;
		if (i == 0)
			break ;
	}
	while (ft_typeconv(str[i]) != 1)
		i++;
	if (i != 0)
		i++;
	createlast(env, str, i);
}
