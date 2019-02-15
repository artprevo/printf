/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_ptrerror1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:26:07 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/15 19:05:59 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	errorc(t_form *form)
{
	if (form->opt->posi != 0)
		ft_error("flag '+' results in undefined behavior \
with 'c' conversion specifier");
	if (form->opt->hash != 0)
		ft_error("flag '#' results in undefined behavior \
with 'c' conversion specifier");
	if (form->opt->lzero != 0)
		ft_error("flag '0' results in undefined behavior \
with 'c' conversion specifier");
	if (form->opt->space != 0)
		ft_error("flag ' ' results in undefined behavior \
with 'c' conversion specifier");
	if (form->precision != 0)
		ft_error("precision used with 'c' conversion specifier, \
resulting in undefined behavior");
	if (form->size != 48 && form->size != 'l')
		ft_error("length modifier 'h' results in undefined behavior \
or no effect with 'c' conversion");
}

void	errors(t_form *form)
{
	if (form->opt->posi != 0)
		ft_error("flag '+' results in undefined behavior \
with 's' conversion specifier");
	if (form->opt->hash != 0)
		ft_error("flag '#' results in undefined behavior \
with 's' conversion specifier");
	if (form->opt->lzero != 0)
		ft_error("flag '0' results in undefined behavior \
with 's' conversion specifier");
	if (form->opt->space != 0)
		ft_error("flag ' ' results in undefined behavior \
with 's' conversion specifier");
	if (form->size != 48)
		ft_error("length modifier results in undefined behavior \
or no effect with 's' conversion");
}

void	errorp(t_form *form)
{
	form = 0;
}

void	errorf(t_form *form)
{
	form = 0;
}

void	errord(t_form *form)
{
	form = 0;
}
