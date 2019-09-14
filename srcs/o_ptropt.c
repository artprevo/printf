/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_ptropt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 20:28:52 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/12 19:37:22 by artprevo         ###   ########.fr       */
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
	RESULT = tmp;
}

void	ohash(t_form *form, char *str, int width)
{
	int		i;
	int		j;
	char	*tmp;

	i = 2;
	j = 0;
	if (width != 0)
		tmp = ft_strnew(width);
	else
		tmp = ft_strnew(ft_strlen(str) + 2);
	tmp[0] = '0';
	tmp[1] = CONV;
	if (CONV == 'o')
		i--;
	if (LZERO != 0)
	{
		while (i < width - ft_strlen(str))
			tmp[i++] = '0';
	}
	while (str[j])
		tmp[i++] = str[j++];
	free(str);
	RESULT = tmp;
}

void	olzero(t_form *form, char *str, int width)
{
	int		i;
	int		j;
	char	*tmp;
	int		neg;

	if (width == 0)
		width = ft_strlen(str);
	i = 0;
	j = 0;
	neg = 0;
	tmp = ft_strnew(width);
	if (str[j] == '-')
	{
		tmp[i++] = '-';
		j++;
		neg++;
	}
	while (i < (width - ft_strlen(str) + neg))
		tmp[i++] = '0';
	while (str[j])
		tmp[i++] = str[j++];
	free(str);
	RESULT = tmp;
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
	RESULT = tmp;
}

void	olalign(t_form *form, char *str, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0 || width < ft_strlen(str))
		width = ft_strlen(str);
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	while (str[j])
		tmp[i++] = str[j++];
	while (i < width)
		tmp[i++] = ' ';
	free(str);
	RESULT = tmp;
}
