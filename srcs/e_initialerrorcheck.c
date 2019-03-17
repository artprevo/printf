/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_initialerrorcheck.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 20:36:15 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/26 19:45:14 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	initialerrorcheck(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			while (str[i++])
			{
				if (ft_typeconv(str[i]) == 1 || str[i] == '%')
					break ;
				if (i >= (ft_strlen(str) - 1))
					return (0);
			}
		}
		i++;
	}
	return (1);
}
