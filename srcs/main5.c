/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:23:34 by jegloff           #+#    #+#             */
/*   Updated: 2019/09/14 16:26:12 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int 	main(int ac, char **av)
{
	av = 0;
	if (ac > 1)
	{
		void	*tab;

		tab = "ouais";
		ft_printf("-42");
		ft_printf("salut");
		ft_printf("\n");
		ft_printf("%ce-Souleve\n", 'J');
		printf("%ce-Souleve\n\n", 'J');
		ft_printf("%s%s%s%s%s%s%s%s\n", "oui", "oui", "oui", "oui", "oui", "oui", "oui", "oui");
		printf("%s%s%s%s%s%s%s%s\n\n", "oui", "oui", "oui", "oui", "oui", "oui", "oui", "oui");
		ft_printf("%d%d%d%d%d%d%d%d%dsalut%c%ssalut\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, '\n', "OUI C MOI\n");
		printf("%d%d%d%d%d%d%d%d%dsalut%c%ssalut\n\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, '\n', "OUI C MOI\n");
		ft_printf("%.4s\n", "qui pensent");
		printf("%.4s\n\n", "qui pensent");
		ft_printf("que print%s", "F\n");
		printf("que print%s\n", "F\n");
		ft_printf("h%dh3\n", 3);
		printf("h%dh3\n\n", 3);
		ft_printf("c'%s dur%soui\n", "est", "oui");
		printf("c'%s dur%soui\n\n", "est", "oui");
		ft_printf("%+5.4d\n", 42);
		printf("%+5.4d\n\n", 42);
		ft_printf("solu%p\n", tab);
		printf("solu%p\n\n", tab);
		ft_printf("%X\n", 11111111);
		printf("%X\n", 11111111);
		printf("%-10s is a string\n", "this");
		ft_printf("%-10s is a string\n", "this");
		printf("%-50.3d is a string\n", 42);
		ft_printf("%-50.3d is a string\n", 42);
		
	}
	if (ac == 2)
	{
	unsigned long long int	i = -922337203685;
	unsigned long		j = -42;
	unsigned int		h = -2500;
		
		printf("------------------------\n");
		printf("le printf = %d\n", h);
		ft_printf("ft_printf = %d\n", h);
		printf("le printf = %x\n", h);
		ft_printf("ft_printf = %x\n", h);
		printf("le printf = %o\n", h);
		ft_printf("ft_printf = %o\n", h);
		printf("le printf = %X\n", h);
		ft_printf("ft_printf = %X\n", h);
		printf("le printf = %u\n", h);
		ft_printf("ft_printf = %u\n", h);
		printf("------------------------\n");
		printf("le printf = %ld\n", j);
		ft_printf("ft_printf = %ld\n", j);
		printf("le printf = %lx\n", j);
		ft_printf("ft_printf = %lx\n", j);
		printf("le printf = %lo\n", j);
		ft_printf("ft_printf = %lo\n", j);
		printf("le printf = %lX\n", j);
		ft_printf("ft_printf = %lX\n", j);
		printf("le printf = %lu\n", j);
		ft_printf("ft_printf = %lu\n", j);
		printf("------------------------\n");
		printf("le printf = %lld\n", i);
		ft_printf("ft_printf = %lld\n", i);
		printf("le printf = %llx\n", i);
		ft_printf("ft_printf = %llx\n", i);
		printf("le printf = %llo\n", i);
		ft_printf("ft_printf = %llo\n", i);
		printf("le printf = %llX\n", i);
		ft_printf("ft_printf = %llX\n", i);
		printf("le printf = %llu\n", i);
		ft_printf("ft_printf = %llu\n", i);
	}
	printf("%lld", -9223372036854775808);
	ft_printf("%lld", -9223372036854775808);
	return (0);
}
