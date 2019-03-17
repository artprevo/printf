/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ptrparsarg1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:45:33 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/28 17:28:54 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		parsargd(t_form *form, va_list va)
{
	if (SIZE == 'l')
		form->arg.li = (long long int)va_arg(va, long int);
	else if (SIZE == 'M')
		form->arg.li = (long long int)va_arg(va, long long int);
	else
		form->arg.li = (long long int)va_arg(va, int);
}

void		parsargc(t_form *form, va_list va)
{
	form->arg.c = va_arg(va, int);
	if (form->arg.c == 0)
	{
		CONV = 's';
		form->arg.s = "^@";
	}
}

void		parsargs(t_form *form, va_list va)
{
	form->arg.s = va_arg(va, char *);
	if (form->arg.s == NULL)
		form->arg.s = "(null)";
}

void		parsargp(t_form *form, va_list va)
{
	form->arg.p = va_arg(va, intptr_t);
	if ((void*)form->arg.p == NULL)
		form->arg.p = 0;
}

void		parsargf(t_form *form, va_list va)
{
	form->arg.f = va_arg(va, double);
}
