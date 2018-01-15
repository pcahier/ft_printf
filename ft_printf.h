/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:34:44 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/06 21:16:26 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <wctype.h>

typedef struct	s_stru
{
	const char	*format;
	int			pre;
	int			wid_min;
	int			len;
	char		l_just;
	char		sign;
	char		zero;
	char		pound;
	char		conv;
}				t_stru;

int				ft_printf(const char *format, ...);
int				ft_vfprintf(int fd, const char *format, va_list *ap);
t_stru			*ft_genbasestru(t_stru *stru, size_t pre, size_t wid_min, 
						const char *format);
t_stru			*ft_analyseformat(t_stru *stru, const char *format);
t_stru			*ft_analyseformat2(t_stru *stru, const char *format);
t_stru			*ft_analyseformat3(t_stru *stru, const char *format);
int				ft_int_dec(const char *format, va_list *ap, int fd);
int				ft_uns_dec(const char *format, va_list *ap, int fd);
int				ft_uns_hex(const char *format, va_list *ap, int fd);
int				ft_uns_hexmaj(const char *format, va_list *ap, int fd);
int				ft_uns_oct(const char *format, va_list *ap, int fd);
int				ft_uns_bin(const char *format, va_list *ap, int fd);
int				ft_pointer(const char *format, va_list *ap, int fd);
int				ft_charray(const char *format, va_list *ap, int fd);
int				ft_int_uchar(const char *format, va_list *ap, int fd);
int				ft_wrongconv(const char *format, int fd);
int				ft_formatwchar(unsigned int s, t_stru *stru, int fd);
int				ft_printchar(t_stru *stru, unsigned char c, int fd);
int				ft_printwchar(t_stru *stru, unsigned int s, int fd);
int				ft_printstring(t_stru *stru, char *str, int fd);
int				ft_printstringwchar(t_stru *stru, unsigned int *str, int fd);
size_t			ft_printdecnumlen(intmax_t nb);
size_t			ft_printunsnumlen(uintmax_t nb, int base);
int				ft_putnstr_fd(char *s, int fd, int n);
char			*ft_itoa_print(intmax_t n, t_stru *stru);
char			*ft_uitoa_print(uintmax_t n, t_stru *stru, int base);
char			*ft_uitoam_print(uintmax_t n, t_stru *stru, int base);

#endif
