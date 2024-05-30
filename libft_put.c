/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:16:35 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/30 13:15:28 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, sizeof(char));
	return (1);
}

size_t	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return (ft_putstr_fd("(null)", 1));	
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

size_t	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	size_t	count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
		count++;
	}
	if (nb / 10 != 0)
	{
		ft_putnbr_fd(nb / 10, fd);
		count++;
	}
	ft_putchar_fd(nb % 10 + '0', fd);
	return (count + 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	lenght;

	lenght = 0;
	while (str[lenght])
	{
		lenght++;
	}
	return (lenght);
}