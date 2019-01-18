/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:29:51 by jegloff           #+#    #+#             */
/*   Updated: 2019/01/18 16:06:00 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(char *str)
{
	t_env		*env;

	//initialiser les 4 structures
	//separer le char * qu'on nous envoie en maillons en se basant sur les %
	//stock chaque compartiment dans form->content
	//remplir les options et le format de chque t_form (sans l'argument)
	//stocker l'argument correspondant a chaque t_form dans une structure t_arg
	//trouver comment definir le type d'une variable. pointeur sur fonction ? iteratif ? boucle de if ?
	env = 0;
	str = 0;
	return (0);
}
