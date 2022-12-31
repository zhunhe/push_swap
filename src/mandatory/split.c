/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:58:39 by juhur             #+#    #+#             */
/*   Updated: 2022/03/11 22:54:02 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static int	get_word_len(char const *s, char c)
{
	int	w_len;

	w_len = 0;
	while (s[w_len] != '\0' && s[w_len] != c)
		++w_len;
	return (w_len);
}

int	count_word(char *s)
{
	int	word_cnt;
	int	i;

	word_cnt = 0;
	i = -1;
	while (s[++i] != '\0')
		if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ')
			++word_cnt;
	return (word_cnt);
}

void	split(t_push_swap *ps, int argc, char **argv)
{
	int	idx;
	int	i;
	int	j;
	int	w_cnt;
	int	w_len;

	idx = 0;
	i = 0;
	while (++i < argc)
	{
		w_cnt = count_word(argv[i]);
		while (w_cnt--)
		{
			while (*(argv[i]) != '\0' && *argv[i] == ' ')
				++argv[i];
			w_len = get_word_len(argv[i], ' ');
			ps->s[idx] = (char *)malloc(sizeof(char) * (w_len + 1));
			if (ps->s[idx] == NULL)
				quit_push_swap(ps, ERROR);
			j = -1;
			while (++j < w_len)
				ps->s[idx][j] = *(argv[i]++);
			ps->s[idx++][w_len] = '\0';
		}
	}
}
