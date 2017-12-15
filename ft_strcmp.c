/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:09:45 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/09 15:50:30 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	a;
	unsigned char	b;

	while (*s1 != '\0' || *s2 != '\0')
	{
		a = *s1;
		b = *s2;
		if (a - b != 0)
			return (a - b);
		else
		{
			s1++;
			s2++;
		}
	}
	return (0);
}
