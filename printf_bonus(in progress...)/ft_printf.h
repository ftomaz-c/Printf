/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:19:43 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/15 17:27:49 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct t_flags
{
	int	minus_flag;
	int	zero_flag;
	int	width_flag;
	int	precision_flag;
	int	alternative_form;
	int	space_flag;
	int	plus_flag;
}	t_flags;

/* printf */
int			ft_printf(const char *format, ...);

/* flags */
t_flags		*flag_check(const char *format);
int			width_flag(const char *format);
int			precision_flag(const char *format);
char		*alternative_form(const char *format);

/* formating */
char		*is_width_flag(int len);
int			format_spec(const char *format, va_list args, t_flags *flags);
int			char_format(int c, t_flags *flags);
int			str_format(char *s, t_flags *flags);
int			ptr_format(void *ptr, t_flags *flags);
int			nbr_format(long long nbr, t_flags *flags);
int			unsigned_format(unsigned int u, t_flags *flags);
void		ft_putunbr_fd(unsigned int n, int fd);
int			hex_formatx(unsigned int hex, t_flags *flags);
int			hex_format_upx(unsigned int hex, t_flags *flags);

/* formating len */
int			str_len(char *s, int len);
int			nbr_len(long long nbr);
int			ptr_len(char *base, unsigned long long nbr);
int			nbr_base_len(char *base, unsigned long long nbr);

#endif
