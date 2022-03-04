/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:58:39 by juhur             #+#    #+#             */
/*   Updated: 2022/03/04 09:45:35 by juhur            ###   ########.fr       */
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

static void	ft_split_free(char **ret, int i)
{
	while (i >= 0)
	{
		free(ret[i]);
		ret[i] = NULL;
		--i;
	}
	free(ret);
	ret = NULL;
	quit_push_swap(NULL, ERROR);
}

/*
** Allocates (with malloc(3)) and returns an array of strings obtained
** by splitting ’s’ using the character ’c’ as a delimiter.
** The array must be ended by a NULL pointer.
*/
char	**ft_split(char const *s, int w_cnt)
{
	char	**ret;
	int		i;
	int		j;
	int		w_len;

	if (s == NULL)
		return (NULL);
	ret = ft_calloc(NULL, sizeof(char *), w_cnt);
	i = -1;
	while (++i < w_cnt)
	{
		while (*s != '\0' && *s == ' ')
			++s;
		w_len = get_word_len(s, ' ');
		ret[i] = (char *)malloc(sizeof(char) * (w_len + 1));
		if (ret[i] == NULL)
			ft_split_free(ret, i);
		j = -1;
		while (++j < w_len)
			ret[i][j] = *(s++);
		ret[i][j] = '\0';
		++s;
	}
	return (ret);
}
