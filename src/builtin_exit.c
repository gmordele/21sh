/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 03:35:57 by gmordele          #+#    #+#             */
/*   Updated: 2018/01/11 04:22:13 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

int		builtin_exit(char **argv)
{
	if (argv != NULL)
		while (*argv != NULL)
		{
			free(*argv);
			++argv;
		}
	normal_exit();
	return (0);
}
