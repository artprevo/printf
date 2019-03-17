/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_utility_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:36:47 by jegloff           #+#    #+#             */
/*   Updated: 2019/02/25 15:54:07 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

double			ft_pow(double nb, int len)
{
	int		i;
	double	tmp;

	tmp = nb;
	i = 0;
	while (++i < len)
		nb *= tmp;
	return (nb);
}

static int		ft_nlen(int n)
{
	int	i;

	i = 0;
	while (n /= 10)
	{
		if ((int)n == 0)
			break ;
		i++;
	}
	return (i);
}

static int	read_neg_bit(double f)
{
	unsigned long long *double_to_int;
	int i;

	i = 0;
	double_to_int = (unsigned long long *)&f;
	if ((*double_to_int >> 63) & 1)
		return (1);
	else
		return (0);
}

char			*ft_dtoa(int n, double f)
{
	char	*new;
	int		len;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = read_neg_bit(f);
	len = ft_nlen(n) + 1;
	if (sign == 1 && n < 0)
		n = -n;
	if (!(new = (char *)malloc(sizeof(char) * ((len + sign) + 1))))
		return (NULL);
	new[len + sign] = '\0';
	while ((len + sign) > 0)
	{
		new[(len + sign) - 1] = n % 10 + '0';
		len--;
		n /= 10;
	}
	if (sign == 1)
		new[0] = '-';
	return (new);
}
