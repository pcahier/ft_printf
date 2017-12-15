/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrongconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:26:01 by pcahier           #+#    #+#             */
/*   Updated: 2017/12/10 20:35:47 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wrongconv(const char *format, int fd)
{
	char	flagset[] = "'-+ #0hljztL.*";
	char	flagset2[] = "'-+ #0hljztL.*123456789";
	int		i;
	int		j;
	int		ret;
	t_stru	stru;


	i = 0;
	j = 0;
	ret = 0;
	ft_genbasestru(&stru, 1, 1);
	ft_analyseformat(&stru, format);
	ft_analyseformat2(&stru, format);
	i = ft_strspn(format, flagset);
	if (format[i] >= '0' && format[i] <= '9')
		j = ft_atoi(format + i);
	i = ft_strspn(format, flagset2);
	return (ft_printchar(&stru, format[i], fd, j));
}
