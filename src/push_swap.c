/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:53:45 by juhur             #+#    #+#             */
/*   Updated: 2022/02/28 18:09:19 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_to_b(t_push_swap *ps)
{
	int	i;

	i = 0;
	while (ps->lis.to_b_count)
	{
		if (i < ps->lis.len && \
			ps->a.stack[ps->a.top] == ps->lis.arr[ps->lis.idx][i])
		{
			ra(ps, true);
			if (i < ps->lis.len)
				i++;
		}
		else
		{
			pb(ps);
			--ps->lis.to_b_count;
		}
	}
}

void	push_swap(int count, char **nums)
{
	t_push_swap	ps;

	init_push_swap(&ps, count);
	to_integer(&ps, nums);
	lis(&ps);
	a_to_b(&ps);
}
