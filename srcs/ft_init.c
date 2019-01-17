/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:02:43 by artprevo          #+#    #+#             */
/*   Updated: 2019/01/17 19:47:12 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_env	*ft_initenv(char *str)
{
	t_env	*new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	new->str = str;
	new->subs = NULL;
	new->form = NULL;
	return (new);
}

t_opt	*ft_initopt(char *str)
{
	t_opt	*new;

	str = 0;
	if (!(new = (t_opt *)malloc(sizeof(t_opt))))
		return (NULL);
	new->posi = 0;
	new->hash = 0;
	new->lzero = 0;
	new->space = 0;
	new->lalign = 0;
	return (new);
}

t_form	*ft_initform(char *str)
{
	t_form	*new;

	str = 0;
	if (!(new = (t_form *)malloc(sizeof(t_form))))
		return (NULL);
	new->id = 0;
	new->size = 48;
	new->width = 0;
	new->precision = 0;
	new->content = NULL;
	new->conversion = 0;
	new->argument = NULL;
	new->opt = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_env	*ft_processinit(char *str)
{
	t_env	*env;

	env = ft_initenv(str);
	return (env);
}
