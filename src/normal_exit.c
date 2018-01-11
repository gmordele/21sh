/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 10:53:43 by gmordele          #+#    #+#             */
/*   Updated: 2018/01/11 19:13:22 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void	normal_exit(void)
{
	t_ast_lst	**ast_lst;

	ast_lst = ast_lst_sta(NULL, 0);
	if (ast_lst != NULL)
		parser_free(ast_lst);
	env_lst_free();
	hist_lst_save();
	hist_lst_free();
	restore_term();
	exit(EXIT_SUCCESS);
}
