/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:44:23 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/24 16:13:52 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Outputs the character ’c’ to the given file descriptor.					*/
/*c: The character to output.												*/
/*fd: The file descriptor on which to write.								*/

#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write (fd, &c, 1));
}
