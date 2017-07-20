/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_print_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 17:35:28 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/18 17:47:46 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		cmd_print_line(char *s)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		++len;
		++i;
	}
	write(1, s, len);
	return (len);
}