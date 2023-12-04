/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorin <smorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:35:12 by smorin            #+#    #+#             */
/*   Updated: 2023/12/04 17:23:32 by smorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	read_and_block(fd, &stash);
	if (stash == NULL)
		return (NULL);
	extract_line(stash, &line);
	clean_block(&stash);
	if (line[0] == '\0')
	{
		free_block(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

/* Cette fonction sert a ajouter des caracteres */

void	read_and_block(int fd, t_list **block)
{
	char	*buf;
	int		readed;

	readed = 1;
	while (!found_newline(*block) && readed != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		readed = (int)read(fd, buf, BUFFER_SIZE);
		if ((*block == NULL && readed == 0) || readed == -1)
		{
			free(buf);
			return ;
		}
		buf[readed] = '\0';
		add_to_block(block, buf, readed);
		free(buf);
	}
}

/* Ajoute le contenu de notre buffer à la fin de notre block.  */

void	add_to_block(t_list **block, char *buf, int readed)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buf[i] && i < readed)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*block == NULL)
	{
		*block = new_node;
		return ;
	}
	last = ft_lst_get_last(*block);
	last->next = new_node;
}

/* Extrait tous les caractères de notre block et les stocke dans notre ligne.
 * s'arrête après le premier \n qu'il rencontre  */
void	extract_line(t_list *block, char **line)
{
	int	i;
	int	j;

	if (block == NULL)
		return ;
	generate_line(line, block);
	if (*line == NULL)
		return ;
	j = 0;
	while (block)
	{
		i = 0;
		while (block->content[i])
		{
			if (block->content[i] == '\n')
			{
				(*line)[j++] = block->content[i];
				break ;
			}
			(*line)[j++] = block->content[i++];
		}
		block = block->next;
	}
	(*line)[j] = '\0';
}

/* Après avoir extrait la ligne qui a été lue,
	nous n'avons plus besoin de ces caractères

	* plus besoin de ces caractères. Cette fonction nettoie le block afin que seuls les caractères qui n'ont pas été renvoyés à la fin de get_next_line restent dans notre réserve statique.

	* pas été renvoyés à la fin de get_next_line restent dans notre block statique. */

void	clean_block(t_list **block)
{
	t_list *last;
	t_list *clean;
	int i;
	int j;

	clean = malloc(sizeof(t_list));
	if (block == NULL || clean == NULL)
		return ;
	clean->next = NULL;
	last = ft_lst_get_last(*block);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i)
				+ 1));
	if (clean->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean->content[j++] = last->content[i++];
	clean->content[j] = '\0';
	free_block(*block);
	*block = clean;
}