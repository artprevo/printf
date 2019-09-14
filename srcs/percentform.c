/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_percentform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:18:23 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/12 17:47:43 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		checkpercentform(t_env *env, char *str, int i)
{
	int		k;
	int		j;

	if (env)
		j = i;
	k = 0;
	if (ft_strlen(str) == 1 && str[0] == '%')
		ft_error(env);
	while (str[i])
	{
		if (ft_typeconv(str[i]) == 1)
			return (0);
		i++;
	}
	while (j != 0)
	{
		j--;
		if (str[j] == '%')
		{
			k++;
			break ;
		}
	}
	return (1);
}

int		initpercentform(t_form *new, char *str, int i, int j)
{
	char	*tmp;

	tmp = ft_strnew(i - j + 1);
	i = 0;
	if (j == 0)
		j++;
	if (str[j] == '%')
		tmp[0] = '%';
	else
	{
		tmp[i] = '%';
		i++;
		while (str[j] != '%')
		{
			if (str[j] != ' ')
				tmp[i++] = str[j];
			j++;
		}
		tmp[i] = '%';
	}
	new->type = 1;
	new->content = tmp;
	return (j + 1);
}
