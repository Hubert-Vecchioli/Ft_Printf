/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:57:52 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/29 16:48:19 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hex_len(unsigned int nbr)
{
	size_t	len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

void	ft_put_hex_lower(unsigned int nbr)
{
	if (nbr >= 16)
	{
		ft_put_hex_lower(nbr / 16);
		ft_put_hex_lower(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd(nbr + '0', 1);
		else
			ft_putchar_fd(nbr - 10 + 'a', 1);
	}
}

void	ft_put_hex_upper(unsigned int nbr)
{
	if (nbr >= 16)
	{
		ft_put_hex_upper(nbr / 16);
		ft_put_hex_upper(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd(nbr + '0', 1);
		else
			ft_putchar_fd(nbr - 10 + 'A', 1);
	}
}

size_t	ft_put_hex(unsigned int nbr, char format)
{
	if (nbr == 0)
		return (ft_putchar_fd('0', 1));// to re do
	if (format == 'x')
		ft_put_hex_lower(nbr);
	else if (format == 'X')
		ft_put_hex_upper(nbr);
	return (ft_hex_len(nbr));
}