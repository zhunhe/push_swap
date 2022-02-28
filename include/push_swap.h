/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:52:07 by juhur             #+#    #+#             */
/*   Updated: 2022/03/01 00:35:18 by juhur            ###   ########.fr       */
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
	int	*nums;
	int	len;
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

/*
** push_swap.c
*/
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
** init.c
*/
void	set_zero(int *array, int count);
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
bool	sa(t_push_swap *ps, bool prints_func);
bool	sb(t_push_swap *ps, bool prints_func);
bool	ss(t_push_swap *ps);
/*
** push.c
*/
bool	pa(t_push_swap *ps);
bool	pb(t_push_swap *ps);
/*
** rotate.c
*/
bool	ra(t_push_swap *ps, bool prints_func);
bool	rb(t_push_swap *ps, bool prints_func);
bool	rr(t_push_swap *ps);
/*
** reverse_rotate.c
*/
bool	rra(t_push_swap *ps, bool prints_func);
bool	rrb(t_push_swap *ps, bool prints_func);
bool	rrr(t_push_swap *ps);
/*
** ft_split.c
*/
char	**ft_split(char const *s, int w_cnt);
#endif