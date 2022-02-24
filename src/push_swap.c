/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:53:45 by juhur             #+#    #+#             */
/*   Updated: 2022/02/24 18:33:16 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

static void	init_push_swap(t_push_swap *ps, int count)
{
	ps->count = count;
	ps->nums = (int *)malloc(sizeof(int) * ps->count);
	if (ps->nums == NULL)
		quit_push_swap(ps, MALLOC_ERROR);
	ps->sorted = (int *)malloc(sizeof(int) * ps->count);
	if (ps->sorted == NULL)
		quit_push_swap(ps, MALLOC_ERROR);
	ps->tmp = (int *)malloc(sizeof(int) * ps->count);
	if (ps->tmp == NULL)
		quit_push_swap(ps, MALLOC_ERROR);
}

void	push_swap(int count, char **nums)
{
	t_push_swap	ps;

	init_push_swap(&ps, count);
	to_integer(&ps, nums);
}

void	quit_push_swap(t_push_swap *ps, char *str)
{
	if (ps != NULL && ps->nums != NULL)
		free(ps->nums);
	if (ps != NULL && ps->sorted != NULL)
		free(ps->sorted);
	if (ps != NULL && ps->tmp != NULL)
		free(ps->tmp);
	if (str != NULL)
		write(1, str, ft_strlen(str));
	exit(0);
}
