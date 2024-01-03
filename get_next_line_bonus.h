/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorin <smorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:56:46 by smorin            #+#    #+#             */
/*   Updated: 2023/12/19 11:46:43 by smorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
# endif

char	*get_next_line(int fd);
char	*ft_clean_save(char *save);
char	*ft_get_line(char *save);
char	*ft_read(int fd, char *save);
char	*ft_strndup(char *str, int n);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif