/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_genprinstruc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:43:09 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/15 17:01:45 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_isconvflag(const char c)
{
	if (c == '\'' || c == '-' || c == '+' || c == ' ' || c == '#' || c == 'h' 
			|| c == 'l' || c == 'j' || c == 'z' || c == 't' || c == 'L' 
				|| c == '.' || c == '*' || ft_isdigit(c))
		return (1);
	return (0);
}

t_stru			*ft_analyseformat3(t_stru *stru, const char *format)
{
	while (ft_isconvflag(*format))
	{
		if ((*format < '1' || *format > '9') && *format != '.')
			format++;
		if (*format >= '1' && *format <= '9')
		{
			stru->wid_min = ft_atoi(format);
			while (*format >= '0' && *format <= '9')
				format++;
		}
		if (*format == '.')
		{
			stru->pre = ft_atoi(format + 1);
			stru->zero = 0;
			return (stru);
		}
	}
	return (stru);
}

t_stru			*ft_analyseformat2(t_stru *stru, const char *format)
{
	while (ft_isconvflag(*format))
		format++;
	if (*format == 'U' || *format == 'O' || *format == 'D' || *format == 'S' || *format == 'C')
		stru->conv = 1;
	else if (*format == 'p')
		stru->conv = 5;
	else if (format[-1] == 'l' && format[-2] == 'l')
		stru->conv = 2;
	else if (format[-1] == 'l')
		stru->conv = 1;
	else if (format[-1] == 'h' && format[-2] == 'h')
		stru->conv = -2;
	else if (format[-1] == 'h')
		stru->conv = -1;
	else if (format[-1] == 'j')
		stru->conv = 3;
	else if (format[-1] == 'z')
		stru->conv = 4;
	return (stru);
}

t_stru			*ft_analyseformat(t_stru *stru, const char *format)
{
	while (ft_isconvflag(*format))
	{
		if (*format == '0' && !(*(format - 1) == '.' || (*(format - 1) >= '0' && *(format - 1) <= '9')))
			stru->zero = 1;
		else if (*format == '-')
			stru->l_just = 1;
		else if (*format == '+')
			stru->sign = 2;
		else if (*format == ' ' && stru->sign < 2)
			stru->sign = 1;
		else if (*format == '#')
			stru->pound = 1;
		format++;
	}
	if (stru->l_just)
		stru->zero = 0;
	return (stru);
}

t_stru			*ft_genbasestru(t_stru *stru, size_t pre, size_t wid_min, 
					const char *format)
{
	stru->pre = pre;
	stru->wid_min = wid_min;
	stru->l_just = 0;
	stru->sign = 0;
	stru->zero = 0;
	stru->pound = 0;
	stru->conv = 0;
	stru->len = 0;
	stru->format = format;
	return (stru);
}
