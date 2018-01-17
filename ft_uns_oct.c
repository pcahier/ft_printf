/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:16:49 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/15 17:36:36 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_formatintdec(uintmax_t s, t_stru *stru)
{
	stru->len = ft_printunsnumlen(s, 8);
	return (ft_uitoa_print(s, stru, 8));
}

int				ft_uns_oct(const char *format, va_list *ap, int fd)
{
	t_stru		stru;
	uintmax_t	s;
	char		*str;

	ft_genbasestru(&stru, -1, 0, format);
	ft_analyseformat(&stru, format);
	ft_analyseformat2(&stru, format);
	ft_analyseformat3(&stru, format);
	s = va_arg(*ap, uintmax_t);
	if (stru.conv == 0)
		str = ft_formatintdec((unsigned int)s, &stru);
	if (stru.conv == 1)
		str = ft_formatintdec((unsigned long int)s, &stru);
	if (stru.conv == 2)
		str = ft_formatintdec((unsigned long long int)s, &stru);
	if (stru.conv == 3)
		str = ft_formatintdec(s, &stru);
	if (stru.conv == 4)
		str = ft_formatintdec((size_t)s, &stru);
	if (stru.conv == -1)
		str = ft_formatintdec((unsigned short int)s, &stru);
	if (stru.conv == -2)
		str = ft_formatintdec((unsigned char)s, &stru);
	s = ft_strlen(str);
	ft_putstr_fd(str, fd);
	free(str);
	return (s);
}
