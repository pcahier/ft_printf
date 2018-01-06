/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstringwchar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:12:02 by pcahier           #+#    #+#             */
/*   Updated: 2017/12/19 16:47:31 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printstringwchar(t_stru *stru, unsigned int *str, int fd)
{
	int		ret;
	int		check;

	ret = 0;
	check = 0;
	while (*str != '\0')
	{
		check = ft_formatwchar(*str, stru, fd);
		str++;
		ret += check;
	}
	return (ret);
}
