/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:11:45 by juhur             #+#    #+#             */
/*   Updated: 2022/12/31 15:45:38 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

struct s_stack
{
	int	*stack;
	int	top;
};

struct s_push_swap_bonus
{
	struct s_stack a;
	struct s_stack b;
};

#endif
