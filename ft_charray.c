/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:37:18 by pcahier           #+#    #+#             */
/*   Updated: 2017/12/15 11:07:44 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_charray(const char *format, va_list *ap, int fd)
{
	t_stru	stru;
	char	*str;
		
	str = va_arg(*ap, char *);
	if (str == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	ft_genbasestru(&stru, ft_strlen(str), 0);
	ft_analyseformat(&stru, format);
	ft_analyseformat2(&stru, format);
	ft_analyseformat3(&stru, format);
	if (stru.conv == 0)
		return (ft_printstring(&stru, str, fd));
	return (ft_printstring(&stru, str, fd));
}
