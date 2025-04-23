/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:10:57 by mohifdi           #+#    #+#             */
/*   Updated: 2025/04/18 18:10:59 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef get_next_line_h
# define get_next_line_h

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

typedef struct s_list
{
    char    *content;
        struct s_list *next;
}   t_list;



void  create_list(t_list **list, int fd);
void    append(t_list **list, char *buf);
void    start_new_line(t_list **list);
void    dealloc(t_list **list, t_list *clean_node, char *buf);
int	    found_newline(t_list *list);
t_list	*find_last_node(t_list *lst);
char    *get_next_line(int fd);
int	len_to_newline(t_list *list);
void    copy_str(t_list *list, char *str);
void    get_new_line(t_list **list);
char	*get_line(t_list *list);

#endif