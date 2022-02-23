/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:52:07 by juhur             #+#    #+#             */
/*   Updated: 2022/02/23 13:41:09 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_push_swap
{
	int		count;
	int		*nums;
}	t_push_swap;

# define PLEASE_INPUT_NUMBERS	"Please input numbers\n"
# define MALLOC_ERROR			"Malloc error\n"
# define INVALID_CHAR			"Some arguments aren't integers\n"
# define ERROR_OVERFLOW			"Some arguments are bigger than an integer\n"
# define ERROR_UNDERFLOW		"Some arguments are smaller than an integer\n"

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
#endif