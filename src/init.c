/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:11:41 by juhur             #+#    #+#             */
/*   Updated: 2022/03/04 09:35:53 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	init_push_swap(t_push_swap *ps, int count)
{
	int	i;

	ps->count = count;
	ps->nums = ft_calloc(ps, sizeof(int *), ps->count);
	ps->tmp = ft_calloc(ps, sizeof(int *), ps->count);
	ps->a.stack = ft_calloc(ps, sizeof(int), ps->count);
	ps->b.stack = ft_calloc(ps, sizeof(int), ps->count);
	ps->lis.to_b = ft_calloc(ps, sizeof(int), ps->count);
	i = -1;
	while (++i < ps->count)
	{
		ps->nums[i] = ft_calloc(ps, sizeof(int), 2);
		ps->tmp[i] = ft_calloc(ps, sizeof(int), ps->count);
	}
	ps->a.top = ps->count - 1;
	ps->b.top = -1;
}
