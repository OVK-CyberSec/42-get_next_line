/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:07:50 by mohifdi           #+#    #+#             */
/*   Updated: 2025/04/18 18:07:53 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static t_list *list = NULL;
    char *next_line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, BUFFER_SIZE) < 0)
        return (NULL);
    create_list(&list, fd);
    if (!list)
        return (NULL);
    next_line = get_line(list);


    if ()
    return line;
}


void    append(t_list **list, char *buf)
{
    t_list *new_node;
    t_list *last_node;

    last_node = find_last_node(*list)
    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return ;
    if (last_node == NULL)
        *list = new_node;
    else
        last_node->next = new_node;
    new_node->content = buf;
    new_node->next = NULL;
}
