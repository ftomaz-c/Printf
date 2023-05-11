/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:04:00 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/10 19:10:58 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_format(int c, t_flag_data *flags)
{
	char	*ptr;
	int		len;

	ptr = NULL;
	len = flags->width_flag;
	if (flags->width_flag > 0)
	{
		ptr = is_width_flag(flags->width_flag - 1);
		if (flags->minus_flag == 0)
		{
			ft_putstr_fd(ptr, 1);
			ft_putchar_fd(c, 1);
		}
		if (flags->minus_flag == 1)
		{
			ft_putchar_fd(c, 1);
			ft_putstr_fd(ptr, 1);
		}
	}
	else
	{
		ft_putchar_fd(c, 1);
		len = 1;
	}
	return (len);
}
