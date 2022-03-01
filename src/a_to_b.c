/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:02:43 by juhur             #+#    #+#             */
/*   Updated: 2022/03/01 17:05:04 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_push_swap *ps)
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
