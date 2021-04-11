/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_large_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotatabe <kotatabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:45:18 by ktabe             #+#    #+#             */
/*   Updated: 2020/10/07 21:50:45 by kotatabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		putnbr_with_pre_and_minus(long tmp, \
t_data *type, int *nega_flag)
{
	int	i;
	int	len;

	i = 0;
	len = type->length;
	if (*nega_flag)
	{
		write(1, "-", 1);
		type->length++;
		*nega_flag = 0;
	}
	while (type->precision > len + i)
	{
		write(1, "0", 1);
		i++;
	}
	type->length += i;
	large_x_putnbr((unsigned int)tmp, len);
	return (type->length);
}

static void		manage_zero_flag(t_data *type, int nega_flag)
{
	if (nega_flag)
		type->precision = type->width - 1;
	else
		type->precision = type->width;
	type->width = 0;
}

static void		put_space_with_i(t_data *type, int nega_flag, int *i)
{
	if (nega_flag)
		*i += 1;
	while (type->width && \
	(type->width - MAX(type->precision, type->length)) > *i)
	{
		write(1, " ", 1);
		(*i)++;
	}
	if (nega_flag)
		*i -= 1;
}

static void		zero_pre(t_data *type)
{
	type->length = 0;
	type->precision = 0;
}

int				output_large_x(va_list ap, t_data *type)
{
	int		i;
	int		nega_flag;
	long	tmp;

	i = 0;
	nega_flag = 0;
	if ((tmp = (long)va_arg(ap, unsigned int)) < 0)
	{
		tmp *= -1;
		nega_flag = 1;
	}
	type->length = x_nbrlen((unsigned long)tmp);
	if (type->precision == -1 && tmp == 0)
		zero_pre(type);
	if (type->left_align && type->length)
		putnbr_with_pre_and_minus(tmp, type, &nega_flag);
	if (type->zero_flag && !(type->left_align) && !(type->precision))
		manage_zero_flag(type, nega_flag);
	put_space_with_i(type, nega_flag, &i);
	if (!(type->left_align) && type->length)
		putnbr_with_pre_and_minus(tmp, type, &nega_flag);
	type->length += i;
	return (type->length);
}
