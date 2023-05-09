/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:11:36 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/09 12:22:30 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(char *s, int n, int fd)
{
	int	i;

	i = 0;
	while (i < n && *s)
	{
		ft_putchar_fd(*s, fd);
		i++;
		s++;
	}
}