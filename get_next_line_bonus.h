
#ifndef get_next_line_bonus_h
# define get_next_line_bonus_h

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*get_next_line(int fd);
char	*create_line(int fd, char *line);
int     found_newline(char *str);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *left_str, char *buff);
char	*get_line(char *left_str);
char	*fetch_new_line(char *left_str);

#endif