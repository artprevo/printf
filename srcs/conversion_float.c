/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:41:55 by jegloff           #+#    #+#             */
/*   Updated: 2019/02/25 15:54:52 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	fill_decimal_str(char *str_decimal, char *str_itoa)
{
	int		i;
	int		j;

	i = ft_strlen(str_decimal) - ft_strlen(str_itoa);
	j = 0;
	if (i < -1)
		return;
	if (str_itoa[0] == '-')
	{
		j++;
		i++;
	}
	while (str_decimal[i] && str_itoa[j])
		str_decimal[i++] = str_itoa[j++];
}

static char	*strjoin_double(char *dest, char *int_part, char *float_part)
{
	int		i;

	i = -1;
	while (++i < ft_strlen(int_part))
		dest[i] = int_part[i];
	dest[i++] = '.';
	i = -1;
	while (++i < ft_strlen(float_part))
		dest[i + ft_strlen(int_part) + 1] = float_part[i];
	free(int_part);
	free(float_part);
	return (dest);
}

static void	bzero_zero(char *str, int size)
{
	int		i;

	i = -1;
	while (++i < size - 1)
		str[i] = '0';
	str[i] = 0;
}

static char	*double_to_lstr(double f, int len)
{
	double	fractional;
	char	*str_integer;
	char	*str_decimal;
	char	*res;

	fractional = f - (int)f;
	str_integer = ft_dtoa((int)f, f);
	if ((res = malloc(sizeof(char) * (ft_strlen(str_integer) + len + 2))) == 0)
		return (NULL);
	if ((str_decimal = malloc(sizeof(char) * len + 1)) == 0)
		return (NULL);
	bzero_zero(res, ft_strlen(str_integer) + len + 2);
	bzero_zero(str_decimal, len + 1);
	if (len != 0)
	{
		fractional = fractional * ft_pow(10, len);
		if (f > 0)
			fill_decimal_str(str_decimal, ft_itoa((int)(fractional + 0.5)));
		else
			fill_decimal_str(str_decimal, ft_itoa((int)(fractional - 0.5)));
	}
	strjoin_double(res, str_integer, str_decimal);
	return (res);
}

char		*conv_float(double f, int preci)
{
	char	*str;

	str = double_to_lstr(f, preci);
	return (str);
}
