/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:42:00 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/15 16:49:27 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strnew(int size)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*chartostr(int d)
{
	char	*str;
	char	c;

	c = d;
	str = ft_strnew(1);
	str[0] = c;
	return (str);
}

char	*ft_strcpy(char *dst, char *src)
{
	size_t i;

	i = ft_strlen(src);
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (dst - i);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	i;

	i = ft_strlen(s1) + 1;
	if (!(s2 = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}

char	*ft_strdup_free(char *content, int r)
{
	char	*tmp;

	tmp = content;
	content = ft_strdup(content + r);
	free(tmp);
	return (content);
}
