/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:54:25 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/27 20:16:31 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static unsigned long long		ft_powpow(unsigned long long nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char							*itoabase(unsigned long long int nb, int base)
{
	int		i;
	char	*res;

	i = (nb > 9) ? 2 : 1;
	if (nb == 0)
		return (ft_strdup("0"));
	while (ft_powpow(base, i) - 1 < nb)
		i++;
	if (!(res = (char*)malloc(sizeof(res) * i)))
		return (NULL);
	res[i] = '\0';
	while (i-- > 0)
	{
		res[i] = (nb % base) + (nb % base > 9 ? 'A' - 10 : '0');
		nb = nb / base;
	}
	return (res);
}

char							*lltoa(long long val, int base)
{
	char		*res;
	int			len;
	int			sign;
	long long	n;

	len = 1;
	sign = (val < 0) ? 1 : 0;
	if (sign == 1)
		val = -val;
	n = val;
	if (val == 0)
		return (ft_strdup("0"));
	while (n /= base)
		len++;
	if (!(res = (char *)malloc(sizeof(char) * (len + sign + 1))))
		return (NULL);
	res[len + sign] = '\0';
	res[0] = '-';
	while (len-- > 0)
	{
		res[len + sign] = "0123456789abcdef"[val % base];
		val /= base;
	}
	return (res);
}
