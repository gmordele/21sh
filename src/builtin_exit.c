/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 03:35:57 by gmordele          #+#    #+#             */
/*   Updated: 2018/01/11 19:08:33 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

int		builtin_exit(char **argv, char **env)
{
	free_string_arr(argv);
	free_string_arr(env);
	normal_exit();
	return (0);
}
