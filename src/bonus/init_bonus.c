/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:24:38 by juhur             #+#    #+#             */
/*   Updated: 2022/12/31 17:57:38 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap_bonus.h"

void	init(struct s_push_swap_bonus *ps)
{
	int	i;

	ps->s = (char **)malloc(sizeof(char *) * ps->count);
	if (ps->s == NULL)
		quit_push_swap(ps, ERROR);
	ps->nums = ft_calloc(ps, sizeof(int *), ps->count);
	ps->tmp = ft_calloc(ps, sizeof(int *), ps->count);
	ps->a.stack = ft_calloc(ps, sizeof(int), ps->count);
	ps->b.stack = ft_calloc(ps, sizeof(int), ps->count);
	i = -1;
	while (++i < ps->count)
	{
		ps->nums[i] = ft_calloc(ps, sizeof(int), 2);
		ps->tmp[i] = ft_calloc(ps, sizeof(int), max(7, ps->count));
	}
	ps->a.top = ps->count - 1;
	ps->b.top = -1;
}
