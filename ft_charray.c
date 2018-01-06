/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:37:18 by pcahier           #+#    #+#             */
/*   Updated: 2017/12/19 16:50:35 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_charray(const char *format, va_list *ap, int fd)
{
	t_stru	stru;
	unsigned int *str;

	str = va_arg(*ap, unsigned int*);
	if (str != NULL)
		ft_genbasestru(&stru, ft_strlen((char*)str), 0, format);
	else
		ft_genbasestru(&stru, 6, 0, format);
	ft_analyseformat(&stru, format);
	ft_analyseformat2(&stru, format);
	ft_analyseformat3(&stru, format);
	if (str == NULL)
		return (ft_printstring(&stru, "(null)", fd));
	if (stru.conv == 0)
		return (ft_printstring(&stru, (char*)str, fd));
	return (ft_printstringwchar(&stru, str, fd));
}
