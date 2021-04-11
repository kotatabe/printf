/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotatabe <kotatabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:20:48 by ktabe             #+#    #+#             */
/*   Updated: 2020/10/05 14:15:05 by kotatabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft/libft.h"

int		output_with_specifier(char **format, va_list ap, t_data *type)
{
	int	ret;

	ret = 0;
	if (**format == 'c' || **format == '%')
		ret = output_c(ap, *format, type);
	if (**format == 's')
		ret = output_s(ap, type);
	if (**format == 'd' || **format == 'i')
		ret = output_di(ap, type);
	if (**format == 'u')
		ret = output_u(ap, type);
	if (**format == 'x')
		ret = output_x(ap, type);
	if (**format == 'X')
		ret = output_large_x(ap, type);
	if (**format == 'p')
		ret = output_p(ap, type);
	if (!(**format))
		return (ret);
	(*format)++;
	return (ret);
}

int		ft_printf(char *format, ...)
{
	size_t	ret;
	size_t	tmp;
	t_data	type;
	va_list	ap;

	ret = 0;
	tmp = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			ret += ft_putchar_and_ret_fd(*format, 1);
			format++;
		}
		else
		{
			format++;
			sort_format(&format, ap, &type);
			ret += output_with_specifier(&format, ap, &type);
		}
	}
	va_end(ap);
	return (ret);
}
