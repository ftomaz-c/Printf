/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:18:31 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/11 01:16:13 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*is_width_flag(int len)
{
	char	*ptr;

	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memset(ptr, ' ', len);
	return (ptr);
}

int	width_flag(const char *format)
{
	int		len;

	if (*format < '1' || *format > '9')
		return (-1);
	len = 0;
	while (*format >= '0' && *format <= '9')
	{
		len = len * 10 + (*format - '0');
		format++;
	}
	return (len);
}
