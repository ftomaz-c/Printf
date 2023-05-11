/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:19:43 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/11 15:48:26 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct t_flag_data
{
	int	minus_flag;
	int	zero_flag;
	int	width_flag;
	int	precision_flag;
	int	alternative_form;
	int	space_flag;
	int	plus_flag;
}	t_flag_data;

/* printf */
int			ft_printf(const char *format, ...);

/* flags */
t_flag_data	*flag_check(const char *format);
int			width_flag(const char *format);
int			precision_flag(const char *format);
char		*alternative_form(const char *format);

/* formating */
char		is_placeholder(const char *format);
char		*is_width_flag(int len);
int			format_spec(const char *format, va_list args, t_flag_data *flags);
int			nbr_base_len(char *base, long long nbr);
int			char_format(int c, t_flag_data *flags);
int			str_format(char *s, t_flag_data *flags);
int			ptr_format(void *ptr, t_flag_data *flags);
int			nbr_format(int i, t_flag_data *flags);
int			unsigned_format(unsigned int u, t_flag_data *flags);
void		ft_putunbr_fd(unsigned int n, int fd);

#endif
