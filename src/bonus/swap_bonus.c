/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:21:18 by juhur             #+#    #+#             */
/*   Updated: 2022/12/31 18:37:48 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(struct s_push_swap_bonus *ps)
{
	if (ps->a.top < 1)
		return ;
	swap(&ps->a.stack[ps->a.top], &ps->a.stack[ps->a.top - 1]);
}

void	sb(struct s_push_swap_bonus *ps)
{
	if (ps->b.top < 1)
		return ;
	swap(&ps->b.stack[ps->b.top], &ps->b.stack[ps->b.top - 1]);
}

void	ss(struct s_push_swap_bonus *ps)
{
	if (ps->a.top < 1 || ps->b.top < 1)
		return ;
	sb(ps);
	sa(ps);
}
