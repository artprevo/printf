/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_ptrerror1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:26:07 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/28 19:27:05 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	errori(t_env *env, t_form *form)
{
	if (HASH != 0)
		HASH = 0;
	if (LZERO != 0 && LALIGN != 0)
		LZERO = 0;
	if (PRECI == -1 && form->arg.li == 0)
	{
		CONV = 's';
		form->arg.s = "";
	}
	env = 0;
}

void	erroro(t_env *env, t_form *form)
{
	if (LZERO != 0 && LALIGN != 0)
		LZERO = 0;
	if (PRECI == -1 && form->arg.li == 0 && HASH == 0)
	{
		CONV = 's';
		form->arg.s = "";
	}
	env = 0;
}

void	erroru(t_env *env, t_form *form)
{
	t_opt	*opt;

	if (LZERO != 0 && LALIGN != 0)
		LZERO = 0;
	if (form->opt)
	{
		opt = form->opt;
		if (opt->space != 0)
			opt->space = 0;
		if (opt->posi != 0)
			opt->posi = 0;
	}
	if (PRECI == -1 && form->arg.li == 0 && HASH == 0)
	{
		CONV = 's';
		form->arg.s = "";
	}
	env = 0;
}

void	errorx(t_env *env, t_form *form)
{
	if (LZERO != 0 && LALIGN != 0)
		LZERO = 0;
	if (PRECI == -1 && form->arg.li == 0)
	{
		CONV = 's';
		form->arg.s = "";
	}
	env = 0;
}

void	errorxx(t_env *env, t_form *form)
{
	if (LZERO != 0 && LALIGN != 0)
		LZERO = 0;
	if (PRECI == -1 && form->arg.li == 0)
	{
		CONV = 's';
		form->arg.s = "";
	}
	env = 0;
}
