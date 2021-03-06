/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ptrparsarg2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:01:58 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/25 19:08:24 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		parsargouxx(t_form *form, va_list va)
{
	if (SIZE == 'l')
		form->arg.li = (unsigned long long)va_arg(va, unsigned long);
	else if (SIZE == 'M')
		form->arg.li = (unsigned long long)va_arg(va, unsigned long long);
	else
		form->arg.li = (unsigned long long)va_arg(va, unsigned int);
}
