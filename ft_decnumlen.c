/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decnumlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 20:14:14 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/22 20:19:22 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_decnumlen(int nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (len + 1);
	if (nb < 0)
		len = 1;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
