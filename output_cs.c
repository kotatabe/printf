/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotatabe <kotatabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:00:26 by ktabe             #+#    #+#             */
/*   Updated: 2020/10/07 21:39:32 by kotatabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		output_s(va_list ap, t_data *type)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = va_arg(ap, char *)))
		str = "(null)";
	type->length = ft_strlen(str);
	if (type->precision && type->precision < type->length)
		type->length = type->precision;
	if (type->precision == -1)
		type->length = 0;
	if (type->left_align)
		ft_putstr_len_fd(str, type->length, 1);
	while (type->width > i + type->length)
	{
		if (type->zero_flag && !(type->left_align))
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
	}
	if (!(type->left_align))
		ft_putstr_len_fd(str, type->length, 1);
	type->length += i;
	return (type->length);
}

int		output_c(va_list ap, char *format, t_data *type)
{
	char	c;
	int		i;
	int		ret;

	if (*format == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	i = 0;
	ret = 0;
	if (type->left_align)
		ret += write(1, &c, 1);
	while (type->width > i + 1)
	{
		if (type->zero_flag && !(type->left_align))
			ret += write(1, "0", 1);
		else
			ret += write(1, " ", 1);
		i++;
	}
	if (!(type->left_align))
		ret += write(1, &c, 1);
	return (ret);
}
