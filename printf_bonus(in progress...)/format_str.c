/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:08:13 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/15 10:55:18 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_format(char *s, t_flags *flags)
{
	int		len;
	int		width;
	char	*ptr;

	len = str_len(s, flags->precision_flag);
	width = flags->width_flag - len;
	if (width > 0)
	{
		ptr = is_width_flag(width);
		if (!flags->minus_flag)
		{
			ft_putstr_fd(ptr, 1);
			ft_putnstr_fd(s, len, 1);
		}
		else if (flags->minus_flag)
		{
			ft_putnstr_fd(s, len, 1);
			ft_putstr_fd(ptr, 1);
		}
		len += width;
		free(ptr);
	}
	else
		ft_putnstr_fd(s, len, 1);
	return (len);
}
