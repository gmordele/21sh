/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pressed_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 11:55:17 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/06 01:24:34 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			cmd_pressed_key(int n, char *read_buf)
{
	if (n == 1)
		return (cmd_pressed_key_n_1(read_buf));
	if (n == 3)
		return (cmd_pressed_key_n_3(read_buf));
	if (n == 4)
		return (cmd_pressed_key_n_4(read_buf));
	if (n == 6)
		return (cmd_pressed_key_n_6(read_buf));
	return (0);
}
