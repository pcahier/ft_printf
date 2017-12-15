/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_genprinstruc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:43:09 by pcahier           #+#    #+#             */
/*   Updated: 2017/12/15 11:07:10 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_stru	*ft_analyseformat3(t_stru *stru, const char *format)
{
	while(*format != 'd' && *format != 'i' && *format != 'u' && *format != 'x' && *format != 'X' && *format != 'o' && *format != 's' && *format != 'c' && *format != 'U' && *format != 'O' && *format != 'D' && *format != 'p' && *format != 'S')
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
			return (stru);
		}
	}
	return (stru);
}
t_stru	*ft_analyseformat2(t_stru *stru, const char *format)
{
	while(*format != 'd' && *format != 'i' && *format != 'u' && *format != 'x' && *format != 'X' && *format != 'o' && *format != 's' && *format != 'c' && *format != 'U' && *format != 'O' && *format != 'D' && *format != 'p' && *format != 'S')  
		format ++;
	if (*format == 'U' || *format == 'O' || *format == 'D' || *format == 'S')
		stru->conv = 1;
	else if (*format == 'p')
		stru->conv = 5;
	else if (format[-1] == 'l' && format[-2] == 'l')
		stru->conv = 2;
	else if (format[-1] == 'l')
		stru->conv = 1;
	else if (format[-1] == 'h' && format [-2] == 'h')
		stru->conv = -2;
	else if (format[-1] == 'h')
		stru->conv = -1;
	else if (format[-1] == 'j')
		stru->conv = 3;
	else if (format[-1] == 'z')
		stru->conv = 4;
	return (stru);
}

t_stru	*ft_analyseformat(t_stru *stru, const char *format)
{
	while(*format != 'd' && *format != 'i' && *format != 's' && *format != 'u' && *format != 'x' && *format != 'X' && *format != 'o' && *format != 'c' && *format != 'U' && *format != 'O' && *format != 'D' && *format != 'p' && *format != 'S')
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

t_stru	*ft_genbasestru(t_stru *stru, size_t pre, size_t wid_min)
{
	stru->pre = pre;
	stru->wid_min = wid_min;
	stru->l_just = 0;
	stru->sign = 0; // 1 pour space et 2 pour +
	stru->zero = 0;
	stru->pound = 0;
	stru->conv = 0;  //pour l, et autres len_modifiers.
	stru->len = 0;
	return (stru);
}
