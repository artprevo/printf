/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingform.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:41:10 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/28 17:28:33 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	void	parseopt(t_form *new, char *str)
{
	t_opt	*opt;
	int		i;

	opt = ft_initopt(str);
	new->opt = opt;
	i = 1;
	while (ft_isoption(str[i]) == 1)
	{
		if (str[i] == '+')
			opt->posi = 1;
		if (str[i] == '#')
			opt->hash = 1;
		if (str[i] == '0')
			opt->lzero = 1;
		if (str[i] == ' ')
			opt->space = 1;
		if (str[i] == '-')
			opt->lalign = 1;
		i++;
	}
}

static	void	parseform2(t_form *new, char *str, int i)
{
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			new->precision = new->precision * 10 + (str[i] - 48);
			i++;
		}
		new->precision = (new->precision == 0) ? -1 : new->precision;
	}
	if (str[i] == 'h' || str[i] == 'l' || str[i] == 'L')
	{
		new->size = str[i++];
		if (str[i] == str[i - 1] && str[i] == 'h')
			new->size = 'H';
		else if (str[i] == str[i - 1] && str[i] == 'l')
			new->size = 'M';
	}
	while (str[i])
		i++;
	new->conversion = str[i - 1];
}

static	void	parseform(t_form *new, char *str)
{
	int		i;
	int		j;

	i = 1;
	while (ft_isoption(str[i]) == 1)
		i++;
	if (str[i] >= '0' && str[i] <= '9')
	{
		j = str[i++] - '0';
		while (str[i] >= '0' && str[i] <= '9')
			j = j * 10 + str[i++] - '0';
		new->width = j;
	}
	parseform2(new, str, i);
}

static	void	parse_form_content(t_form *new)
{
	char	*str;

	str = new->content;
	parseform(new, str);
	parseopt(new, str);
}

void			fill_t_form(t_env *env)
{
	t_form	*new;

	new = env->form;
	while (new)
	{
		if (new->type == 1)
			parse_form_content(new);
		new = new->next;
	}
}
