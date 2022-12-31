/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 13:27:07 by juhur             #+#    #+#             */
/*   Updated: 2023/01/01 13:28:27 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(struct s_push_swap_bonus *ps)
{
	if (ps->b.top < 0)
		return ;
	ps->a.stack[++ps->a.top] = ps->b.stack[ps->b.top];
	ps->b.stack[ps->b.top--] = 0;
}

void	pb(struct s_push_swap_bonus *ps)
{
	if (ps->a.top < 0)
		return ;
	ps->b.stack[++ps->b.top] = ps->a.stack[ps->a.top];
	ps->a.stack[ps->a.top--] = 0;
}
