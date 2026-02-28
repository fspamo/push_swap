/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:24:45 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/27 16:26:07 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	if (!s)
		return (0);
	if (c == 0)
		return (1);
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static size_t	word_length(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (c == 0)
	{
		while (s[i])
			i++;
		return (i);
	}
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_allfree(char **s, size_t w)
{
	size_t	i;

	i = 0;
	while (i < w)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static void	ft_skip(char **s, char c)
{
	if (c == 0)
		return ;
	while (**s == c)
		(*s)++;
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	size_t	w;
	size_t	w_len;

	w = 0;
	if (!s)
		return (NULL);
	new_str = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!new_str)
		return (NULL);
	ft_skip((char **)&s, c);
	while (*s)
	{
		w_len = word_length(s, c);
		new_str[w] = malloc(w_len + 1);
		if (!new_str[w])
			return (ft_allfree(new_str, w), NULL);
		ft_memcpy(new_str[w], s, w_len);
		new_str[w][w_len] = '\0';
		s += w_len;
		ft_skip((char **)&s, c);
		w++;
	}
	new_str[w] = NULL;
	return (new_str);
}
