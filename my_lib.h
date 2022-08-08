#pragma once
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int my_puts(const char *str);
size_t my_strlen(const char *str);
char *my_strcpy(char* dest, const char* src);
char *my_strncpy(char *dest, const char *src, int count);
char *my_strcat(char *dest, const char *src);
char *my_strncat(char *dest, const char *src, int count);
char *my_fgets(char* str, int count, FILE* stream);
char *my_strdup(const char *src);
const char *my_strchr(const char* str, int ch);
