/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 12:21:54 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/29 07:45:48 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define PTRNULL "(nil)"

typedef struct s_flags
{
	int	spec;
	int	width;
	int	left;
	int	zero;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}		t_flags;

t_flags	ft_flags_init(void);
int		ft_width_flag(const char *str, int pos, t_flags *flags);
int		ft_precision_flag(const char *str, int pos, t_flags *flags);

int		ft_printf(const char *format, ...);
int		ft_print_arg(char type, va_list args, t_flags *flags);

// c
int		ft_print_char(char c, t_flags *flags);
int		ft_print_c(char c);
// s
int		g_print_str(const char *str, t_flags *flags);
int		ft_print_s(const char *str);
int		ft_print_s_pre_width(const char *s, int precision);
// i, d
int		ft_print_int(char *s_nbr, int nbr, t_flags *flags);
int		g_print_int(int nbr, t_flags *flags);
int		ft_print_s_int(const char *str, t_flags *flags);
// u
int		g_print_unsigned(unsigned int nbr, t_flags *flags);
int		ft_print_u(const char *s_nbr, t_flags *flags);
// x, X
int		g_print_hex(unsigned int nb, int is_upper, t_flags *flags);
int		ft_print_hex(char *s_nbr, unsigned int nb,
			int is_upper, t_flags *flags);
int		ft_print_h(char *s_nbr, t_flags *flags);
// p
int		g_print_ptr(void *ptr, t_flags *flags);
int		ft_print_p(unsigned long int n, t_flags *flags);
void	ft_print_add(unsigned long nbr);

char	*ft_itoa_(long nbr);
char	*ft_utoa(unsigned int nb);
char	*ft_xtoa(unsigned long int nb, int is_upper);
int		ft_istype(int c);
int		ft_isspec(int c);
int		ft_isflag(int c);

int		ft_pad_width(int total_width, int size, int zero);

#endif
