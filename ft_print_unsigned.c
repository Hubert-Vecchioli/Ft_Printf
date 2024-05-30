/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:57:38 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/30 16:01:24 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_unsigned(unsigned int n, int fd)
{
	size_t			nb;
	size_t			count;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
		count++;
	}
	if (nb / 10 != 0)
	{
		count += ft_print_unsigned(nb / 10, fd);
	}
	ft_putchar_fd(nb % 10 + '0', fd);
	return (count + 1);
}
