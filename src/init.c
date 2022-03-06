/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:11:41 by juhur             #+#    #+#             */
/*   Updated: 2022/03/06 18:28:14 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	init_push_swap(t_push_swap *ps, int count)
{
	int	i;

	ps->count = count;
	ps->s = (char **)malloc(sizeof(char *) * ps->count);
	if (ps->s == NULL)
		quit_push_swap(ps, ERROR);
	ps->nums = ft_calloc(ps, sizeof(int *), ps->count);
	ps->tmp = ft_calloc(ps, sizeof(int *), ps->count);
	ps->a.stack = ft_calloc(ps, sizeof(int), ps->count);
	ps->b.stack = ft_calloc(ps, sizeof(int), ps->count);
	ps->lis.to_b = ft_calloc(ps, sizeof(int), ps->count);
	i = -1;
	while (++i < ps->count)
	{
		ps->nums[i] = ft_calloc(ps, sizeof(int), 2);
		ps->tmp[i] = ft_calloc(ps, sizeof(int), max(7, ps->count));
	}
	ps->a.top = ps->count - 1;
	ps->b.top = -1;
}
