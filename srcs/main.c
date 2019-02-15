/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:23:34 by jegloff           #+#    #+#             */
/*   Updated: 2019/02/15 19:06:00 by artprevo         ###   ########.fr       */
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
		
		tab = 0;
		ft_printf("%.4s\n", "salut");
		printf("%.4s\n", "salut");
	}
		return (0);
}
