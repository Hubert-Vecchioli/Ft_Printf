/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:34:13 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/30 09:57:11 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>

#include <stdarg.h>

typedef struct s_flag
{
	int     aligned_left;
	int     empty_with_zero;
	int     min_width;
	int     precision;
	int     hex_prefix;
	int     space_prefix;
	int     sign_prefix;
	char    conversion_type;
}		t_flag;

#endif