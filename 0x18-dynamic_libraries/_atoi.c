#include <stdio.h>
/**
 * _atoi - convert a string into an integer.
 * @s: the string to use.
 * Return: integer.
 */
int my_atoi(const char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;

    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i++] == '-') ? -1 : 1;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i++] - '0');
    }

    return sign * result;
}
