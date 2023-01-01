/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:14:13 by juhur             #+#    #+#             */
/*   Updated: 2023/01/01 13:40:42 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "push_swap_bonus.h"

static int	count_all_word(int len, char **input)
{
	int	ret;
	int	i;

	ret = 0;
	i = -1;
	while (++i < len)
		ret += count_word(input[i]);
	return (ret);
}

static void	execute(struct s_push_swap_bonus *ps, char *command)
{
	if (!strcmp(command, "rr"))
		rr(ps, 1);
	else if (!strcmp(command, "ra"))
		ra(ps, 1);
	else if (!strcmp(command, "rb"))
		rb(ps, 1);
	else if (!strcmp(command, "rrr"))
		rrr(ps, 1);
	else if (!strcmp(command, "rra"))
		rra(ps, 1);
	else if (!strcmp(command, "rrb"))
		rrb(ps, 1);
	else if (!strcmp(command, "ss"))
		ss(ps);
	else if (!strcmp(command, "sa"))
		sa(ps);
	else if (!strcmp(command, "sb"))
		sb(ps);
	else if (!strcmp(command, "pa"))
		pa(ps);
	else if (!strcmp(command, "pb"))
		pb(ps);
	else
		quit_push_swap(ps, ERROR);
}

int	main(int argc, char **argv)
{
	struct s_push_swap_bonus	ps;
	char						*line;
	int							i;

	if (argc == 1)
		return (0);
	ps.count = count_all_word(argc - 1, argv + 1);
	init(&ps);
	split(&ps, argc, argv);
	to_integer(&ps, ps.s);
	while (true)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		execute(&ps, line);
		free(line);
		line = NULL;
	}
	i = -1;
	while (++i < ps.a.top)
		if (ps.a.stack[i] < ps.a.stack[i + 1])
			quit_push_swap(&ps, KO);
	write(1, OK, ft_strlen(OK));
	return (0);
}
