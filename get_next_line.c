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

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
        return (NULL);
    create_list(&list, fd);
    if (!list)
        return (NULL);
    next_line = get_line(list);

    get_new_line(&list);
    return (next_line);
}

void  create_list(t_list **list, int fd)
{
    int char_readed;
    char *buf;

    while(!found_newline(*list))
    {
        buf = malloc(BUFFER_SIZE + 1);
        if (!buf)
            return ;
        char_readed = read(fd, buf, BUFFER_SIZE);
        if (!char_readed)
        {
            free(buf);
            return ;
        }
        buf[char_readed] = '\0';
        append(list, buf);
    }
}

void    append(t_list **list, char *buf)
{
    t_list *new_node;
    t_list *last_node;

    last_node = find_last_node(*list);
    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return ;
    if (!last_node)
        *list = new_node;
    else
        last_node->next = new_node;
    new_node->content = buf;
    new_node->next = NULL;
}

void    get_new_line(t_list **list)
{
    t_list  *last_node;
    t_list  *clean_node;
    int i;
    int k;
    char    *buf;

    buf = malloc(BUFFER_SIZE + 1);
    clean_node = malloc(sizeof(t_list));
    if (!buf || !clean_node)
        return ;
    last_node = find_last_node(*list);
    i = 0;
    k = 0;
    while (last_node->content[i] && last_node->content[i] != '\n')
            i++;
    while (last_node->content[i] && last_node->content[++i])
            buf[k++] = last_node->content[i];
    buf[k] = '\0';
    clean_node->content = buf;
    clean_node->next = NULL;
    dealloc(list, clean_node, buf);
}

char	*get_line(t_list *list)
{
	char    *line;
    int str_len;

    if (!list)
        return (NULL);
    str_len = len_to_newline(list);
    line = malloc(str_len + 1);
    if (!line)
        return (NULL);
    copy_str(list, line);
    return (line);
}

// int main()
// {
//     int fd;
//     char *line;
//     int lines;
//     int i = 0;
    
//     fd = open("file.txt", O_RDONLY);

//     while ((line = get_next_line(fd)))
//     {
//         printf("%d -> %s\n",i++, line);
//     }
// }