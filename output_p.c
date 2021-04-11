/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotatabe <kotatabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:32:46 by kotatabe          #+#    #+#             */
/*   Updated: 2020/10/05 14:40:08 by kotatabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		putnbr_with_pre_and_minus(unsigned long tmp, t_data *type)
{
	int	i;
	int	len;

	i = 0;
	len = type->length;
	type->written_len += write(1, "0x", 2);
	while (type->precision > len + i)
	{
		write(1, "0", 1);
		i++;
	}
	type->written_len += i;
	x_putnbr(tmp, len);
	return (type->written_len);
}

static void		manage_zero_flag(t_data *type)
{
	type->precision = type->width;
	type->width = 0;
}

static void		put_space_with_i(t_data *type)
{
	int	i;

	i = 0;
	while (type->width \
	&& (type->width - (MAX(type->precision, type->length) + 2)) > i)
	{
		type->written_len += write(1, " ", 1);
		i++;
	}
	if (type->pre_zero_flag)
		type->written_len += write(1, "0x", 2);
}

int				output_p(va_list ap, t_data *type)
{
	int				i;
	unsigned long	tmp;

	i = 0;
	tmp = (unsigned long)va_arg(ap, void *);
	type->length = x_nbrlen(tmp);
	type->written_len = type->length;
	if (type->precision == -1)
	{
		type->pre_zero_flag = 1;
		type->length = 0;
		type->written_len = 0;
		type->precision = 0;
	}
	if (type->left_align && type->length)
		putnbr_with_pre_and_minus(tmp, type);
	if (type->zero_flag && !(type->left_align) && !(type->precision))
		manage_zero_flag(type);
	put_space_with_i(type);
	if (!(type->left_align) && type->length)
		putnbr_with_pre_and_minus(tmp, type);
	return (type->written_len);
}
