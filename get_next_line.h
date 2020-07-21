/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** headerfile
*/

#ifndef HEADER
#define HEADER

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
char *get_next_line(int fd);

#endif


#ifndef READ_SIZE
#define READ_SIZE (5)
#endif
