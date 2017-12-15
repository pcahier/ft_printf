/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsnumlen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:21:08 by pcahier           #+#    #+#             */
/*   Updated: 2017/12/12 17:48:40 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printunsnumlen(uintmax_t nb, int base)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (len + 1);
	while (nb != 0)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}
