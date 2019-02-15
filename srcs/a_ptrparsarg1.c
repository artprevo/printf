/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ptrparsarg1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:45:33 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/06 17:56:43 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*gerer les cas option h/L*/

void		parsargd(t_form *form, va_list va)
{
	form->arg.i = va_arg(va, int);
}

void		parsargc(t_form *form, va_list va)
{
	form->arg.c = va_arg(va, int);
}

void		parsargs(t_form *form, va_list va)
{
	form->arg.s = va_arg(va, char *);
}

void		parsargp(t_form *form, va_list va)
{
	form->arg.p = va_arg(va, intptr_t);
}

void		parsargf(t_form *form, va_list va)
{
	form->arg.f = va_arg(va, double);
}
