/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:34:46 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/28 12:31:22 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of words in a string separated by a character.
 *
 * The `ft_num_word` function iterates over the string `s` and counts the number
 * of words that are separated by the character `c`. A word is defined as
 * a sequence of characters that does not contain `c`.
 *
 * @param s The string to analyze.
 * @param c The character that separates the words in the string.
 * @return int The number of words found in the string.
 */
static int	ft_num_word(const char *s, char c)
{
	int	i;
	int	iw;

	i = 0;
	iw = 0;
	while (*s)
	{
		if (iw == 0 && *s != c)
		{
			iw = 1;
			i++;
		}
		else if (iw == 1 && *s == c)
			iw = 0;
		s++;
	}
	return (i);
}

/**
 * @brief Calculates the length of a word in a string up to a given character.
 *
 * The `ft_len_word` function iterates through the string `str` until it
 * encounters the character `c` or the end of the string, and returns the
 * number of characters before this separator character.
 *
 * @param str The string to analyze.
 * @param c The separator character that marks the end of the word.
 * @return int The length of the word before the character `c`.
 */
static int	ft_len_word(const char *str, char c)
{
	int	i;

	i = 0;
	while (*str && *str != c)
	{
		str++;
		i++;
	}
	return (i);
}

/**
 * @brief Frees the memory allocated for an array of strings.
 *
 * The `ft_freetab` function frees each string in the array `str`
 * up to the index `j`, and then frees the array itself. It is used to free
 * memory in case of an error during memory allocation in `ft_split`.
 *
 * @param str The array of strings to free.
 * @param j The number of strings to free before returning `NULL`.
 * @return char** Always `NULL` after freeing the memory.
 */
char	**ft_freetab(char **tab, unsigned int j)
{
	unsigned int	i;

	if (!j)
	{
		j = 0;
		while (tab[j])
			j++;
	}
	i = 0;
	while (i < j)
	{
		free(tab[i++]);
	}
	free(tab);
	return (NULL);
}

/**
 * @brief Split a string into an array of substrings, separated by a character.
 *
 * The `ft_split` function divides the string `s` into multiple substrings,
 * using the character `c` as a separator. It returns an array of strings,
 * where each element is a word extracted from the original string. If a memory
 * allocation error occurs, it frees the allocated resources before returning
 * `NULL`.
 *
 * @param s The string to split.
 * @param c The character that separates the words in the string.
 * @return char** An array of strings, or `NULL` in case of an error.
 */
char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		nw;

	i = 0;
	nw = ft_num_word(s, c);
	str = (char **)malloc(sizeof(char *) * (nw + 1));
	if (!str)
		return (NULL);
	while (nw--)
	{
		while (*s && *s == c)
			s++;
		str[i] = ft_substr(s, 0, ft_len_word(s, c));
		if (!str[i])
			return (ft_freetab(str, i));
		s = s + ft_len_word(s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
