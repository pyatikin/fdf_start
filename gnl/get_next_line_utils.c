/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 14:56:54 by tgwin             #+#    #+#             */
/*   Updated: 2021/12/30 14:56:57 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup_str;

	dup_str = malloc((ft_strlen(s) + 1) * sizeof(*s));
	if (dup_str)
	{
		i = -1;
		while (s[++i])
			dup_str[i] = s[i];
		dup_str[i] = '\0';
	}
	return (dup_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*join_str;

	if (!s1 || !s2)
		return (NULL);
	join_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*s1));
	if (!join_str)
		return (NULL);
	i = -1;
	while (s1[++i])
		join_str[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		join_str[i] = s2[j];
		i++;
	}
	join_str[i] = '\0';
	return (join_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	const char	*source;
	char		*dest;
	size_t		max_len;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	source = s + start;
	max_len = ft_strlen(source);
	if (max_len < len)
		len = max_len;
	substr = malloc(sizeof(*substr) * (len + 1));
	if (!substr)
		return (NULL);
	dest = substr;
	while (source && len--)
		*dest++ = *source++;
	*dest = '\0';
	return (substr);
}
