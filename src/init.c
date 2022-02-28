/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:11:41 by juhur             #+#    #+#             */
/*   Updated: 2022/02/28 12:13:47 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	init_push_swap(t_push_swap *ps, int count)
{
	int	i;

	ps->count = count;
	ps->nums = (int **)malloc(sizeof(int *) * ps->count);
	ps->tmp = (int **)malloc(sizeof(int *) * ps->count);
	ps->stack_a = (int *)malloc(sizeof(int) * ps->count);
	ps->stack_b = (int *)malloc(sizeof(int) * ps->count);
	ps->dp = (int *)malloc(sizeof(int) * ps->count);
	ps->lis = (int **)malloc(sizeof(int *) * ps->count);
	if (ps->nums == NULL || ps->tmp == NULL || ps->stack_a == NULL \
		|| ps->stack_b == NULL || ps->dp == NULL || ps->lis == NULL)
		quit_push_swap(ps, MALLOC_ERROR);
	i = -1;
	while (++i < ps->count)
	{
		ps->nums[i] = (int *)malloc(sizeof(int) * 2);
		ps->tmp[i] = (int *)malloc(sizeof(int) * 2);
		ps->lis[i] = (int *)malloc(sizeof(int) * ps->count);
		if (ps->nums[i] == NULL || ps->tmp[i] == NULL || ps->lis[i] == NULL)
			quit_push_swap(ps, MALLOC_ERROR);
	}
	ps->top_a = ps->count - 1;
	ps->top_b = -1;
}