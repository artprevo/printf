/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_opt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 20:19:46 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/28 19:17:08 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		checkoptionerror(t_env *env, t_form *form)
{
	t_opt	*opt;

	if (form->opt)
	{
		env = 0;
		opt = form->opt;
		if (opt->posi != 0 && opt->space != 0 && CONV != 'd')
			ft_error(env);
		if (opt->lalign != 0 && opt->lzero != 0 && CONV != 'd')
			ft_error(env);
		return (1);
	}
	else
		return (0);
}

static int		applydoubleoption(t_form *form, char *str)
{
	t_opt	*opt;

	opt = form->opt;
	if (opt->posi != 0 && opt->lalign != 0)
	{
		oposineg(form, str, WIDTH);
		return (1);
	}
	if (opt->posi != 0 && opt->lzero != 0)
	{
		oposizero(form, str, WIDTH);
		return (1);
	}
	if (opt->lalign != 0 && opt->space != 0)
	{
		onegspace(form, str, WIDTH);
		return (1);
	}
	if (opt->lzero != 0 && opt->space != 0)
	{
		ozerospace(form, str, WIDTH);
		return (1);
	}
	return (0);
}

static void		applyoption(t_form *form, char *str)
{
	t_opt	*opt;
	int		i;

	i = WIDTH;
	opt = form->opt;
	if (opt->posi != 0)
	{
		if (str[0] != '-')
			oposi(form, str, i);
	}
	else if (opt->hash != 0)
	{
		if (str[0] != '0' && str[1])
			ohash(form, str, i);
	}
	else if (opt->lzero != 0)
		olzero(form, str, i);
	else if (opt->space != 0)
	{
		if (str[0] != '-')
			ospace(form, str, i);
	}
	else if (opt->lalign != 0)
		olalign(form, str, i);
}

void			option(t_env *env)
{
	t_form	*form;
	char	*str;

	form = env->form;
	while (form)
	{
		if (CONV == 'c' || CONV == 's' || CONV == '%' || CONV == 'p')
			break ;
		if (checkoptionerror(env, form) == 1 && PRECI <= ft_strlen(RESULT))
		{
			str = RESULT;
			if (applydoubleoption(form, str) == 0)
				applyoption(form, str);
		}
		form = form->next;
	}
}
