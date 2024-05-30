/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:34:13 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/30 13:16:30 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...);
size_t	ft_hex_len(unsigned int nbr);
size_t	ft_print_hex(unsigned long long nbr, char format);
void	ft_put_hex(unsigned int nbr, char *base);
size_t	ft_print_ptr(unsigned long long ptr);
size_t	ft_print_unsigned(unsigned int n, int fd);
int	ft_parse(const char *str, va_list args);
void	ft_print_conversion(va_list args, char c, size_t *count);
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(char *s, int fd);
size_t	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *str);


#endif