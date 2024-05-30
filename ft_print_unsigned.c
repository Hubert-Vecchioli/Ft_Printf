/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:57:38 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/30 10:12:29 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_unsigned(unsigned int n)
{
	size_t	len;
	char	*nbr;

	if (n == 0)
		return (ft_putchar_fd('0', 1));
	nbr = ft_uitoa(n);
	len = ft_putstr_fd(nbr, 1);
	free(nbr);
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*nbr;
	size_t	len;

	len = ft_nbr_len(n);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (0);
	nbr[len] = '\0';
	while (n != 0)
	{
		nbr[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (nbr);
}

size_t	ft_nbr_len(unsigned int nbr)
{
	size_t	len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

size_t	ft_putnbr_fd(int n, int fd)
{
	size_t	len;
	char	*nbr;

	nbr = ft_itoa(n);
	len = ft_putstr_fd(nbr, fd);
	free(nbr);
	return (len);
}