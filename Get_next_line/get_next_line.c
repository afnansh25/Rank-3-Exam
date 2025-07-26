#include "get_next_line.h"

char *get_next_line(int fd)
{
    int bytes;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = malloc(1000000);
    bytes = read(fd, line, 1000000);
    if (bytes <= 0)
        return (free(line), NULL);
    line[bytes] = '\0';
    return(line);
}