/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:11:41 by juhur             #+#    #+#             */
/*   Updated: 2022/03/01 00:25:56 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	set_zero(int *array, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		array[i] = 0;
}

void	init_push_swap(t_push_swap *ps, int count)
{
	int	i;

	ps->count = count;
	ps->nums = (int **)malloc(sizeof(int *) * ps->count);
	ps->tmp = (int **)malloc(sizeof(int *) * ps->count);
	ps->a.stack = (int *)malloc(sizeof(int) * ps->count);
	ps->b.stack = (int *)malloc(sizeof(int) * ps->count);
	ps->lis.nums = (int *)malloc(sizeof(int) * ps->count);
	if (ps->nums == NULL || ps->tmp == NULL || ps->a.stack == NULL \
		|| ps->b.stack == NULL || ps->lis.nums == NULL)
		quit_push_swap(ps, ERROR);
	i = -1;
	while (++i < ps->count)
	{
		ps->nums[i] = (int *)malloc(sizeof(int) * 2);
		ps->tmp[i] = (int *)malloc(sizeof(int) * ps->count);
		if (ps->nums[i] == NULL || ps->tmp[i] == NULL)
			quit_push_swap(ps, ERROR);
	}
	ps->a.top = ps->count - 1;
	ps->b.top = -1;
}
