/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorin <smorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:00:55 by smorin            #+#    #+#             */
/*   Updated: 2023/12/19 11:46:20 by smorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strndup(char *str, int n)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	while (str[i] && i < n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_read(int fd, char *save)
{
	char	*tmp;
	int		readbytes;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	readbytes = 1;
	if (!save)
	{
		save = malloc(sizeof(char) * 1);
		if (!save)
			return (NULL);
		save[0] = '\0';
	}
	while (!ft_strchr(save, '\n') && readbytes != 0)
	{
		readbytes = read(fd, tmp, BUFFER_SIZE);
		if (readbytes == -1)
			return (free(tmp), free(save), NULL);
		tmp[readbytes] = '\0';
		save = ft_strjoin(save, tmp);
	}
	return (free(tmp), save);
}

char	*ft_get_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		line = ft_strndup(save, i + 1);
	else
		line = ft_strndup(save, i);
	return (line);
}

char	*ft_clean_save(char *save)
{
	int		i;
	int		len;
	char	*newsave;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	len = ft_strlen(save);
	if (!save[i])
		return (free(save), NULL);
	newsave = ft_strndup((save + i + 1), (len - i));
	if (newsave)
		free(save);
	return (newsave);
}
