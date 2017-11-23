/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:05:04 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/26 14:13:12 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define EV(err,res)	(err_void(err,res))

# include <unistd.h>
# include <string.h>
# include <wchar.h>

# define INIT(a,b,c) a b = c
# define BUFF_SIZE 4096

typedef	struct		s_content
{
	char			*buffer;
	char			*end;
	char			*pos;
}					t_content;

typedef struct		s_tree
{
	struct s_tree	*left;
	struct s_tree	*right;
	void			*data;
}					t_tree;

typedef struct		s_list
{
	void			*content;
	size_t			size;
	struct s_list	*next;
}					t_list;

/*
** parsing
*/
int					count_occur(const char *str, const char occur);
int					get_next_line(int const fd, char **line);
char				*find_in_path(char **tab, char *to_find);
/*
** array
*/
void				tab_rm_element(char ***tab, int elem);
int					count_array(char **ar);
char				**tab_add_element(char **tab, char *to_add);
char				**tabdup(char **src, int size_array);
char				**tabjoin(char **tab1, char **tab2);
int					**mki_tab(int x, int y);
void				sort_char_tab(char **tab, int s_type);
void				free_tab(void ***tab);
int					find_in_array(char **ar, char *to_find, int len);
/*
** ft_is...
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isodd(int i);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
/*
** memory
*/
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
/*
** unclasified
*/
int					ft_atoi(const char *str);
int					int_size(int content);
/*
** ft_str
*/
void				strmvoccur(char **str, int oc, int dest);
int					ft_strallchr(const char *str, int chr);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_realloc(char *ret_str, size_t len);
char				*ft_itoa(int n);
char				**ft_strsplit(const char *s, char c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
void				ft_strdel(char **as);
void				ft_bzero(void *s, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strclr(char *s);
void				str_deloccur(char **str, int oc);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
/*
** print
*/
char				ft_putchar(char c);
void				*err_void(void *err, void *res);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
void				ft_putchar_utf(wchar_t c);
void				ft_putstr_utf(wchar_t *str);
void				ft_printlist(t_list *head, int l);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				print_err(char *str);
/*
** struct&tree
*/

t_list				*ft_find_occurence(t_list **root, char *str);
t_list				*lst_create(t_list **root, char c);
t_list				*sort_list(t_list *root);
void				ft_lstcopy(t_list *origin, t_list **dup, int size_ct,
					void (*f)(t_list *, t_list *));
void				tree_str_sort(t_tree **tree, char *str);
void				ft_lstiter(t_list *lst, void (*f)(t_list *));
void				ft_lstdelone(t_list **root, t_list *one);
void				ft_lstdel_occur(t_list **root, char *occur);
void				ft_lstdel(t_list **root);
char				*ft_itoa_base(int n, int base);
char				*ft_unsigned_itoa(unsigned int n);
int					count_node(t_list *list);
#endif
