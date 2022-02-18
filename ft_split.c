/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:16:45 by kmilchev          #+#    #+#             */
/*   Updated: 2021/11/26 22:16:45 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_strings(char const *s, char c);
static void	ft_find_word(char **next_str, int *s_len, char c);
static char	**ft_free(char **array);

char	**ft_split(char const *s, char c)
{
	char	**strings;
	char	*next_str;
	int		s_len;
	int		nbr_strings;
	int		i;

	if (!s)
		return (NULL);
	nbr_strings = ft_count_strings(s, c);
	strings = (char **)ft_calloc(nbr_strings + 1, sizeof(char *));
	if (!(strings))
		return (NULL);
	i = -1;
	s_len = 0;
	next_str = (char *)s;
	while (++i < nbr_strings)
	{
		ft_find_word(&next_str, &s_len, c);
		strings[i] = (char *)ft_calloc(s_len + 1, sizeof(char));
		if (!strings[i])
			return (ft_free(strings));
		ft_strlcpy(strings[i], next_str, s_len + 1);
	}
	strings[i] = NULL;
	return (strings);
}

static int	ft_count_strings(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

static void	ft_find_word(char **next_str, int *s_len, char c)
{
	int	i;

	*next_str += *s_len;
	*s_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*s_len)++;
		i++;
	}
}

static char	**ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

// #include <unistd.h>
// void	ft_print_result(char const *s)
// {
// 	int		len;
// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }
// int main()
// {
// 	char	**tabstr;
// 	int		i;
// 	i = 0;
// 	if (!(tabstr = ft_split("z zz", 'z')))
// 			ft_print_result("NULL");
// 		else
// 		{
// 			while (tabstr[i] != NULL)
// 			{
// 				ft_print_result(tabstr[i]);
// 				write(1, "\n", 1);
// 				i++;
// 			}
// 		}
// }