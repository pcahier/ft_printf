/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 20:31:19 by pcahier           #+#    #+#             */
/*   Updated: 2017/12/10 20:37:13 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printchar(t_stru *stru, char c, int fd, int j)
{
	int		ret;

	ret = 0;
	if (!stru->l_just)
	{
		while (j > ret + 1 && !stru->zero)
			ret = ret + ft_putchar_fd(' ', fd);
		while (j > ret + 1 && stru->zero)
			ret = ret + ft_putchar_fd('0', fd);
	}
	ft_putchar_fd(c, fd);
	if (stru->l_just)
		while (j > ret + 1)
			ret = ret + ft_putchar_fd(' ', fd);
	return (ret + 1);
}
