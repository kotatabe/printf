/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotatabe <kotatabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:19:01 by ktabe             #+#    #+#             */
/*   Updated: 2020/10/07 18:35:16 by kotatabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nbrlen(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int		x_nbrlen(unsigned long ui)
{
	int	ret;

	ret = 0;
	if (ui == 0)
		return (1);
	while (ui)
	{
		ui = ui / 16;
		ret++;
	}
	return (ret);
}

void	ft_putnbr_long_fd(long n, int fd)
{
	char	c;

	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n >= 10)
	{
		ft_putnbr_long_fd(n / 10, fd);
		n = n % 10;
	}
	if (n <= 9)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

int		ft_putchar_and_ret_fd(char c, int fd)
{
	int	ret;

	ret = 0;
	ret = write(fd, &c, 1);
	return (ret);
}

void	ft_putstr_len_fd(char *s, int len, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (len > i)
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}
