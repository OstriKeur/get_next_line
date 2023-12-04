/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorin <smorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:34:06 by smorin            #+#    #+#             */
/*   Updated: 2023/12/04 17:31:02 by smorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> // REMOVE FOR PUSH
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
    char    *content; 
	struct s_list   *next;
}					t_list;

char    *get_next_line(int fd);
int found_newline(t_list *stash);
t_list  *ft_lst_get_last(t_list *block);
void    read_and_block(int fd, t_list **block);
void    add_to_block(t_list **block, char *buf, int readed);
void    extract_line(t_list *block, char **line);
void    generate_line(char **line, t_list *block);
void    clean_block(t_list **block);
int	    ft_strlen(const char *str);
void    free_block(t_list *block);
#endif