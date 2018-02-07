/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:01:52 by rtarasen          #+#    #+#             */
/*   Updated: 2018/01/13 13:44:34 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_words(char const *s, char c)
{
	size_t i;
	size_t result;

	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			result++;
		i++;
	}
	return (result);
}

static	size_t	get_wordlen(char const *s, char c, size_t *i)
{
	size_t word_len;

	word_len = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		word_len++;
		*i = *i + 1;
	}
	return (word_len);
}

static	void	ft_putwords(char const *s, char c, char **dest, size_t words_nb)
{
	size_t i;
	size_t j;
	size_t word_len;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < words_nb)
	{
		if ((word_len = get_wordlen(s, c, &i)) != 0)
		{
			if ((dest[j] = ft_strsub(s, i - word_len, word_len)) == NULL)
				return (ft_strarr_del(&dest));
			j++;
		}
		i++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	words;
	char	**result;

	if (s == NULL)
		return (NULL);
	words = get_words(s, c);
	if (words == 0)
	{
		result = ft_strarr_new(1);
		*result = 0;
		return (result);
	}
	result = ft_strarr_new(words + 1);
	if (result == NULL)
		return (NULL);
	ft_putwords(s, c, result, words);
	return (result);
}
