#include "my_lib.h"

int my_puts(const char *str) 
{
    long i = 0;

    if (str == NULL) { 
        return EOF;
    }

    for (i; str[i] != '\0'; i++) {
        if (putchar(str[i]) == EOF) {
            return EOF;
        }
    }
    putchar('\n');

    return str[i - 1];
}

//------------------------------------------------------------------

size_t my_strlen(const char *str)
{
    assert(str);

    size_t len = 0;

    while (str[len] != '\0') {
        len++;
    }

    return len;
}

//------------------------------------------------------------------

char* my_strcpy(char* dest, const char* src)
{
    assert(dest);
    assert(src);

    long i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return dest;
}

//------------------------------------------------------------------

char *my_strncpy(char *dest, const char *src, int count)
{
    assert(dest);
    assert(src);

    long i = 0;

    for (i; i < count && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }

    while (i < count) {
        dest[i] = '\0';
        i++;
    }

    return dest;
}

//------------------------------------------------------------------

char *my_strcat(char *dest, const char *src) 
{
    assert(dest);
    assert(src);

    size_t len = my_strlen(dest);
    long i = 0;

    for (i; src[i] != '\0'; i++) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';

    return dest;
}

//------------------------------------------------------------------

char *my_strncat(char *dest, const char *src, int count)
{
    assert(dest);
    assert(src);

    size_t len = my_strlen(dest);
    long i = 0;

    for (i; i < count && src[i] != '\0'; i++) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';

    return dest;
}

//------------------------------------------------------------------

char *my_fgets(char* str, int count, FILE* stream)
{
    assert(str);
    assert(stream);

    long i = 0;

    for (i; i < count; i++) {
        int symb = getc(stream);

        if (symb != '\n' && symb != EOF) {
            str[i] = symb;
        }
        else{
            break;
        }
    }

    return (ferror(stream) || (i == 0 && feof(stream))) ? NULL : str;
}

//------------------------------------------------------------------

char *my_strdup(const char *src)
{
    assert(src);

    size_t len = my_strlen(src);
    char *p = (char *) malloc(len + 1);
    long i = 0;

    if (p == NULL) {
        return NULL;
    }

    for (i; i < len + 1; i++) {
        p[i] = src[i];
    }

    return p;
}

//------------------------------------------------------------------

const char *my_strchr(const char* str, int ch) 
{
    assert(str);
    
    long i = 0;
    for (i; str[i]; i++) {

        if (str[i] == ch) {
            return &str[i];
        }
    }

    return NULL;
}

