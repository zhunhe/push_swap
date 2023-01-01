/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:11:45 by juhur             #+#    #+#             */
/*   Updated: 2023/01/01 13:45:32 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stddef.h>
# include <stdbool.h>

# define ERROR		"Error\n"

# define OK			"OK\n"
# define KO			"KO\n"

# define NUMBER		0
# define ORDER		1

struct s_stack
{
	int	*stack;
	int	top;
};

struct s_push_swap_bonus
{
	struct s_stack	a;
	struct s_stack	b;
	char			**s;
	int				**nums;
	int				**tmp;
	int				count;
};

/*
** if BUFFER_SIZE is negative integer, set BUFFER_SIZE to 0.
*/
# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE	0
#  endif
# else
#  define BUFFER_SIZE	42
# endif

/*
** get_next_line_bonus.c
*/
char	*get_next_line(int fd);

/*
** get_next_line_utils_bonus.c
*/
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strexpand(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

/*
** init_bonus.c
*/
void	init(struct s_push_swap_bonus *ps);

/*
** push_bonus.c
*/
void	pa(struct s_push_swap_bonus *ps);
void	pb(struct s_push_swap_bonus *ps);

/*
** quit_bonus.c
*/
void	quit_push_swap(struct s_push_swap_bonus *ps, char *str);

/*
** reverse_rotate_bonus.c
*/
void	rra(struct s_push_swap_bonus *ps, int count);
void	rrb(struct s_push_swap_bonus *ps, int count);
void	rrr(struct s_push_swap_bonus *ps, int count);

/*
** rotate_bonus.c
*/
void	ra(struct s_push_swap_bonus *ps, int count);
void	rb(struct s_push_swap_bonus *ps, int count);
void	rr(struct s_push_swap_bonus *ps, int count);

/*
** split_bonus.c
*/
int		count_word(char *s);
void	split(struct s_push_swap_bonus *ps, int argc, char **argv);

/*
** swap_bonus.c
*/
void	sa(struct s_push_swap_bonus *ps);
void	sb(struct s_push_swap_bonus *ps);
void	ss(struct s_push_swap_bonus *ps);

/*
** to_integer_bonus.c
*/
void	to_integer(struct s_push_swap_bonus *ps, char **nums);

/*
** util_bonus.c
*/
int		ft_strlen(const char *s);
void	fill_n(int *array, int len, int val);
void	*ft_calloc(struct s_push_swap_bonus *ps, int size, int len);
void	reverse(int *arr, int len);
int		max(int a, int b);

/*
** util2_bonus.c
*/
void	deep_copy(int *dst, int *src, int len);
void	swap(int *a, int *b);
int		ft_strcmp(const char *s1, const char *s2);

#endif
