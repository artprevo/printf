/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:41:46 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/27 22:27:27 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_typeconv(char c)
{
	if (c == 'd' || c == 'i' || c == 'f'\
			|| c == 'c' || c == 'u' || c == 'o' || c == 'x' || c == 'X' \
			|| c == 's' || c == 'p')
		return (1);
	return (0);
}

int		ft_isoption(char c)
{
	if (c == '-' || c == '+' || c == '#' || c == '0' || c == ' ')
		return (1);
	return (0);
}

int		ft_isnumber(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c += 32);
	return (c);
}

int		ft_typenumb(char c)
{
	if (c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return (1);
	return (0);
}
