/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:28:43 by pcahier           #+#    #+#             */
/*   Updated: 2017/12/12 15:49:12 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printstru.h"

int		ft_vfprintf(int fd, const char *format, va_list *ap)
{
	int			i;
	int			a;
	int			ret;
	int			check;
	char		flagset[] = "'-+ #0hljztL.*123456789";
	
	ret = 0;
	while (*format)
	{
		i = 0;
		check = 0;
		if (*format != '%')
		{
			ft_putchar(*format);
			ret++;
		}
		if (format[i] == '%')
		{
			i = ft_strspn(format + 1, flagset) + 1;
			if (!format[i])
			{
				return (ret);
			}
			a = 0;
			while (a < 22)
			{
				if (format[i] == g_print[a].operat)
				{
					ret = ret + g_print[a].ft(format + 1, ap, fd);
					check = 1;
				}
				a++;
			}
			if (!check)
				ret = ret + ft_wrongconv(format + 1, fd);
		}
		format = format + i + 1;
	}
	return (ret);
}
