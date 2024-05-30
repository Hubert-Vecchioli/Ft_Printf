/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:33:28 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/30 16:21:13 by hvecchio         ###   ########.fr       */
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
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_print_conversion(args, str[i + 1], &count);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], STDOUT_FILENO);
			count++;
		}
		i++;
	}
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

// #include <stdio.h>
// int main ()
// {
//     int i;
// 	printf("Cas null\n");
// 	i = printf("");
//     printf("%d\n", i);
//     i = ft_printf("");
//     printf("%d\n", i);
// 	i = printf("");
//     printf("%d\n", i);
//     i = ft_printf("");
//     printf("%d\n", i);
//
// 	printf("\ns\n");
// 	i = printf("Original: %s %s\n", "Je suis", "une patate.");
//     printf("%d\n", i);
//     i = ft_printf("Perso   : %s %s\n", "Je suis", "une patate.");
//     printf("%d\n", i);
//
// 	printf("\nc\n");
// 	i = printf("Original: %c\n", 'a');
//     printf("%d\n", i);
//     i = ft_printf("Perso   : %c\n", 'a');
//     printf("%d\n", i);
//
// 	printf("\ni\n");
// 	i = printf("Original: %i\n", 010);
//     printf("%d\n", i);
//     i = ft_printf("Perso   : %i\n", 010);
//     printf("%d\n", i);
//
// 	printf("\nd\n");
// 	i = printf("Original: %d\n", 0);
//     printf("%d\n", i);
//     i = ft_printf("Perso   : %d\n", 0);
//     printf("%d\n", i);
//     i = printf("Original: %d\n", 10);
//     printf("%d\n", i);
//     i = ft_printf("Perso   : %d\n", 10);
//     printf("%d\n", i);
//
// 	printf("\np\n");
// 	i = printf("Original: %p\n", 9223372036854775807);
//     printf("%d\n", i);
//     i = ft_printf("Perso   : %p\n", 9223372036854775807);
//     printf("%d\n", i);
//     i = printf("Original: %p\n", -9223372036854775808);
//     printf("%d\n", i);
//     i = ft_printf("Perso   : %p\n", -9223372036854775808);
//     printf("%d\n", i);
//     return (0);
// }