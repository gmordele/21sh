/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 17:41:06 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/10 17:49:39 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"
#include "libft.h"

void	print_keys(void)
{
	ssize_t n;
	char	buf[1024];
	int		first;
	int		i;

	if ((n = read(0, buf, 1024)) <= 0)
		err_exit("Error read");
	ft_printf("n = %d ", n);
	first = 1;
	i = 0;
	while (i < n)
	{
		if (first)
			first = 0;
		else
			ft_printf(" ");
		ft_printf("[%d]", buf[i++]);
	}
	ft_printf("\n");
}
