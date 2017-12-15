/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_uchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 04:09:14 by pcahier           #+#    #+#             */
/*   Updated: 2017/12/15 04:25:42 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_formatwchar(wint_t s, t_stru *stru)
{
	stru->len = ft_printunsnumlen(s, 10);
	return (ft_uitoa_print(s, stru, 10));
}

static int		ft_formatchar(unsigned char s, t_stru *stru, int fd)
{
	stru->len = s ? 1 : 0;
	return (ft_printchar(stru, s, fd, stru->wid_min));
}

int			ft_int_uchar(const char *format, va_list *ap, int fd)
{
	t_stru			stru;
	int				s;
	unsigned int	c;
	char			*str;

	ft_genbasestru(&stru, -1, 0);
	ft_analyseformat(&stru, format);
	ft_analyseformat2(&stru, format);
	ft_analyseformat3(&stru, format);
	if (stru.conv == 0)
	{
		c = va_arg(*ap, unsigned int);
		return (ft_formatchar((unsigned char)c, &stru, fd));
	}
	str = ft_formatwchar(va_arg(*ap, wint_t), &stru);
	s = ft_strlen(str);
	ft_putstr_fd(str, fd);
	free(str);
	return (s);
}
