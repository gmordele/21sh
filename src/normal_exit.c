/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 10:53:43 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/09 03:05:11 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void	normal_exit(void)
{
	env_lst_free();
	hist_lst_save();
	hist_lst_free();
	restore_term();
	exit(EXIT_SUCCESS);
}
