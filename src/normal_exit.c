/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 10:53:43 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/11 18:48:57 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void	normal_exit(void)
{
	t_env_lst **env_lst;

	env_lst = sta_env_lst(NULL);
	env_lst_free(env_lst);
	restore_term();
	exit(EXIT_SUCCESS);
}
