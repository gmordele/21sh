/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit_rest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:55:57 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/11 19:29:14 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

void		err_exit_rest(char *str)
{
	t_env_lst **env_lst;

	(void)env_lst;
	env_lst = sta_env_lst(NULL);
//	env_lst_free(env_lst);
	ft_dprintf(2, "%s\n", str);
	restore_term();
	exit(EXIT_FAILURE);
}
