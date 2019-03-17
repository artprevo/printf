/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ptrconvarg2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 17:41:17 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/27 20:15:28 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*convargo(t_form *form, t_arg *arg)
{
	char				*res;
	unsigned long long	nb;

	if (SIZE == 'h')
		nb = (unsigned short)(arg->li);
	else if (SIZE == 'H')
		nb = (unsigned char)(arg->li);
	else if (SIZE == 'l')
		nb = (unsigned long)(arg->li);
	else if (SIZE == 'M')
		nb = (unsigned long long)(arg->li);
	else
		nb = (unsigned int)(arg->li);
	res = itoabase(nb, 8);
	return (res);
}

char	*convargu(t_form *form, t_arg *arg)
{
	char				*res;
	unsigned long long	nb;

	if (SIZE == 'h')
		nb = (unsigned short)(arg->li);
	else if (SIZE == 'H')
		nb = (unsigned char)(arg->li);
	else if (SIZE == 'l')
		nb = (unsigned long)(arg->li);
	else if (SIZE == 'M')
		nb = (unsigned long long)(arg->li);
	else
		nb = (unsigned int)(arg->li);
	res = itoabase(nb, 10);
	return (res);
}

char	*convargx(t_form *form, t_arg *arg)
{
	char				*res;
	int					i;
	unsigned long long	nb;

	if (SIZE == 'h')
		nb = (unsigned short)(arg->li);
	else if (SIZE == 'H')
		nb = (unsigned char)(arg->li);
	else if (SIZE == 'l')
		nb = (unsigned long)(arg->li);
	else if (SIZE == 'M')
		nb = (unsigned long long)(arg->li);
	else
		nb = (unsigned int)(arg->li);
	i = 0;
	res = itoabase(nb, 16);
	while (res[i])
	{
		if (res[i] > 64 && res[i] < 91)
			res[i] += 32;
		i++;
	}
	return (res);
}

char	*convargxx(t_form *form, t_arg *arg)
{
	char				*res;
	int					i;
	unsigned long long	nb;

	if (SIZE == 'h')
		nb = (unsigned short)(arg->li);
	else if (SIZE == 'H')
		nb = (unsigned char)(arg->li);
	else if (SIZE == 'l')
		nb = (unsigned long)(arg->li);
	else if (SIZE == 'M')
		nb = (arg->li);
	else
		nb = (unsigned int)(arg->li);
	i = 0;
	res = itoabase(nb, 16);
	while (res[i])
	{
		if (res[i] > 96 && res[i] < 123)
			res[i] -= 32;
		i++;
	}
	return (res);
}

char	*convargf(t_form *form, t_arg *arg)
{
	double		f;
	long double	lf;
	char		*res;

	lf = arg->lf;
	f = arg->f;
	if (PRECI == 0)
		PRECI = 6;
	if (SIZE == 'L')
		res = conv_float((double)lf, PRECI);
	else
		res = conv_float(f, PRECI);
	return (res);
}
