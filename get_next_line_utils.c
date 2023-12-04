/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorin <smorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:35:04 by smorin            #+#    #+#             */
/*   Updated: 2023/12/04 16:46:51 by smorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Looks for a newline character in the given linked list. */

int	found_newline(t_list *block)
{
	int		i;
	t_list	*current;

	if (block == NULL)
		return (0);
	current = ft_lst_get_last(block);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lst_get_last(t_list *block)
{
	t_list	*current;

	current = block;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	generate_line(char **line, t_list *block)
{
	int	i;
	int	len;

	len = 0;
	while (block)
	{
		i = 0;
		while (block->content[i])
		{
			if (block->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		block = block->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	free_block(t_list *block)
{
	t_list	*current;
	t_list	*next;

	current = block;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}