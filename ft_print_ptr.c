/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:08:54 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/30 13:11:51 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_ptr(unsigned long long ptr)
{
	size_t	len;
	char *base_low;

	base_low ="0123456789abcdef";

	if (ptr == 0)
		return (ft_putstr_fd("(nil)", 1));
	len = ft_putstr_fd("0x", 1);
	ft_put_hex(ptr, base_low);
	len += ft_hex_len(ptr);
	return (len);
}