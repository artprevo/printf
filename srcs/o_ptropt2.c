/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_ptropt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:19:27 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/06 14:54:51 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	oposineg(t_form *form, char *str, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = ft_strlen(str) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	tmp[i++] = '+';
	while (str[j])
		tmp[i++] = str[j++];
	while (i < width)
		tmp[i++] = ' ';
	free(str);
	form->result = tmp;
}

void	oposizero(t_form *form, char *str, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = ft_strlen(str) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	tmp[i++] = '+';
	while (i < width - ft_strlen(str))
		tmp[i++] = '0';
	while (str[j])
		tmp[i++] = str[j++];
	free(str);
	form->result = tmp;
}

void	onegspace(t_form *form, char *str, int width)
{
	int		i;
	int		j;
	char	*tmp;
	
	if (width == 0)
		width = ft_strlen(str) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	tmp[i++] = ' ';
	while (str[j])
		tmp[i++] = str[j++];
	while (i < width)
		tmp[i++] = ' ';
	free(str);
	form->result = tmp;
}

void	ozerospace(t_form *form, char *str, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = ft_strlen(str) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	tmp[i++] = ' ';
	while (i < (width - ft_strlen(str)))
		tmp[i++] = '0';
	while (str[j])
		tmp[i++] = str[j++];
	free(str);
	form->result = tmp;
}
