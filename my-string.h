#include <string.h>
#include "my_lib.cpp"

int test ()
{
    char str1[] = "Testing ";
    char str2[] = "program";


}

int test(char *str1, char *str2)
{
    //puts
    my_puts(str1);
    puts(str1);

    //strlen
    if(my_strlen(str1) != strlen(str1)) {
        printf("Error in my_strlen(). Received value is %d instead of %d\n",
                my_strlen(str1), strlen(str1));
    }

    //strcpy
    char s1[], s2[];

    my_strcpy(s1, str1);
    strcpy(s2, str2);

    if (strcmp(s1, s2)) {
        printf("Error in my_strcpy().");
    }

    //strncpy
    

}