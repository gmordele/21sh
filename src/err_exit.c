/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:55:57 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/25 15:40:40 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

void		err_exit(char *str)
{
	env_lst_free();
	ft_dprintf(2, "%s\n", str);
	restore_term();
	exit(EXIT_FAILURE);
}
