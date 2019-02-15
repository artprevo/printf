/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_ptropt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 20:28:52 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/15 16:05:45 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	oposi(t_form *form, char *str, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = ft_strlen(str) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	while (i < (width - ft_strlen(str)) - 1)
		tmp[i++] = ' ';
	tmp[i++] = '+';
	while (str[j])
		tmp[i++] = str[j++];
	free(str);
	form->result = tmp;
}

/* a quoi sert le # ????? */
void	ohash(t_form *form, char *str, int width)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	while (i < (width - ft_strlen(str)) - 1)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i++] = '+';
	while (str[j])
		tmp[i++] = str[j++];
	free(str);
	form->result = tmp;
}

void	olzero(t_form *form, char *str, int width)
{
	int		i;
	int		j;
	char	*tmp;
	
	if (width == 0)
		width = ft_strlen(str);
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	while (i < (width - ft_strlen(str)))
		tmp[i++] = '0';
	while (str[j])
		tmp[i++] = str[j++];
	free(str);
	form->result = tmp;
}

void	ospace(t_form *form, char *str, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = ft_strlen(str) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	while (i < (width - ft_strlen(str)))
		tmp[i++] = ' ';
	while (str[j])
		tmp[i++] = str[j++];
	free(str);
	form->result = tmp;
}

void	olalign(t_form *form, char *str, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = ft_strlen(str);
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	while (str[j])
		tmp[i++] = str[j++];
	while (i < width)
		tmp[i++] = ' ';
	free(str);
	form->result = tmp;
}
