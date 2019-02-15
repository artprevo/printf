/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_applyformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:55:01 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/15 18:19:35 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	int	emptyopt(t_opt *opt)
{
	if (opt->posi != 0)
		return (0);
	if (opt->hash != 0)
		return (0);
	if (opt->lzero != 0)
		return (0);
	if (opt->space != 0)
		return (0);
	if (opt->lalign != 0)
		return (0);
	return (1);
}

static	void	applywidth(t_form *form)
{
	int		i;
	int		j;
	char	*str;
	char	*tmp;

	i = 0;
	j = 0;
	str = form->result;
	tmp = 0;
	if (emptyopt(form->opt) == 1)
	{
		if (form->width > ft_strlen(str))
		{
			tmp = ft_strnew(form->width);
			while (i < (form->width - ft_strlen(str)))
				tmp[i++] = ' ';
			while (str[j])
				tmp[i++] = str[j++];
			form->result = tmp;
		}
	}
}

static	void	applyprecisionfors(t_form *form)
{
	int		i;
	int		j;
	char	*tmp;
	char	*str;

	i = 0;
	j = 0;
	str = form->result;
	tmp = ft_strnew(form->precision);
	while (i < form->precision)
		tmp[i++] = str[j++];
	form->result = tmp;
}

static	void	applyprecision(t_form *form)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;
	char	*str;

	i = 0;
	j = 0;
	str = form->result;
	k = ft_strlen(str) - form->opt->posi - form->opt->space;
	tmp = ft_strnew(form->precision + form->opt->posi + form->opt->space);
	if (form->opt->posi != 0)
		tmp[i++] = '+';
	if (form->opt->space != 0)
		tmp[i++] = ' ';
	while (i < (form->precision - k))
		tmp[i++] = '0';
	while (str[j])
		tmp[i++] = str[j++];
	free(str);
	form->result = tmp;
}

void	applyformat(t_env *env)
{
	t_form	*form;

	form = env->form;
	while (form)
	{
		if (form->precision != 0 && form->conversion != 'c')
		{
			if (form->conversion == 's')
				applyprecisionfors(form);
			else
				applyprecision(form);
		}
		if (form->width != 0 && form->precision == 0)
			applywidth(form);
		form = form->next;
	}
}
