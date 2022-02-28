/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:53:45 by juhur             #+#    #+#             */
/*   Updated: 2022/02/28 20:29:13 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_sorted(t_push_swap *ps)
{
	int	i;

	i = -1;
	while (++i < ps->count)
		if (ps->a.stack[i] != ps->count - i)
			return (false);
	return (true);
}

static void	align(t_push_swap *ps)
{
	if (ps->a.stack[ps->a.top] == ps->count)
		ra(&ps, true);
	else if (ps->a.stack[1] == ps->count)
		rra(&ps, true);
	if (ps->a.stack[ps->a.top] == ps->a.stack[ps->a.top - 1] + 1)
		sa(&ps, true);
}

static void	a_to_b(t_push_swap *ps)
{
	int	i;

	i = 0;
	while (ps->lis.to_b_count)
	{
		if (i < ps->lis.len && ps->a.stack[ps->a.top] == ps->lis.nums[i])
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
		if (is_sorted(ps))
			break ;
	}
}

void	push_swap(int count, char **nums)
{
	t_push_swap	ps;

	init_push_swap(&ps, count);
	to_integer(&ps, nums);
	align(&ps);
	if (!is_sorted(&ps))
	{
		lis(&ps);
		a_to_b(&ps);
	}
}
