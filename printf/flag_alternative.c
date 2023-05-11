/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternative_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:26:28 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/10 19:28:01 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*alternative_form(const char *format)
{
	char	*ptr;

	if (*format == 'x')
		ptr = ft_strdup("0x");
	else if (*format == 'X')
		ptr = ft_strdup("0X");
	else
		return (NULL);
	if (!ptr)
	{
		free (ptr);
		return (NULL);
	}
	return (ptr);
}
