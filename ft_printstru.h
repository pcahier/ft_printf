/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstru.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:40:47 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/06 21:11:18 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTSTRU_H
# define FT_PRINTSTRU_H

typedef struct	s_print
{
	char	operat;
	int		(*ft)(const char *, va_list *, int);
}				t_print;

t_print			g_print[20] = {
	{'d', ft_int_dec},
	{'D', ft_int_dec},
	{'i', ft_int_dec},
	{'o', ft_uns_oct},
	{'O', ft_uns_oct},
	{'u', ft_uns_dec},
	{'U', ft_uns_dec},
	{'x', ft_uns_hex},
	{'X', ft_uns_hexmaj},
	{'b', ft_uns_bin},
/*	{'f', ft_dbl_dec},
	{'F', ft_dbl_decmaj},
	{'e', ft_dbl_exp},
	{'E', ft_dbl_expmaj},
	{'g', ft_dbl_conv},
	{'G', ft_dbl_convmaj},
	{'a', ft_dbl_hex},
	{'A', ft_dbl_hexmaj},
*/	{'c', ft_int_uchar},
	{'C', ft_int_uchar},
	{'s', ft_charray},
	{'S', ft_charray},
	{'p', ft_pointer},
/*	{'n', ft_bytewritten},*/
};

#endif
