/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:52:07 by juhur             #+#    #+#             */
/*   Updated: 2022/02/25 17:54:35 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>

typedef struct s_push_swap
{
	int		count;
	int		**nums;
	int		**tmp;
	int		*stack_a;
	int		*stack_b;
	int		top_a;
	int		top_b;
}	t_push_swap;

# define PLEASE_INPUT_NUMBERS	"Please input numbers\n"
# define MALLOC_ERROR			"Malloc error\n"
# define INVALID_CHAR			"Some arguments aren't integers\n"
# define ERROR_OVERFLOW			"Some arguments are bigger than an integer\n"
# define ERROR_UNDERFLOW		"Some arguments are smaller than an integer\n"
# define ERROR_DUPLICATE		"There are duplicates\n"

# define NUMBER		0
# define ORDER		1

/*
** push_swap.c
*/
void	push_swap(int count, char **nums);
void	quit_push_swap(t_push_swap *ps, char *error);
/*
** utils.c
*/
int		ft_strlen(const char *s);
/*
** to_integer.c
*/
void	to_integer(t_push_swap *ps, char **nums);
/*
** swap.c
*/
bool	sa(t_push_swap *ps);
bool	sb(t_push_swap *ps);
bool	ss(t_push_swap *ps);
/*
** push.c
*/
bool	pa(t_push_swap *ps);
bool	pb(t_push_swap *ps);
/*
** rotate.c
*/
bool	ra(t_push_swap *ps);
bool	rb(t_push_swap *ps);
bool	rr(t_push_swap *ps);
#endif