/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:18:14 by pcahier           #+#    #+#             */
/*   Updated: 2017/12/15 19:34:35 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_formatintdec(intmax_t s, t_stru *stru)
{
	stru->len = ft_printdecnumlen(s);
	return (ft_itoa_print((intmax_t)s, stru));
}

int				ft_int_dec(const char *format, va_list *ap, int fd)
{
	t_stru		stru;
	intmax_t	s;
	char		*str;

	ft_genbasestru(&stru, -1, 0, format);
	ft_analyseformat(&stru, format);
	ft_analyseformat2(&stru, format);
	ft_analyseformat3(&stru, format);
	s = va_arg(*ap, intmax_t);
	if (stru.conv == 0)
		str = ft_formatintdec((int)s, &stru);
	if (stru.conv == 1)
		str = ft_formatintdec((long int)s, &stru);
	if (stru.conv == 2)
		str = ft_formatintdec((long long int)s, &stru);
	if (stru.conv == 3)
		str = ft_formatintdec(s, &stru);
	if (stru.conv == 4)
		str = ft_formatintdec((ssize_t)s, &stru);
	if (stru.conv == -1)
		str = ft_formatintdec((short)s, &stru);
	if (stru.conv == -2)
		str = ft_formatintdec((char)s, &stru);
	s = ft_strlen(str);
	ft_putstr_fd(str, fd);
	free(str);
	return (s);
}
