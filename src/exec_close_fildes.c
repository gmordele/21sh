/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_close_fildes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 02:42:52 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/14 02:44:20 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	exec_close_fildes(void)
{
	int i;

	i = 3;
	while (i < 1000)
		close(i++);
}
