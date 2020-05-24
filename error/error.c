/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** disp
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void error2(int ac, const char **av)
{
    if (atoi(av[1]) < 1 || atoi(av[1]) > 3) {
        printf("First argument should only be comprised between 1 and 3.\n");
        exit(84);
    }
}

void error(int ac, const char **av)
{
    if (av[1] == NULL) {
        printf("Try '-h' for more informations.\n");
        exit(84);
    } else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        display_help();
    if (ac != 9) {
        printf("Wrong number of arguments.\n");
        exit(84);
    }
    if (atoi(av[5]) == atoi(av[6]) && atoi(av[6]) == atoi(av[7])) {
        printf("Vector is null.\n");
        exit(84);
    }
    if (av[8][0] == '-') {
        printf("Wrong radius.\n");
        exit(84);
    }
    error2(ac, av);
}