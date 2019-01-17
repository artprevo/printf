/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingform.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:41:10 by artprevo          #+#    #+#             */
/*   Updated: 2019/01/17 19:35:25 by artprevo         ###   ########.fr       */
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
		if (ft_isespace(str, i) == 1)
			opt->space = 1;
		if (str[i] == '-')
			opt->lalign = 1;
		i++;
	}
	printf("posi = %d\nhash = %d\nlzero = %d\nspace = %d\nlalign = %d\n", \
			opt->posi, opt->hash, opt->lzero, opt->space, opt->lalign);
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
		printf("j = %d\n", j);
		while (str[i] >= '0' && str[i] <= '9')
			j = j * 10 + str[i++] - '0';
		new->width = j;
	}
	if (str[i] == '.')
	{
		i++;
		new->precision = str[i++] - '0';
	}
	if (str[i] == 'h' || str[i] == 'l' || str[i] == 'L')
		new->size = str[i++];
	while (str[i])
		i++;
	new->conversion = str[i - 1];
	printf ("id = %d\nsize = %c\nwidth = %d\nprecision = %d\nconversion = %c\ncontent = %s\n", new->id, new->size, new->width, new->precision, \
			new->conversion, new->content);
//	ft_error("bad conversion character");
}

static	void	parse_form_content(t_form *new)
{
	char	*str;

	str = new->content;
	parseform(new, str);
	parseopt(new, str);
	printf ("\nAU SUIVANT\n\n");
}

void			fill_t_form(t_env *env)
{
	t_form	*new;

	new = env->form;
	while (new)
	{
		parse_form_content(new);
		new = new->next;
	}
}
