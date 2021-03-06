/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:10:42 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/22 19:18:25 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrtab(char **tab)
{
	unsigned int	i;

	i = 0;
	if (tab)
	{
		if (*tab)
		{
			while (tab[i][0])
			{
				ft_putstr(tab[i]);
				ft_putchar('\n');
				i++;
			}
		}
	}
}
