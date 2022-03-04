/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:52:07 by juhur             #+#    #+#             */
/*   Updated: 2022/03/04 09:31:32 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>

typedef struct s_stack
{
	int	*stack;
	int	top;
}	t_stack;

typedef struct s_lis
{
	int	*to_b;
	int	to_b_count;
}	t_lis;

typedef struct s_push_swap
{
	int		count;
	int		**nums;
	int		**tmp;
	t_stack	a;
	t_stack	b;
	t_lis	lis;
}	t_push_swap;

# define ERROR		"Error\n"

# define NUMBER		0
# define ORDER		1

# define COUNT	0
# define RR	1
# define RA	2
# define RB	3
# define RRR	4
# define RRA	5
# define RRB	6

/*
** push_swap.c
*/
bool	is_sorted(t_push_swap *ps);
void	push_swap(int count, char **nums, bool one_string);
/*
** utils.c
*/
int		ft_strlen(const char *s);
void	swap(int *a, int *b);
void	deep_copy(int *dst, int *src, int len);
void	reverse(int *arr, int len);
void	println(char *s);
/*
** utils2.c
*/
int		min(int a, int b);
int		max(int a, int b);
void	fill_n(int *array, int len, int val);
void	*ft_calloc(t_push_swap *ps, int size, int len);
/*
** init.c
*/
void	init_push_swap(t_push_swap *ps, int count);
/*
** quit.c
*/
void	free_2d_array(void **ptr, int len);
void	quit_push_swap(t_push_swap *ps, char *error);
/*
** to_integer.c
*/
void	to_integer(t_push_swap *ps, char **nums);
/*
** lis.c
*/
void	lis(t_push_swap *ps);
/*
** swap.c
*/
void	sa(t_push_swap *ps, bool prints_func);
void	sb(t_push_swap *ps, bool prints_func);
void	ss(t_push_swap *ps);
/*
** push.c
*/
void	pa(t_push_swap *ps);
void	pb(t_push_swap *ps);
/*
** rotate.c
*/
void	ra(t_push_swap *ps, int count, bool prints_func);
void	rb(t_push_swap *ps, int count, bool prints_func);
void	rr(t_push_swap *ps, int count);
/*
** reverse_rotate.c
*/
void	rra(t_push_swap *ps, int count, bool prints_func);
void	rrb(t_push_swap *ps, int count, bool prints_func);
void	rrr(t_push_swap *ps, int count);
/*
** ft_split.c
*/
char	**ft_split(char const *s, int w_cnt);
/*
** a_to_b.c
*/
void	a_to_b(t_push_swap *ps);
/*
** b_to_a.c
*/
void	b_to_a(t_push_swap *ps);
#endif