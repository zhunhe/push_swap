/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:46:44 by juhur             #+#    #+#             */
/*   Updated: 2023/01/01 15:04:59 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap_bonus.h"

void	ra(struct s_push_swap_bonus *ps, int count)
{
	int	i;
	int	*tmp;

	if (ps->a.top < 0 || count == 0)
		return ;
	tmp = ft_calloc(ps, sizeof(int), count);
	deep_copy(tmp, ps->a.stack + ps->a.top - count + 1, count);
	i = ps->a.top - count + 1;
	while (--i >= 0)
		ps->a.stack[i + count] = ps->a.stack[i];
	deep_copy(ps->a.stack, tmp, count);
	free(tmp);
	tmp = NULL;
}

void	rb(struct s_push_swap_bonus *ps, int count)
{
	int	i;
	int	*tmp;

	if (ps->b.top < 0 || count == 0)
		return ;
	tmp = ft_calloc(ps, sizeof(int), count);
	deep_copy(tmp, ps->b.stack + ps->b.top - count + 1, count);
	i = ps->b.top - count + 1;
	while (--i >= 0)
		ps->b.stack[i + count] = ps->b.stack[i];
	deep_copy(ps->b.stack, tmp, count);
	free(tmp);
	tmp = NULL;
}

void	rr(struct s_push_swap_bonus *ps, int count)
{
	if (count == 0)
		return ;
	ra(ps, count);
	rb(ps, count);
}
