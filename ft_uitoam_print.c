/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoam_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 02:12:52 by pcahier           #+#    #+#             */
/*   Updated: 2017/12/15 02:22:24 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_itoa_print_form(char *str, size_t len, t_stru *stru, int base)
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
		stru->wid_min--;
	}
	if (stru->pound == 1 && str[0] != '0' && (base == 8 || (base == 16 && *str)))
		strr[i++] = '0';
	if (stru->pound == 1 && base == 16 && str[0] != '0' && *str)
		strr[i++] = 'X';
	while (stru->zero && stru->wid_min)
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

static char		*ft_itoa_print_forml(char *str, size_t len, t_stru *stru, int base)
{
	char			*strr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!(strr = (char*)ft_memalloc(sizeof(char) * (len + stru->wid_min + 1))))
		return (NULL);
	if (stru->pound == 1 && str[0] != '0' && (base == 8 || (base == 16 && *str)))
		strr[i++] = '0';
	if (stru->pound == 1 && base == 16 && str[0] != '0' && *str)
		strr[i++] = 'X';
	while (stru->zero && stru->wid_min)
	{
		strr[i++] = '0';
		stru->wid_min--;
	}
	while (str[j] != '\0')
		strr[i++] = str[j++];
	while (!stru->zero && stru->wid_min)
	{
		strr[i++] = ' ';
		stru->wid_min--;
	}
	free(str);
	return (strr);
}

static char		*ft_itoarev(char *str, unsigned int len, t_stru *stru, int base)
{
	size_t		i;
	char		*strr;

	i = 0;
	if (!(strr = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len - i > 0)
	{
		strr[i] = str[(len - 1 - i)];
		i++;
	}
	strr[i] = '\0';
	free(str);
	stru->len = ft_strlen(strr);
	if (base == 16 && stru->pound == 1)
		stru->len += 2;
	if (base == 8 && stru->pound == 1)
		stru->len++;
	if (stru->len < stru->wid_min)
		stru->wid_min -= stru->len;
	else
		stru->wid_min = 0;
	if (stru->l_just)
		return (ft_itoa_print_forml(strr, i, stru, base));
	else
		return (ft_itoa_print_form(strr, i, stru, base));
}

static char		*ft_itoafill(char *str, uintmax_t n, unsigned int i, t_stru *stru, int base)
{
	while (n > 0)
	{
		str[i] = (n % base) + ((n % base) > 9 ? 55 : 48);
		n = n / base;
		i++;
	}
	while (stru->pre > stru->len)
	{
		str[i++] = '0';
		stru->pre--;
	}
	return (ft_itoarev(str, i, stru, base));
}

char			*ft_uitoam_print(uintmax_t n, t_stru *stru, int base)
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
	return (ft_itoafill(str, n, i, stru, base));
}
