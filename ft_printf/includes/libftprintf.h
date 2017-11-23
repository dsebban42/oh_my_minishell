/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 16:43:56 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/28 14:58:53 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define INIT(a,b,c) a b = c
# define EV(err,res)	(err_void(err,res))
# define B_SIZE 512

# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include "limits.h"
# include <stdio.h>
# include <stdint.h>

typedef struct		s_flag
{
	int				width;
	int				precision;
	char			sign;
	char			fill;
	char			space;
	char			sharp;
	char			decalage;
	char			lng_mod;
}					t_flag;

char				*var_integer_sub1(t_flag *flg, char *ct_str, void *i);
char				*var_integer_sub2(t_flag *flg, char *ct_str);
char				*ft_realloc(char *ret_str, size_t len);
char				*ft_strnstr(const char *str, const char *tofind,
					size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strncat(char *dst, const char *src, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strchr(const char *str, int chr);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strcpy(char *dst, const char *src);
void				ft_bzero(void *ptr, size_t n);
void				*ft_memset(void *ptr, int val, size_t num);
void				pprint_err(char *str);
void				ftp_longtoa_base(long value, int base, char **ct_str);
void				ftp_itoa_base(long int value, int base, char **ct_str);
void				ftp_ulongtoa_base(size_t value, int base, char **ct_str);
void				ft_dec_to_hex_upper(void *content, short c, char **ct_str);
void				ft_dec_to_hex(void *content, short c, char **ct_str);
void				ft_p(t_flag flg, void *content, char *ct_str);
void				largeur_champ(t_flag flg, char **ct_str, int size);
size_t				var_wstr(t_flag flg, wchar_t *wstr, char **ct_str);
size_t				var_wc(t_flag flg, wchar_t c, char **ct_str);
size_t				var_lower_hexa(t_flag flg, void *content, char **ct_str);
size_t				var_upper_hexa(t_flag flg, void *content, char **ct_str);
size_t				ft_select(void *content, char type, char **ct_str,
					t_flag flg);
size_t				var_adress(t_flag flg, void *i, char **ct_str);
size_t				var_integer(t_flag flg, void *i, char **ct_str);
size_t				var_c(t_flag flg, char c, char **ct_str);
size_t				var_str(t_flag flg, void *str, char **ct_str);
size_t				var_octal(t_flag flg, unsigned long o, char **ct_str);
size_t				var_octal_long(t_flag flg, unsigned long o, char **ct_str);
size_t				var_utoa(t_flag flg, void *i, char **ct_str);
size_t				var_ulongtoa(t_flag flg, unsigned long int j,
					char **ct_str);
size_t				var_longtoa(t_flag flg, long l, char **ct_str);
int					va_foreach(va_list ap, const char *fmt, char **ct_str,
					size_t len);
int					utf_size(wchar_t *content, int o);
int					int_size(int i);
int					null_str_verif(void *content, char **ct_str, char type);
int					ftp_putstr(char const *str);
int					ft_printf(const char *fmt, ...);
int					ft_printferror(const char *fmt, ...);
int					ft_isdigit(int d);
int					verif_conv(char type);
int					ft_flags(const char *s, int pos, t_flag *flg);
int					ft_toupper(int ch);
int					convert_utf(wchar_t c, char **ct_str);
int					length_modif(const char *fmt, int pos, t_flag *flg);
unsigned long		hex_size(unsigned long hx);
long unsigned int	ft_strlen(const char *str);
unsigned			unsigned_size(unsigned u);

#endif
