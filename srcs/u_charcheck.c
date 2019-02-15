/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:41:46 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/04 19:32:50 by artprevo         ###   ########.fr       */
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

int		ft_isespace(char *str, int i)
{
	if (str[i++] == 'e')
	{
		if (str[i++] == 's')
		{
			if (str[i++] == 'p')
			{
				if (str[i++] == 'a')
				{
					if (str[i++] == 'c')
					{
						if (str[i] == 'e')
							return (1);
					}
				}
			}
		}
	}
	return (0);
}
