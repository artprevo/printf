/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_opt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 20:19:46 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/06 18:02:11 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	checkoptionerror(t_form *form)
{
	t_opt	*opt;

	if (form->opt)
	{	
		opt = form->opt;
		if (opt->posi != 0 && opt->space != 0)
			ft_error ("'+' & ' ' behavior is undefined when used together");
		if (opt->lalign != 0 && opt->lzero != 0)
			ft_error ("'-' & '0' behavior is undefined when used together");
		return (1);
	}
	else
		return (0);
}

static int	applydoubleoption(t_form *form, char *str)
{
	t_opt	*opt;

	opt = form->opt;
	if (opt->posi != 0 && opt->lalign != 0)
	{
		oposineg(form, str, form->width);
		return (1);
	}
	if (opt->posi != 0 && opt->lzero != 0)
	{
		oposizero(form, str, form->width);
		return (1);
	}
	if (opt->lalign != 0 && opt->space != 0)
	{
		onegspace(form, str, form->width);
		return (1);
	}
	if (opt->lzero != 0 && opt->space != 0)
	{
		ozerospace(form, str, form->width);
		return (1);
	}
	return (0);
}
static void	applyoption(t_form *form, char *str)
{
	t_opt	*opt;
	int		i;

	i = form->width;
	opt = form->opt;
	if (opt->posi != 0)
		oposi(form, str, i);
	else if (opt->hash != 0)
		ohash(form, str, i);
	else if (opt->lzero != 0)
		olzero(form, str, i);
	else if (opt->space != 0)
		ospace(form, str, i);
	else if (opt->lalign != 0)
		olalign(form, str, i);
}

void	option(t_env *env)
{
	t_form	*form;
	char	*str;

	form = env->form;
	while (form)
	{
		if (form->conversion == 'c' || form->conversion == 's')
			break ;
		if (checkoptionerror(form) == 1 && form->precision == 0)
		{
			str = env->form->result;
			if (applydoubleoption(form, str) == 0)
				applyoption(form, str);
		}
		form = form->next;
	}
}
