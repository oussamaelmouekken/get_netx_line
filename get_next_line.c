#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *line;
    char *buffer;
    static char *stock = NULL;
    size_t d = 1;

    if(fd < 0 || BUFFER_SIZE <= 0)
     return(0);

    buffer = malloc( BUFFER_SIZE + 1);
    if(!buffer)
     return NULL;

    while(d > 0)
    {
        d = read(fd, buffer, BUFFER_SIZE);
        if(d == -1)
        {
            free(buffer);
            return (0);
        }
        buffer[d] = '\0';
        if (stock == NULL)
         stock = malloc(1);

        char *ttemp = malloc(ft_strlen(stock) + d + 1);
        if (ttemp == NULL)
        {
        free(buffer);
        return NULL;
        }
        if (stock != NULL)
        {
        ft_strncpy(ttemp, stock, ft_strlen(stock));
        free(stock);
        }
        stock = ttemp;
        stock = ft_strcat(stock, buffer);
        free(buffer);
        char *linepas = ft_strchr(stock, '\n');
        size_t line_length = 0;

        if (linepas != NULL)
        {
            line_length = linepas - stock + 1; 
            line = malloc(line_length + 1);
            if (line == NULL)
                return (0);
            ft_strncpy(line, stock, line_length);
            line[line_length] = '\0';

            char *temp = ft_strdup(linepas + 1);
            free(stock);
            stock = temp;
            return (line);
        }
    }
    return (NULL);
}
// int main () 
// {
//     int f;
//     f = open("abdo.txt",O_RDONLY | O_CREAT,0644);

//     printf("%s",get_next_line(f));
//     printf("%s",get_next_line(f));
//     printf("%s",get_next_line(f));
//     printf("%s",get_next_line(f));
//     printf("%s",get_next_line(f));
// }