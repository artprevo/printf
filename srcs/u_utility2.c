/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_utility2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:43:25 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/15 16:49:29 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*strtostr(char *str)
{
	return (str);
}

char	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char *ptr1;
	char *ptr2;

	if (dst == src || n == 0)
		return (dst);
	ptr1 = (char*)dst;
	ptr2 = (char*)src;
	while (n--)
		*ptr1++ = *ptr2++;
	return (dst);
}

char	*convargp(intptr_t *ptr)
{
	unsigned long	adr;
	char const		*base;
	char			*res;
	int				i;

	res = ft_strnew(9);
	adr = (unsigned long) ptr;
	base = "0123456789abcdef";
	i = 8;
	while ((adr / 16) > 0 || i >= 8)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	return (res);
}
