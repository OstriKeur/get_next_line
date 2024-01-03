/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorin <smorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:55:43 by smorin            #+#    #+#             */
/*   Updated: 2023/12/19 11:46:11 by smorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*save[4095];
	char		*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	save[fd] = ft_read(fd, save[fd]);
	if (!save[fd] || save[fd][0] == 0)
	{
		free(save[fd]);
		save[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(save[fd]);
	if (!line || line[0] == 0)
		return (free(line), free(save[fd]), NULL);
	save[fd] = ft_clean_save(save[fd]);
	if (save[fd] && save[fd][0] == 0)
	{
		free(save[fd]);
		save[fd] = NULL;
	}
	return (line);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
