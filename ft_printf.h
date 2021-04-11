/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotatabe <kotatabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:41:22 by ktabe             #+#    #+#             */
/*   Updated: 2020/10/06 13:04:03 by kotatabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

# define MAX(x, y) (x > y ? x : y)

typedef struct	s_data
{
	int		length;
	int		width;
	int		precision;
	int		left_align;
	int		zero_flag;
	char	specifier;
	int		asterisk;
	int		written_len;
	int		pre_zero_flag;
}				t_data;

int				ft_printf(char *format, ...);
void			ft_putnbr_long_fd(long n, int fd);
int				ft_putchar_and_ret_fd(char c, int fd);
void			ft_putstr_len_fd(char *s, int len, int fd);
int				output_with_specifier(char **format, va_list ap, t_data *type);
int				atoi_width_or_prec\
(char **format, va_list ap, t_data *type);
void			sort_format(char **format, va_list ap, t_data *type);
int				output_di(va_list ap, t_data *type);
int				output_s(va_list ap, t_data *type);
int				output_u(va_list ap, t_data *type);
int				output_c(va_list ap, char *format, t_data *type);
int				output_x(va_list ap, t_data *type);
int				output_large_x(va_list ap, t_data *type);
int				output_p(va_list ap, t_data *type);
int				output_with_specifier(char **format, va_list ap, t_data *type);
int				nbrlen(long n);
int				x_nbrlen(unsigned long ui);
void			x_putnbr(unsigned long ui, int len);
void			large_x_putnbr(unsigned int ui, int len);

#endif
