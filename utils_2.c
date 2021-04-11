/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotatabe <kotatabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:38:40 by ktabe             #+#    #+#             */
/*   Updated: 2020/10/05 14:39:36 by kotatabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_putnbr(unsigned long ui, int len)
{
	int		n;
	char	*x_nbr;
	char	*str;

	x_nbr = "0123456789abcdef";
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (len)
	{
		n = ui % 16;
		str[len - 1] = x_nbr[n];
		len--;
		ui = ui / 16;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

void	large_x_putnbr(unsigned int ui, int len)
{
	int		n;
	char	*x_nbr;
	char	*str;

	x_nbr = "0123456789ABCDEF";
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (len)
	{
		n = ui % 16;
		str[len - 1] = x_nbr[n];
		len--;
		ui = ui / 16;
	}
	ft_putstr_fd(str, 1);
	free(str);
}
