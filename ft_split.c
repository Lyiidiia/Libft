/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuellar <lcuellar@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:58:50 by lcuellar          #+#    #+#             */
/*   Updated: 2023/09/16 15:14:33 by lcuellar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	if (s[0] != c)
		words++;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && i > 0 && s[i - 1] == c)
			words++;
		if (s[i])
			i++;
	}
	return (words);
}

static char	**ft_mem(char **str, char const *s, char c)
{
	int	count;
	int	i;
	int	word;

	count = 0;
	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			count++;
		}
		str[word] = (char *)malloc(sizeof(char) * (count + 1));
		if (!str[word])
			return (NULL);
		word++;
		count = 0;
	}
	return (str);
}

static char	**ft_fill(char **str, char const *s, char c)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	j = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			str[word][j++] = s[i++];
		str[word][j] = '\0';
		word++;
		j = 0;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;

	words = ft_words(s, c);
	if (!s || !s[0])
	{
		split = (char **)malloc(sizeof(char *));
		if (!split)
			return (NULL);
		*split = NULL;
		return (split);
	}
	words = ft_words(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	if (ft_mem(split, s, c) != NULL)
		ft_fill(split, s, c);
	else
	{
		free(split);
		return (NULL);
	}
	split[words] = NULL;
	return (split);
}
