/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:02:43 by juhur             #+#    #+#             */
/*   Updated: 2022/03/06 19:50:05 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_push_swap *ps)
{
	while (ps->lis.to_b_count)
	{
		if (ps->lis.to_b[ps->a.stack[ps->a.top] - 1])
		{
			pb(ps);
			--ps->lis.to_b_count;
		}
		else
			ra(ps, 1, true);
	}
}
