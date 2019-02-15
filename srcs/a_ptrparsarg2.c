/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ptrparsarg2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:01:58 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/15 16:04:58 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		parsargouxx(t_form *form, va_list va)
{
	form->arg.li = (long long int)va_arg(va, unsigned int);
}
