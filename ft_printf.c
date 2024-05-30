/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:33:28 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/30 10:12:43 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			result;

	if (!str || !*str)
		return (0);
	result = 0;
	va_start(args, str);
	result = ft_parse(str, args);
	va_end(args);
	return (result);
}

int	ft_parse(const char *str, va_list args)
{
	va_list	args;
	size_t	i;
	size_t	count;


	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_format(args, str[i + 1], &count);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	return (count)
}

void	ft_print_flags(va_list args, char c, size_t *count)
{
	if (c == 'c')
		*count += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		*count += ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		*count += ft_print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		*count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		*count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		*count += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		*count += ft_putchar_fd('%', 1);
	return (count);
}

static size_t	ft_digitlen(long n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	i;
	size_t	n_len;
	char	*str;

	nbr = (long)n;
	n_len = ft_digitlen(nbr);
	str = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (n == 0)
		str[i] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[(n_len - 1) - i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	str[n_len] = 0;
	return (str);
}
