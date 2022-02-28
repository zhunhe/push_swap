/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:23:15 by juhur             #+#    #+#             */
/*   Updated: 2022/02/28 17:25:10 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

static void	free_2d_array(t_push_swap *ps, void **ptr)
{
	int	i;

	if (ptr != NULL)
	{
		i = -1;
		while (++i < ps->count)
		{
			if (ptr[i])
				free(ptr[i]);
			ptr[i] = NULL;
		}
		free(ptr);
		ptr = NULL;
	}
}

static void	free_1d_array(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
}

void	quit_push_swap(t_push_swap *ps, char *str)
{
	if (ps != NULL)
	{
		free_2d_array(ps, (void **)ps->nums);
		free_2d_array(ps, (void **)ps->tmp);
		free_2d_array(ps, (void **)ps->lis.arr);
		free_1d_array((void *)ps->a.stack);
		free_1d_array((void *)ps->b.stack);
		free_1d_array((void *)ps->lis.dp);
	}
	if (str != NULL)
		write(1, str, ft_strlen(str));
	exit(0);
}
