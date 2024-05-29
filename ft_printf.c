/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:33:28 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/29 18:09:39 by hvecchio         ###   ########.fr       */
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
	int		i;
	int		count;
	t_flag	flag;

	i = -1;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			flag = ft_new_flag_setup();
			if (str[i] == '%' && str[i + 1])
			{
				i = ft_parse_flag(str, i, args, &flag);
				if (str[i] && flag.conversion_type > 0)
					count += ft_print_arg(str[i], args, flag);
				else if (str[i])
					count += ft_print_char(str[i], flag);
			}
		}
		else
			write(STDOUT_FILENO, &str[i++], 1)
	}
	return (count)
}

int	ft_print_arg(char type, va_list args, t_flag flag)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_print_char(va_arg(args, int), flag);
	else if (type == 's')
		count += ft_print_str(va_arg(args, const char *), flag);
	else if (type == 'd' || type == 'i')
		count += ft_print_int(va_arg(args, int), flag);
	else if (type == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), 0, flag);
	else if (type == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 1, flag);
	else if (type == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int), flag);
	else if (type == 'p')
		count += ft_print_ptr((unsigned long int)va_arg(args, void *), flag);
	else if (type == '%')
		count += ft_print_char('%', flag);
	return (count);
}
