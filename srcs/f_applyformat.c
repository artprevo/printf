/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_applyformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:55:01 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/12 18:17:17 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	void	applywidth(t_form *form, int i, int j, char *str)
{
	char	*tmp;

	if (CONV == 's' && str[0] == '^' && str[1] == '@' && WIDTH != 0)
		WIDTH = WIDTH + 1;
	if (WIDTH > ft_strlen(str))
	{
		tmp = ft_strnew(WIDTH + 1);
		if (form->opt && LALIGN == 1)
		{
			while (str[j])
				tmp[i++] = str[j++];
			while (i <= (WIDTH - 1))
				tmp[i++] = ' ';
		}
		else
		{
			while (i < (WIDTH - ft_strlen(str)))
				tmp[i++] = ' ';
			while (str[j])
				tmp[i++] = str[j++];
		}
		free(str);
		RESULT = tmp;
	}
}

static	void	applyprecisionfors(t_form *form, int i, int j, char *str)
{
	char	*tmp;

	tmp = ft_strnew(PRECI);
	if (PRECI > ft_strlen(str))
	{
		while (str[j])
			tmp[i++] = str[j++];
	}
	else
	{
		while (i < PRECI)
			tmp[i++] = str[j++];
	}
	free(str);
	RESULT = tmp;
}

static	void	applyprecision(t_form *form, int i, int j, char *str)
{
	int		k;
	char	*tmp;

	k = ft_strlen(str) - POSI - SPACE;
	if (str[0] == '-')
		PRECI = PRECI + 2;
	tmp = ft_strnew(PRECI + POSI + SPACE);
	if (POSI != 0)
		tmp[i++] = '+';
	if (SPACE != 0)
		tmp[i++] = ' ';
	if (str[0] == '-')
	{
		tmp[i++] = '-';
		j++;
	}
	while (i < (PRECI - k))
		tmp[i++] = '0';
	while (str[j])
		tmp[i++] = str[j++];
	free(str);
	RESULT = tmp;
}

void			applyformat(t_env *env)
{
	t_form	*form;

	form = env->form;
	while (form)
	{
		if (PRECI > 0 && CONV != 'c' && CONV != 'f')
		{
			if (CONV == 's')
				applyprecisionfors(form, 0, 0, RESULT);
			else if (PRECI > ft_strlen(RESULT))
				applyprecision(form, 0, 0, RESULT);
		}
		if (WIDTH != 0 && WIDTH > PRECI)
			applywidth(form, 0, 0, RESULT);
		if (WIDTH != 0 && CONV == 's' && WIDTH < PRECI)
			applywidth(form, 0, 0, RESULT);
		form = form->next;
	}
}
