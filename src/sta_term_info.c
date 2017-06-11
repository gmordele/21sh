/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sta_term_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:10:33 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/10 16:54:06 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

t_term_info	*sta_term_info(t_term_info *term)
{
	static t_term_info	*sta_term = NULL;

	if (term != NULL)
		sta_term = term;
	else
		if (sta_term == NULL)
			err_exit("Error sta_term_info");
	return (sta_term);
}
