/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:23:34 by jegloff           #+#    #+#             */
/*   Updated: 2019/01/18 16:05:46 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int 	main(int ac, char **av)
{
	av = 0;
	if (ac > 1)
		ft_printf("tab1 = %ababababababababad %ababababababababababad");
	return 0;
}
