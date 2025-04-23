#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


int main()
{
    int fd;
    char *line;
    int lines;
    int i = 0;
    
    fd = open("file.txt", O_RDONLY);

    while ((line = get_next_line(fd)))
    {
        printf("%d -> %s\n",i++, line);
    }
}