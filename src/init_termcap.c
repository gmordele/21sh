/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_termcap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 19:24:43 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/11 19:37:35 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdlib.h>
#include "header.h"
#include "libft.h"

void	init_termcap(void)
{
	char	*term_type;
	
	if ((term_type = getenv("TERM")) == NULL)
		err_exit_rest("Error getenv");
	if (tgetent(NULL, term_type) <= 0)
		err_exit_rest("Error tgetent");
	enter_insert();
}
