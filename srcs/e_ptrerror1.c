/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_ptrerror1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:26:07 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/28 19:29:46 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	errorc(t_env *env, t_form *form)
{
	if (POSI != 0)
		POSI = 0;
	if (HASH != 0)
		HASH = 0;
	if (LZERO != 0)
		LZERO = 0;
	if (SPACE != 0)
		SPACE = 0;
	if (PRECI != 0)
		PRECI = 0;
	if (SIZE != 48 && SIZE != 'l')
		SIZE = 0;
	env = 0;
}

void	errors(t_env *env, t_form *form)
{
	if (POSI != 0)
		POSI = 0;
	if (HASH != 0)
		HASH = 0;
	if (LZERO != 0)
		LZERO = 0;
	if (SPACE != 0)
		SPACE = 0;
	if (SIZE != 48)
		SIZE = 0;
	if (PRECI < 0)
		form->arg.s = "";
	env = 0;
}

void	errorp(t_env *env, t_form *form)
{
	if (POSI != 0)
		POSI = 0;
	if (LZERO != 0)
		LZERO = 0;
	if (HASH != 0)
		HASH = 0;
	if (SPACE != 0)
		SPACE = 0;
	if (SIZE != 48)
		SIZE = 0;
	env = 0;
}

void	errorf(t_env *env, t_form *form)
{
	if (form)
	{
	}
	if (env)
	{
	}
}

void	errord(t_env *env, t_form *form)
{
	if (HASH != 0)
		HASH = 0;
	if (LZERO != 0 && LALIGN != 0)
		LZERO = 0;
	if (PRECI == -1 && form->arg.i == 0)
	{
		CONV = 's';
		form->arg.s = "";
	}
	env = 0;
}
