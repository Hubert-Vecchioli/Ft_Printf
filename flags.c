/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:30:27 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/29 17:42:44 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_flag	ft_new_flag_setup(void)
{
	t_flag	flag;

	flag.conversion_type = 0;
	flag.aligned_left = 0;
	flag.empty_with_zero = 0;
	flag.min_width = 0;
	flag.precision = -1; /// A REVOIR
	flag.hex_prefix = 0;
	flag.space_prefix = 0;
	flag.sign_prefix = 0;
	return (flag);
}


int	ft_isflag(int c)
{
	return (ft_is_conversion(c) || ft_isdigit(c) || ft_is_bonus_flag(c));
}

int	ft_is_bonus_flag(int c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*'
		|| c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int	ft_is_conversion(int c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}


