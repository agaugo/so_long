/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:12:58 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 15:17:13 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buffer;

	i = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_empty_string());
	buffer = (char *)malloc(sizeof(char) * len + 1);
	if (!buffer)
		return (0);
	while (i < len && s[start] != '\0')
	{
		buffer[i] = s[start];
		i++;
		start++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_empty_string(void)
{
	char	*buffer;

	buffer = malloc(1);
	if (!buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer[0] = '\0';
	return (buffer);
}

char	*ft_strchr(const char *s, int c)
{
	char			*target;
	char			c_char;

	target = (char *)s;
	c_char = (char)c;
	while (*target)
	{
		if (*target == c_char)
			return (target);
		target++;
	}
	if (c_char == '\0')
		return (target);
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	c;
	char			*buffer;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	c = 0;
	buffer = malloc((sizeof(char const) * len) + 1);
	if (!buffer)
		return (0);
	while (s1[i] != '\0')
	{
		buffer[i] = s1[i];
		i++;
	}
	while (s2[c] != '\0')
	{
		buffer[i + c] = s2[c];
		c++;
	}
	buffer[i + c] = '\0';
	return (buffer);
}
