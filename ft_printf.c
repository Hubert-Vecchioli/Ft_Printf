/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:33:28 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/31 13:27:57 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			result;

	if (!str)
		return (-1);
	if (!*str)
		return (0);
	result = 0;
	va_start(args, str);
	result = ft_parse(str, args);
	va_end(args);
	return (result);
}

int	ft_parse(const char *str, va_list args)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_is_type(str[i + 1]))
		{
			ft_print_conversion(args, str[i + 1], &count);
			i++;
		}
		else if (str[i] != '%' || (str[i] == '%' && str[i + 1]) )
		{
			ft_putchar_fd(str[i], STDOUT_FILENO);
			count++;
		}
		i++;
	}
	if (i > 0 && str[i - 1] == '%')
		return (-1);
	return (count);
}

void	ft_print_conversion(va_list args, char c, size_t *count)
{
	if (c == 'c')
		*count += ft_putchar_fd(va_arg(args, int), STDOUT_FILENO);
	else if (c == 's')
		*count += ft_putstr_fd(va_arg(args, char *), STDOUT_FILENO);
	else if (c == 'p')
		*count += ft_print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		*count += ft_putnbr_fd(va_arg(args, int), STDOUT_FILENO);
	else if (c == 'u')
		*count += ft_print_unsigned(va_arg(args, unsigned int), STDOUT_FILENO);
	else if (c == 'x' || c == 'X')
		*count += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		*count += ft_putchar_fd('%', STDOUT_FILENO);
}

int	ft_is_type(int c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}
