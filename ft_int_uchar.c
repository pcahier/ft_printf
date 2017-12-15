/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_uchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 04:09:14 by pcahier           #+#    #+#             */
/*   Updated: 2017/12/15 11:37:20 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_formatwchar(wint_t s, t_stru *stru, int fd)
{
	if (s >= 128 && s < 57344 && MB_CUR_MAX > 1)
	{
		stru->len = ft_printunsnumlen(s, 2);
		return (ft_printwchar(stru, s, fd));
	}
	else if (s >= 57344 && s < 65536 && MB_CUR_MAX > 2)
	{
		stru->len = ft_printunsnumlen(s, 2);
		return (ft_printwchar(stru, s, fd));
	}
	else if (s>= 65536 && MB_CUR_MAX > 3)
	{
		stru->len = ft_printunsnumlen(s, 2);
		return (ft_printwchar(stru, s, fd));
	}
	else if (s <= 127)
	{
		stru->len = s ? 1 : 0;
		return (ft_printchar(stru, s, fd));
	}
	return (-1);
}

static int		ft_formatchar(unsigned char s, t_stru *stru, int fd)
{
	stru->len = s ? 1 : 0;
	return (ft_printchar(stru, s, fd));
}

int			ft_int_uchar(const char *format, va_list *ap, int fd)
{
	t_stru			stru;
	unsigned int	c;

	ft_genbasestru(&stru, -1, 0);
	ft_analyseformat(&stru, format);
	ft_analyseformat2(&stru, format);
	ft_analyseformat3(&stru, format);
	if (stru.conv == 0)
	{
		c = va_arg(*ap, unsigned int);
		return (ft_formatchar((unsigned char)c, &stru, fd));
	}
	return (ft_formatwchar(va_arg(*ap, wint_t), &stru, fd));
}
