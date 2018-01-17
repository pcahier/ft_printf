/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrongconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:26:01 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/17 15:40:41 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wrongconv(const char *format, int fd)
{
	char	flagset2[] = "'-+ #0hljztL.*123456789";
	int		i;
	int		ret;
	t_stru	stru;

	i = 0;
	ret = 0;
	ft_genbasestru(&stru, 1, 0, format);
	ft_analyseformat3(&stru, format);
	ft_analyseformat2(&stru, format);
	ft_analyseformat(&stru, format);
	i = ft_strspn(format, flagset2);
	stru.len = format[i] ? 1 : 0;
	return (ft_printchar(&stru, format[i], fd));
}
