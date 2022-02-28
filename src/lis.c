/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:49:50 by juhur             #+#    #+#             */
/*   Updated: 2022/02/28 18:43:29 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_len(int *array, int max)
{
	int	i;
	int	idx;

	i = -1;
	idx = max;
	while (++i < max)
	{
		if (array[i] == 0)
		{
			idx = i;
			break ;
		}
	}
	return (idx);
}

static void	set_lis_data(t_push_swap *ps)
{
	int	i;
	int	idx;
	int	max;

	i = -1;
	max = 0;
	while (++i < ps->count)
	{
		if (ps->lis.nums[i] > max)
		{
			max = ps->lis.nums[i];
			idx = i;
		}
	}
	ps->lis.len = get_len(ps->tmp[idx], ps->count);
	deep_copy(ps->lis.nums, ps->tmp[idx], ps->lis.len);
	reverse(ps->lis.nums, ps->lis.len);
	ps->lis.to_b_count = ps->count - ps->lis.len;
}

void	lis(t_push_swap *ps)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ps->count)
	{
		ps->lis.nums[i] = 1;
		set_zero(ps->tmp[i], ps->count);
		j = -1;
		while (++j < i)
		{
			if (ps->a.stack[j] <= ps->a.stack[i])
				continue ;
			if (ps->lis.nums[j] + 1 > ps->lis.nums[i])
			{
				ps->lis.nums[i] = ps->lis.nums[j] + 1;
				deep_copy(ps->tmp[i], ps->tmp[j], ps->count);
			}
		}
		ps->tmp[i][get_len(ps->tmp[i], ps->count)] = ps->a.stack[i];
	}
	set_lis_data(ps);
}
