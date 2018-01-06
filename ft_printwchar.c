/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 07:11:09 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/05 17:48:51 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fourbytes(t_stru *stru, unsigned int s, int fd)
{
	unsigned char	tab[4];
	int				i;

	(void)stru;
	(void)fd;
	tab[3] = 128;
	tab[2] = 128;
	tab[1] = 128;
	tab[0] = 240;
	i = 0;
	tab[3] += s % 64;
	s /= 64;
	tab[2] += s % 64;
	s /= 64;
	tab[1] += s % 64;
	s /= 64;
	tab[0] += s;
	write(1, tab, 4);
	return (4);
}

static int	ft_threebytes(t_stru *stru, unsigned int s, int fd)
{
	unsigned char	tab[3];
	int				i;

	(void)fd;
	(void)stru;
	tab[2] = 128;
	tab[1] = 128;
	tab[0] = 224;
	i = 0;
	tab[2] += s % 64;
	s /= 64;
	tab[1] += s % 64;
	s /= 64;
	tab[0] += s;
	write(1, tab, 3);
	return (3);
}

static int	ft_twobytes(t_stru *stru, unsigned int  s, int fd)
{
	unsigned char	tab[2];
	int				i;

	(void)fd;
	(void)stru;
	tab[1] = 128;
	tab[0] = 192;
	i = 0;
	tab[1] += s % 64;
	s /= 64;
	tab[0] += s;
	write(1, tab, 2);
	return (2);
}

int			ft_printwchar(t_stru *stru, unsigned int s, int fd)
{
	if (stru->len <= 11)
		return (ft_twobytes(stru, s, fd));
	else if (stru->len <= 16)
		return (ft_threebytes(stru, s, fd));
	else
		return (ft_fourbytes(stru, s, fd));
}
