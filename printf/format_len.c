/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:36:47 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/14 17:51:11 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_len(char *s, int len)
{
	int	format_len;
	int	s_len;

	format_len = 0;
	s_len = ft_strlen(s);
	if (len > 0 && s_len <= len)
		format_len = s_len;
	if (len > 0 && s_len > len)
		format_len = len;
	if (len == -1)
		format_len = 0;
	else if (len == 0)
		format_len = s_len;
	return (format_len);
}

int	nbr_len(long long nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	nbr_base_len(char *base, unsigned long long nbr)
{
	int	len;
	int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

int	ptr_len(char *base, unsigned long long nbr)
{
	int	len;
	int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (nbr == 0)
		len+= 5;
	while (nbr != 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}
