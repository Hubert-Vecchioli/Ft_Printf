/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:57:52 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/30 13:12:58 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

size_t	ft_hex_len(unsigned int nbr)
{
	size_t	count;

	count = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

size_t	ft_print_hex(unsigned long long nbr, char c)
{
	char *base_up;
	char *base_low;
	
	base_up ="0123456789ABCDEF";
	base_low ="0123456789abcdef";
	
	if (nbr == 0)
		return (ft_putchar_fd('0', 1));
	if (c == 'x')
		ft_put_hex(nbr, base_low);
	else if (c == 'X')
		ft_put_hex(nbr, base_up);
	return (ft_hex_len(nbr));
}

void	ft_put_hex(unsigned int nbr, char *base)
{
	if (nbr >= 16)
	{
		ft_put_hex(nbr / 16, base);
		ft_put_hex(nbr % 16, base);
	}
	else
	{
		write(1, (base + nbr), 1);
	}
}