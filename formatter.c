/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotatabe <kotatabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:22:11 by ktabe             #+#    #+#             */
/*   Updated: 2020/10/07 21:41:30 by kotatabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_data(t_data *type)
{
	type->length = 0;
	type->width = 0;
	type->precision = 0;
	type->left_align = 0;
	type->zero_flag = 0;
	type->specifier = 'c';
	type->written_len = 0;
	type->pre_zero_flag = 0;
}

int			atoi_width_or_prec(char **format, va_list ap, t_data *type)
{
	int	num;

	num = 0;
	while (ft_isdigit(**format))
	{
		num *= 10;
		num += **format - 48;
		(*format)++;
	}
	if (**format == '*')
	{
		type->asterisk = va_arg(ap, int);
		num = type->asterisk;
		if (type->asterisk < 0)
		{
			type->left_align = 1;
		}
		(*format)++;
	}
	return (num);
}

void		sort_format(char **format, va_list ap, t_data *type)
{
	init_data(type);
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			type->left_align = 1;
		if (**format == '0')
			type->zero_flag = 1;
		(*format)++;
	}
	if (ft_isdigit(**format) || **format == '*')
	{
		if (0 > (type->width = atoi_width_or_prec(format, ap, type)))
			type->width *= -1;
	}
	if (**format == '.')
	{
		(*format)++;
		if (0 > (type->precision = atoi_width_or_prec(format, ap, type)))
		{
			type->precision = 0;
			return ;
		}
		if (type->precision == 0)
			type->precision = -1;
	}
}
