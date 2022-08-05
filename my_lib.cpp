#include <stdio.h>
#include <stddef.h>

int my_puts( const char *str ) 
{
    if (str == NULL) {
        return EOF;
    }
    for (long i = 0; str[i] != '\0'; i++) {
        if (putchar(srt[i]) == EOF) {
            return EOF;
        }
    }
    putchar('\n');

    return 1;
}

//------------------------------------------------------------------

size_t my_strlen( const char *str )
{
    size_t len = 0;

    while (str[len] != '\0') {
        len++;
    }

    return len;
}

//------------------------------------------------------------------

char* strcpy( char* dest, const char* src )
{
    long i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    return dest;
}

//------------------------------------------------------------------

char *strncpy( char *dest, const char *src, int count )
{
    for (long i = 0; i < count && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }

    while (i < count) {
        dest[i] = '\0';
        i++;
    }

    return dest;
}

