/*
** EPITECH PROJECT, 2018
** get next line
** File description:
** get next line
*/

#include "get_next_line.h"

char *my_strncat(char *dest, char const *src, int num)
{
    int count1 = 0;
    int count2 = 0;

    while (dest[count1] != '\0')
        count1++ ;
    while (count2 < num) {
        dest[count1] = src[count2];
        count2++;
        count1++;
    }
    dest[count1] = '\0';
    return (dest);
}

char *my_realloc(char *old_str, int add_length, char *add_str)
{
    char *new_str;
    int count = 0;
    int new_length = add_length;

    for (int i = 0; old_str[i] != '\0'; i++)
        new_length++;
    new_str = malloc(sizeof(char) * (new_length + 1));
    if (new_str == NULL)
        return (NULL);
    while (old_str[count] != '\0' && count != new_length) {
        new_str[count] = old_str[count];
        count++;
    }
    new_str[count] = '\0';
    free(old_str);
    new_str = my_strncat(new_str, add_str, add_length);
    return (new_str);
}

int adjust_save(char save[][READ_SIZE])
{
    int counter1 = 0;
    int read_chars = 0;

    while (save[0][counter1] != '\0' && save[0][counter1] != '\n') {
        counter1++;
    }
    counter1 += 1;
    while (save[0][counter1] != '\0') {
        save[0][read_chars] = save[0][counter1];
        save[0][counter1] = '\0';
        counter1++;
        read_chars++;
    }
    return (read_chars);
}

char *next_line_into_str(int fd, char save[][READ_SIZE], char *str)
{
    int end = 1;

    for (int count = 0; count != -1;) {
        count = 0;
        end = read(fd, save, READ_SIZE);
        if (end == -1)
            return (NULL);
        save[0][end] = '\0';
        while (save[0][count] != '\n' && save[0][count] != '\0')
            count++;
        str = my_realloc(str, count, save[0]);
        if (str == NULL || end == 0)
            return (NULL);
        if (count != READ_SIZE)
            count = -1;
    }
    return (str);
}

char *get_next_line(int fd)
{
    static int read_chars = 0;
    static char save[READ_SIZE];
    char *str = malloc(sizeof(char) * (read_chars + 1));

    if (str == NULL)
        return (NULL);
    for (int i = 0; i != read_chars; i++)
        str[i] = save[i];
    str[read_chars] = '\0';
    str = next_line_into_str(fd, &save, str);
    if (str == NULL)
        return (NULL);
    read_chars = adjust_save(&save);
    return (str);
}