/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:30:19 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/29 17:40:44 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_parse_flag(const char *str, int i, va_list args, t_flag *flag)
{
	while (str[++i] && ft_isflag(str[i]))
	{
		if (str[i] == '0' && (*flag).aligned_left == 0 && flag->width == 0)
			(*flag).empty_with_zero = 1;
		if (str[i] == '-')
		{
			(*flag).aligned_left = 1;
			(*flag).empty_with_zero = 0;
		}
		if (str[i] == '.')
			i = ft_flag_precision(str, i, args, flag);
		if (str[i] == '#')
			(*flag).hex_prefix = 1;
		if (str[i] == ' ' && (*flag).sign_prefix == 0)
			(*flag).space_prefix = 1;
		if (str[i] == '+')
		{
			(*flag).sign_prefix = 1;
			(*flag).space_prefix = 0;
		}
		if (ft_isdigit(str[i]))
			(*flag).min_width = ((*flag).width * 10) + (str[i] - '0'); ////
		if (ft_is_conversion(str[i]))
		{
			(*flag).conversion_type = str[i];
			break ;
		}
	}
	return (i);
}