/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit_rest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:55:57 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/10 16:58:53 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

void		err_exit_rest(char *str)
{
	ft_dprintf(2, "%s\n", str);
	restore_term();
	exit(EXIT_FAILURE);
}
