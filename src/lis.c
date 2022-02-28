/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:49:50 by juhur             #+#    #+#             */
/*   Updated: 2022/02/28 16:27:55 by juhur            ###   ########.fr       */
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

static void	set_lis_idx(t_push_swap *ps)
{
	int	i;
	int	max;

	i = -1;
	max = 0;
	while (++i < ps->count)
	{
		if (ps->lis.dp[i] > max)
		{
			max = ps->lis.dp[i];
			ps->lis.idx = i;
		}
	}
}

void	lis(t_push_swap *ps)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ps->count)
	{
		ps->lis.dp[i] = 1;
		j = -1;
		while (++j < i)
		{
			if (ps->a.stack[j] <= ps->a.stack[i])
				continue ;
			if (ps->lis.dp[j] + 1 > ps->lis.dp[i])
			{
				ps->lis.dp[i] = ps->lis.dp[j] + 1;
				deep_copy(ps->lis.arr[i], ps->lis.arr[j], ps->count);
			}
		}
		ps->lis.arr[i][get_len(ps->lis.arr[i], ps->count)] = ps->a.stack[i];
	}
	set_lis_idx(ps);
	ps->lis.len = get_len(ps->lis.arr[ps->lis.idx], ps->count);
	reverse(ps->lis.arr[ps->lis.idx], ps->lis.len);
}
