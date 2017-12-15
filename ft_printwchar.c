/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 07:11:09 by pcahier           #+#    #+#             */
/*   Updated: 2017/12/15 10:21:30 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fourbytes(t_stru *stru, wint_t s, int fd)
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
	while(i < 6)
		tab[3] += (s & (1 << i++));
	s /= 64;
	while (i < 12)
		tab[2] += (s & (1 << ((i++) - 6)));
	s /= 64;
	while (i < 18)
		tab[1] += (s & (1 << ((i++) - 12)));
	s /= 64;
	while (i < 21)
		tab[0] += (s & (1 << ((i++) - 18)));
	write(1, &tab[0], 1);
	write(1, &tab[1], 1);
	write(1, &tab[2], 1);
	write(1, &tab[3], 1);
	return (4);
}

static int	ft_threebytes(t_stru *stru, wint_t s, int fd)
{
	unsigned char 	tab[3];
	int				i;

	(void)fd;
	(void)stru;
	tab[2] = 128;
	tab[1] = 128;
	tab[0] = 224;
	i = 0;
	while (i < 6)
		tab[2] += (s & (1 << i++));
	s /= 64;
	while (i < 12)
		tab[1] += (s & (1 << ((i++) - 6)));
	s /= 64;
	while (i < 16)
		tab[0] += (s & (1 << ((i++) - 12)));
	write(1, &tab[0], 1);
	write(1, &tab[1], 1);
	write(1, &tab[2], 1);
	return (3);
}

static int	ft_twobytes(t_stru *stru, wint_t s, int fd)
{
	unsigned char 	tab[2];
	int				i;

	(void)fd;
	(void)stru;
	tab[1] = 128;
	tab[0] = 192;
	i = 0;
	while (i < 6)
		tab[1] += (s & (1 << i++));
	s /= 64;
	while (i < 11)
		tab[0] += (s & (1 << ((i++) - 6)));
	write(1, &tab[0], 1);
	write(1, &tab[1], 1);
	return (2);
}

int			ft_printwchar(t_stru *stru, wint_t s, int fd)
{
	if (stru->len <= 11)
		return (ft_twobytes(stru, s, fd));
	else if (stru->len <= 16)
		return (ft_threebytes(stru, s, fd));
	else
		return (ft_fourbytes(stru, s, fd));
}
