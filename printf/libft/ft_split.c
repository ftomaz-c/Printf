/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student@42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:11:11 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/04/24 16:25:29 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns an array of strings obtained by	*/
/* splitting ’s’ using the character ’c’ as a delimiter. The array must end	*/
/* with a NULL pointer. Returns the array of new strings resulting from the	*/
/* split or NULL if the allocation fails.									*/
/*s: The string to be split.												*/
/*c: The delimiter character.												*/

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int	count;
	int	switcher;

	count = 0;
	switcher = 0;
	while (*s != '\0')
	{
		if (*s != c && switcher == 0)
		{
			switcher = 1;
			count++;
		}
		else if (*s == c)
			switcher = 0;
		s++;
	}
	return (count);
}

static char	*new_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc((end - start + 1), sizeof(char));
	if (!word || !s)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	split = ft_calloc (count_words(s, c) + 1, sizeof(char *));
	if (!split || !s)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c && start >= 0) || (s[i] != c && i == ft_strlen(s)))
		{
			split[j++] = new_word(s, start, i);
			start = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
