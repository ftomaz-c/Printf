/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:58:47 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/04 17:17:07 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

int	error_check(char *base, int base_len)
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (!error_check(base, base_len))
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= base_len)
	{
		ft_putnbr_base(nbr / base_len, base);
	}
	ft_putchar(base[nbr % base_len]);
}

int	main(void)
{
	int	nbr = 11;
	char	base[] = "0123456789ABCDEF";
 
	ft_putnbr_base(nbr, base);
}
