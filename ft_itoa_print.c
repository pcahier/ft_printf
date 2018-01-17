/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:38:24 by pcahier           #+#    #+#             */
/*   Updated: 2017/12/15 02:13:37 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void		ft_putsign(char *s, unsigned int neg, t_stru *stru)
{
	if (stru->sign == 1 && !neg)
		*s = ' ';
	else if (stru->sign == 2 && !neg)
		*s = '+';
	else if (neg)
		*s = '-';
}

static char		*ft_itoa_print_form(char *str, size_t len, unsigned int neg, t_stru *stru)
{
	char			*strr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!(strr = (char*)ft_memalloc(sizeof(char) * (len + stru->wid_min + 1))))
		return (NULL);
	while ((!stru->zero || stru->pre != -1) && stru->wid_min > 0)
	{
		strr[i++] = ' ';
		stru->wid_min = stru->wid_min - 1;
	}
	ft_putsign(&strr[i], neg, stru);
	if (stru->sign != 0 || neg)
		i++;
	while (stru->zero && stru->wid_min && stru->pre == -1)
	{
		strr[i++] = '0';
		stru->wid_min--;
	}
	while (str[j] != '\0')
	{
		strr[i++] = str[j++];
	}
	strr[i] = '\0';
	free(str);
	return (strr);
}

static char		*ft_itoa_print_forml(char *str, size_t len, unsigned int neg, t_stru *stru)
{
	char			*strr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!(strr = (char*)ft_memalloc(sizeof(char) * (len + stru->wid_min + 1))))
		return (NULL);
	ft_putsign(&strr[i], neg, stru);
	if (stru->sign != 0 || neg)
		i++;
	while (stru->zero && stru->wid_min && stru->pre == -1)
	{
		strr[i++] = '0';
		stru->wid_min--;
	}
	while (str[j])
		strr[i++] = str[j++];
	while (!stru->zero && stru->wid_min)
	{
		strr[i++] = ' ';
		stru->wid_min--;
	}
	strr[i] = '\0';
	free(str);
	return (strr);
}

static char		*ft_itoarev(char *str, unsigned int len, unsigned int neg, t_stru *stru)
{
	size_t		i;
	char		*strr;

	i = 0;
	if (!(strr = (char*)ft_memalloc(sizeof(char) * (len + stru->pre + 1))))
		return (NULL);
	while (len - i > 0)
	{
		strr[i] = str[(len - 1 - i)];
		i++;
	}
	strr[i] = '\0';
	free(str);
	stru->len = ft_strlen(strr);
	if (stru->len < stru->wid_min)
	{
		stru->wid_min -= stru->len;
		stru->wid_min -= ((stru->sign || neg) ? 1 : 0);
	}
	else
		stru->wid_min = 0;
	if (stru->l_just)
		return (ft_itoa_print_forml(strr, i, neg, stru));
	else
		return (ft_itoa_print_form(strr, i, neg, stru));
}

static char		*ft_itoafill(char *str, intmax_t n, unsigned int i, t_stru *stru)
{
	unsigned int	neg;

	neg = 0;
	if (n < 0)
	{
		neg = 1;
		i++;
	}
	else
		n = -n;
	while (n < 0)
	{
		str[i] = (-(n % 10) + 48);
		n = n / 10;
		i++;
	}
	while (stru->pre > (stru->len - (int)neg))
	{
		str[i++] = '0';
		stru->pre--;
	}
	return (ft_itoarev(str, i, neg, stru));
}

char			*ft_itoa_print(intmax_t n, t_stru *stru)
{
	uintmax_t		i;
	char			*str;
	unsigned int	neg;

	neg = 0;
	if (!(str = (char*)ft_memalloc(sizeof(char) * (stru->len + stru->pre + 1))))
		return (NULL);
	i = 0;
	if (n == 0 && stru->pre)
	{
		str[0] = '0';
		i++;
	}
	return (ft_itoafill(str, n, i, stru));
}
