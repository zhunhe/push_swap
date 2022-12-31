/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:11:17 by juhur             #+#    #+#             */
/*   Updated: 2022/12/31 18:37:26 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap_bonus.h"

void	rra(struct s_push_swap_bonus *ps, int count)
{
	int	*tmp;

	if (ps->a.top < 0 || count == 0)
		return ;
	tmp = ft_calloc(ps, sizeof(int), count);
	deep_copy(tmp, ps->a.stack, count);
	deep_copy(ps->a.stack, ps->a.stack + count, ps->a.top + 1 - count);
	deep_copy(ps->a.stack + ps->a.top - count + 1, tmp, count);
	free(tmp);
	tmp = NULL;
}

void	rrb(struct s_push_swap_bonus *ps, int count)
{
	int	*tmp;

	if (ps->b.top < 0 || count == 0)
		return ;
	tmp = ft_calloc(ps, sizeof(int), count);
	deep_copy(tmp, ps->b.stack, count);
	deep_copy(ps->b.stack, ps->b.stack + count, ps->b.top + 1 - count);
	deep_copy(ps->b.stack + ps->b.top - count + 1, tmp, count);
	free(tmp);
	tmp = NULL;
}

void	rrr(struct s_push_swap_bonus *ps, int count)
{
	if (ps->a.top < 0 || ps->b.top < 0 || count == 0)
		return ;
	rra(ps, count);
	rrb(ps, count);
}
