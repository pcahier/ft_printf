/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_uchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 04:09:14 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/17 16:27:16 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_formatwchar(unsigned int s, t_stru *stru)
{
	char	len;

	if (s >= 128 && s < 2048)
		len = 2;
	else if (s >= 2048 && s < 65536)
		len = 3;
	else if (s >= 65536)
		len = 4;
	else if (s <= 127)
		len = 1;
	else
	{
		len = MB_CUR_MAX + 1;
		stru->len = -1;
	}
	//if (len > MB_CUR_MAX)
	//	return (-1);
	stru->len += len;
	return (len);
}
/*
int			ft_formatwchar(unsigned int s, t_stru *stru)
{
	if (s >= 128 && s < 2048 && MB_CUR_MAX > 1)
	{
		stru->len += 2;
		return (2);
	}
	else if (s >= 2048 && s < 65536 && MB_CUR_MAX > 2)
	{
		stru->len += 3;
		return (3);
	}
	else if (s >= 65536 && MB_CUR_MAX > 3)
	{
		stru->len += 4;
		return (4);
	}
	else if (s <= 127)
	{
		stru->len += 1;
		return (1);
	}
	else
		stru->len = -1;
	return (-1);
}
*/
int			ft_int_uchar(const char *format, va_list *ap, int fd)
{
	t_stru			stru;
	unsigned int	c;

	ft_genbasestru(&stru, -1, 0, format);
	ft_analyseformat3(&stru, format);
	ft_analyseformat2(&stru, format);
	ft_analyseformat(&stru, format);
	c = va_arg(*ap, unsigned int);
	if (stru.conv != 1)
	{
		stru.len += 1;
		return (ft_printchar(&stru, (unsigned char)c, fd));
	}
	else
		ft_formatwchar(c, &stru);
	return (ft_printchar(&stru, c, fd));
}
