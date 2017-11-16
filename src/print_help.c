/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 03:33:48 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/16 03:48:39 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_help(void)
{
	ft_printf("%-22s : deplacement colonne\n", "shift + haut/bas");
	ft_printf("%-22s : deplacement mot\n", "shift + droite/gauche");
	ft_printf("%-22s : debut/fin de commande\n", "home/end");
	ft_printf("%-22s : debut/fin de ligne\n", "ctrl + a/e");
	ft_printf("%-22s : mode selection\n", "ctrl + space");
	ft_printf("%-22s : sortir mode selection\n", "ctrl + g");
	ft_printf("%-22s : couper\n", "ctrl + w");
	ft_printf("%-22s : copier\n", "alt + w");
	ft_printf("%-22s : coller\n", "ctrl + y");
	ft_printf("%-22s : historique\n", "haut/bas");
	ft_printf("%-22s : clear screen\n", "ctrl + l");
	ft_printf("%-22s : couper debut/fin de ligne\n", "ctrl + u/k");
	ft_printf("%-22s : delete ou exit si commande vide\n", "ctrl + d");
	ft_printf("%-22s : reset prompt\n", "ctrl + c");
}
