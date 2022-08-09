#ifndef TEST_H 
#define TEST_H

void test_run(void);
void test_puts(char *str1);
void test_strcpy(char *str1, char *str2, int *failed_tests);
void test_strlen(char *str1, int *failed_tests);
void test_strncpy(char *str1, char *str2, int *failed_tests);
void test_strcat(char *str1, char *str2, int *failed_tests);
void test_strncat(char *str1, char *str2, int *failed_tests);
void test_strdup(char *str1, char *str2, int *failed_tests);
void test_strchr(char *str2, int *failed_tests);

#endif
