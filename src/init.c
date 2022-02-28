/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:11:41 by juhur             #+#    #+#             */
/*   Updated: 2022/02/28 14:40:44 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static void	set_zero(int *array, int count)
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
	ps->lis.dp = (int *)malloc(sizeof(int) * ps->count);
	ps->lis.arr = (int **)malloc(sizeof(int *) * ps->count);
	if (ps->nums == NULL || ps->tmp == NULL || ps->a.stack == NULL \
		|| ps->b.stack == NULL || ps->lis.dp == NULL || ps->lis.arr == NULL)
		quit_push_swap(ps, MALLOC_ERROR);
	i = -1;
	while (++i < ps->count)
	{
		ps->nums[i] = (int *)malloc(sizeof(int) * 2);
		ps->tmp[i] = (int *)malloc(sizeof(int) * 2);
		ps->lis.arr[i] = (int *)malloc(sizeof(int) * ps->count);
		if (ps->nums[i] == NULL || ps->tmp[i] == NULL || ps->lis.arr[i] == NULL)
			quit_push_swap(ps, MALLOC_ERROR);
		set_zero(ps->lis.arr[i], ps->count);
	}
	ps->a.top = ps->count - 1;
	ps->b.top = -1;
}