#include <string.h>
#include "../lib/my_lib.h"
#include "test.h"

void test_run (void)
{
    char str1[] = "Testing ";
    char str2[] = "program"; 

    int failed_tests = 0;

    test_puts    (str1);
    failed_tests += test_strcpy  (str1, str2);
    failed_tests += test_strlen  (str1);              
    failed_tests += test_strncpy (str1, str2);             
    failed_tests += test_strcat  (str1, str2);            
    failed_tests += test_strncat (str1, str2);
    failed_tests += test_strdup  (str1, str2);
    failed_tests += test_strchr  (str2);

    if (failed_tests == 0) {
        printf ("All tests passed successfully.\n");
    }
    else {
        printf ("Tests failed: %d\n", failed_tests);
    }
}

//------------------------------------------------------------------

void test_puts (const char *str1)
{
    assert (str1);

    printf ("Test of my_puts():\n");
    
    printf ("String received with my_puts(): ");
    my_puts (str1);
    printf ("String received with puts(): ");
    puts (str1);
    printf ("\n");

}

//------------------------------------------------------------------

int test_strcpy (const char *str1, const char *str2)
{
    assert (str1);
    assert (str2);

    int failed = 0;

    char *s1 = strdup (str1);
    char *s2 = strdup (str1);

    printf ("Test of my_strcpy():\n");

    my_strcpy (s1, str2);
    strcpy (s2, str2);

    if (strcmp (s1, s2)) {
        printf ("Error in my_strcpy().\n");

        printf ("String received with my_strcpy(): ");
        puts (s1);
        printf ("String received with strcpy(): ");
        puts (s2);
        printf ("\n\n");

        failed++;
    }
    else {
        printf ("Test passed.\n\n");
    }

    free (s1);
    free (s2);

    return failed;
}

//------------------------------------------------------------------

int test_strlen (const char *str1) 
{
    assert (str1);

    int failed = 0;

    printf ("Test of my_strlen():\n");
    if (my_strlen (str1) != strlen (str1)) {
        printf ("Error in my_strlen(). Received value is %zu instead of %zu\n\n",
                my_strlen (str1), strlen (str1));

        failed++;
    }
    else {
        printf ("Test passed.\n\n");
    }

    return failed;
}

//------------------------------------------------------------------

int test_strncpy (const char *str1, const char *str2)
{
    assert (str1);
    assert (str2);

    int failed = 0;

    char *s1 = strdup (str1);
    char *s2 = strdup (str1);

    printf ("Test of my_strncpy():\n");

    int count = 8;
    my_strncpy (s1, str2, count);
    strncpy (s2, str2, count);

    if (strcmp (s1, s2)) {
        printf ("Error in my_strncpy().\n");

        printf ("String received with my_strncpy(): ");
        puts (s1);
        printf ("String received with strncpy(): ");
        puts (s2);
        printf ("\n\n");

        failed++;
    }
    else {
        printf ("Test passed.\n\n");
    }

    free (s1);
    free (s2);

    return failed;
}

//------------------------------------------------------------------

int test_strcat (const char *str1, const char *str2)
{
    assert (str1);
    assert (str2);

    int failed = 0;

    printf ("Test of my_strcat():\n");
    char *s1 = (char*) calloc (strlen(str1) + strlen(str2) + 1, sizeof(char));
    char *s2 = (char*) calloc (strlen(str1) + strlen(str2) + 1, sizeof(char));

    my_strcat (s1, str2);
    strcat (s2, str2);
    
    if (strcmp (s1, s2)) {
        printf ("Error in my_strcat().\n");

        printf ("String received with my_strcat(): ");
        puts (s1);
        printf ("String received with strcat(): ");
        puts (s2);
        printf ("\n\n");

        failed++;
    }
    else {
        printf ("Test passed.\n\n");
    }

    free (s1);
    free (s2);

    return failed;
}

//------------------------------------------------------------------

int test_strncat (const char *str1, const char *str2)
{
    assert (str1);
    assert (str2);

    int failed = 0; 

    printf ("Test of my_strncat():\n");
    char *s1 = (char*) calloc (strlen(str1) + strlen(str2) + 1, sizeof(char));
    char *s2 = (char*) calloc (strlen(str1) + strlen(str2) + 1, sizeof(char));
    int count = 8;

    my_strncat (s1, str2, count);
    strncat (s2, str2, count);
    
    if (strcmp (s1, s2)) {
        printf ("Error in my_strncat().\n");
 
        printf ("String received with my_strncat(): ");
        puts (s1);
        printf ("String received with strncat(): ");
        puts (s2);
        printf ("\n\n");

        failed++;
    }
    else {
        printf ("Test passed.\n\n");
    }

    free (s1);
    free (s2);

    return failed;
}

//------------------------------------------------------------------

int test_strdup (const char *str1, const char *str2)
{
    assert (str1);
    assert (str2);

    int failed = 0;

    printf ("Test of my_strdup():\n");
    char *p_s1 = my_strdup (str1);
    char *p_s2 = strdup (str1); 

    if (strcmp (p_s1, p_s2)) {
        printf ("Error in my_strdup().\n");

        printf ("String received with my_strdup(): ");
        puts (p_s1);
        printf ("String received with strdup(): ");
        puts (p_s2);
        printf ("\n\n");

        failed++;
    }
    else {
        printf ("Test passed.\n\n");
    }

    free(p_s1);
    free(p_s2);

    return failed;
}

//------------------------------------------------------------------

int test_strchr (const char *str2)
{
    assert (str2);

    int failed = 0;

    printf ("Test of my_strchr():\n");
    int ch1 = 'a';
    int ch2 = 'h';

    int ch1_comp = my_strchr (str2, ch1) != strchr (str2, ch1);
    int ch2_comp = my_strchr (str2, ch2) != strchr (str2, ch2);

    if (ch1_comp || ch2_comp) {
        printf ("Error in my_strchr() with symbol ");
        if (ch1_comp) {
            putchar (ch1);
        }
        else {
            putchar (ch2);
        } 
        printf ("\n");
        failed++;
    }
    else {
        printf ("Test passed.\n\n");
    }

    return failed;
}