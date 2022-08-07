#include <string.h>
#include "my_lib.cpp"

int test ()
{
    char str1[] = "Testing ";
    char str2[] = "program";

    int failed_tests = test(str1, str2);
    if (failed_tests == 0) {
        printf("All tests passed successfully.\n");
    }
    else {
        printf("Tests failed: %d\n", failed_tests);
    }
}

int test(char *str1, char *str2)
{
    int failed_tests = 0;

    //puts
    my_puts(str1);
    puts(str1);

    //strlen
    if(my_strlen(str1) != strlen(str1)) {
        printf("Error in my_strlen(). Received value is %d instead of %d\n",
                my_strlen(str1), strlen(str1));
    }
    failed_tests++;

    //strcpy
    char s1[], s2[];

    my_strcpy(s1, str1);
    strcpy(s2, str2);

    if (strcmp(s1, s2)) {
        printf("Error in my_strcpy().\n");
    }
    failed_tests++;

    //strncpy
    int count = 8;
    my_strncpy(s1, str2, count);
    strncpy(s2, str2, count);

    if (strcmp(s1, s2)) {
        printf("Error in my_strncpy().\n");
    }
    failed_tests++;

    //strcat
    strcpy(s1, str1);
    strcpy(s2, str1);

    my_strcat(s1, str2);
    strcat(s2, str2);

    if (strcmp(s1, s2)) {
        printf("Error in my_strcat().\n");
    }
    failed_tests++;

    //strncat
    strcpy(s1, str1);
    strcpy(s2, str1);

    my_strncat(s1, str2);
    strcat(s2, str2);

    if (strcmp(s1, s2)) {
        printf("Error in my_strcat().\n");
    }
    failed_tests++;

    //fgets

    //strdup
    char *p_s1 = my_strdup(str1);
    char *p_s2 = strdup(str1);

    if (strcmp(p_s1, p_s2)) {
        printf("Error in my_strdup().\n");
    }
    failed_tests++;

    //strchr
    int ch1 = 'a';
    int ch2 = 'h';

    int ch1_comp = my_strchr(str2, ch1) != strchr(str2, ch1);
    int ch2_comp = my_strchr(str2, ch2) != strchr(str2, ch2);

    if (ch1_comp || ch2_comp) {
        printf("Error in my_strchr() with symbol ");
        if (ch1_comp) {
            putchar(ch1);
        }
        else {
            putchar(ch2);
        } 
        printf("\n");
    }
    
    return failed_tests;
}