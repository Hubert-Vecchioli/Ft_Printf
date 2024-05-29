/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:57:55 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/29 17:58:30 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c, t_flag flag)
{
	int	count;

	count = 0;
	if (flag.aligned_left == 1)
    {
        count++;
        write(STDOUT_FILENO, &c, 1);
    }
	count += ft_pad_width(flag.min_width, 1, flag.empty_with_zero);
	if (flag.aligned_left == 0)
    {
        count++;
        write(STDOUT_FILENO, &c, 1);
    }
	return (count);
}