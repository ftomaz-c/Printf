/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:58:47 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/11 17:00:29 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	base_double(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_check(char *base, long long base_len)
{
	if (*base == '\0')
		return (0);
	if (base_double(base) == 1)
		return (0);
	if (*base == '-' || *base == '+')
		return (0);
	if (base_len < 2)
		return (0);
	return (1);
}

void	ft_putnbr_base_fd(long long nbr, char *base, int fd)
{
	long long	base_len;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (base_len == 16)
	{
		if (nbr == 0)
			return (ft_putstr_fd("(nil)", 1));
		if (nbr == LONG_MIN && base_len == 16)
			return (ft_putstr_fd("8000000000000000", 1));
		if (nbr == (long long)ULONG_MAX && base_len == 16)
			return (ft_putstr_fd("ffffffffffffffff", 1));
	}
	if (!error_check(base, base_len))
		return ;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr >= base_len)
		ft_putnbr_base_fd(nbr / base_len, base, fd);
	ft_putchar_fd(base[nbr % base_len], fd);
}

/* int main()
{
	char		*base;
	long long	nbr;

	nbr = 1993;
	base = "0123456789abcdef";
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd(nbr, base, 1);
} */
