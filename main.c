/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** disp
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

void print_cone(int ac, const char **av)
{
    printf("Cone with a %s degree angle\n", av[8]);
    printf("Line passing through the point (%s,%s,%s) and parallel to ", \
    av[2], av[3], av[4]);
    printf("the vector (%s,%s,%s)\n", av[5], av[6], av[7]);
}

para_t fill_para(para_t *para, const char **av)
{
    para->x = atoi(av[2]);
    para->y = atoi(av[3]);
    para->z = atoi(av[4]);
    para->px = atoi(av[5]);
    para->py = atoi(av[6]);
    para->pz = atoi(av[7]);
    para->r = atoi(av[8]);
}

int main(int ac, char const **av)
{
    para_t *para;

    error(ac, av);
    if (av[1][0] == '1')
        sphere(av);
    if (av[1][0] == '2')
        cylinder(av);
    if (av[1][0] == '3') {
        print_cone(ac, av);
        para = malloc(sizeof(para_t));
        fill_para(para, av);
        cone(para);
    }
    return (0);
}
