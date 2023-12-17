#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#define BUFFER_SIZE 10
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *get_next_line(int fd);

char	*ft_strdup(const char *src);

char * ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strcat(char *dest, char *src);

#endif 