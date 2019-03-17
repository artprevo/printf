/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ptrconvarg1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:49:18 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/28 17:20:03 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*convargc(t_form *form, t_arg *arg)
{
	char	*res;
	char	c;

	c = arg->c;
	SIZE = 0;
	res = ft_strnew(1);
	res[0] = c;
	return (res);
}

char		*convargs(t_form *form, t_arg *arg)
{
	char	*res;

	SIZE = 0;
	res = ft_strdup(arg->s);
	return (res);
}

char		*convargd(t_form *form, t_arg *arg)
{
	char		*res;
	long long	nb;

	nb = arg->li;
	if (SIZE == 'h')
		res = ft_itoa((short)nb);
	else if (SIZE == 'H')
		res = ft_itoa((char)nb);
	else if (SIZE == 'l')
		res = lltoa((long)nb, 10);
	else if (SIZE == 'M')
		res = lltoa((long long)nb, 10);
	else
		res = ft_itoa(nb);
	return (res);
}

static char	*fixcharp(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 2;
	j = 0;
	tmp = ft_strnew(ft_strlen(str) + 2);
	tmp[0] = '0';
	tmp[1] = 'x';
	while (str[j])
	{
		str[j] = ft_tolower(str[j]);
		tmp[i++] = str[j++];
	}
	free(str);
	return (tmp);
}

char		*convargp(t_form *form, t_arg *arg)
{
	unsigned long	nb;
	char			*res;
	intptr_t		ptr;

	SIZE = 0;
	ptr = arg->p;
	nb = (unsigned long)ptr;
	if (nb == 0)
	{
		res = itoabase(0, 16);
		res = fixcharp(res);
		return (res);
	}
	res = itoabase(nb, 16);
	res = fixcharp(res);
	return (res);
}
