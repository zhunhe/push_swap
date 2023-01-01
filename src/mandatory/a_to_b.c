/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:02:43 by juhur             #+#    #+#             */
/*   Updated: 2023/01/01 13:33:06 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_push_swap *ps)
{
	while (ps->lis.to_b_count)
	{
		if (ps->lis.to_b[ps->a.stack[ps->a.top]])
		{
			pb(ps);
			--ps->lis.to_b_count;
			if (ps->count > 100 && ps->b.stack[ps->b.top] > ps->count / 2)
				rb(ps, 1, true);
		}
		else
			ra(ps, 1, true);
	}
}
