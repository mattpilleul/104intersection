/*
** EPITECH PROJECT, 2019
** disp.c
** File description:
** disp
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void display_help(void)
{
    printf("USAGE\n   ./104intersection opt xp ");
    printf("yp zp xv yv zv p\n\nDESCRIPTION\n   ");
    printf("opt         surface option: 1 for a sphere, ");
    printf("2 for a cylinder, 3 for a cone\n   (xp, yp, zp) ");
    printf("   coordinates of a point by which the light");
    printf(" ray passes through\n   (xv, yv, zv) ");
    printf("   coordinates of a vector parallel to the light ");
    printf("ray\n   p               parameter: radius of the sphere,");
    printf(" radius of the cylinder, or\n\t\t ");
    printf("  angle formed by the cone and the Z-axis\n");
    exit(0);
}

void disp_ans(para_t *para, char *fig)
{
    printf("%s of radius %.0f\nLine passing through the point ", para->r, fig);
    printf("(%.0f, %.0f, %.0f) and parallel to the vector (%.0f, %.0f, %.0f)"\
    , para->x, para->y, para->z, para->px, para->py, para->pz);
}

void disp_1_intersec(para_t *para, float *delta)
{
    printf("\n1 intersection point:\n(%.3f, %.3f, %.3f)\n", para->x + \
    para->px * delta[0], para->y + para->py * delta[0], para->z + \
    para->pz * delta[0]);
    exit(0);
}

void disp_2_intersec(para_t *para, float *delta)
{
    printf("\n2 intersection points:\n(%.3f, %.3f, %.3f)\n", para->x + \
    para->px * delta[0], para->y + para->py * delta[0], para->z + \
    para->pz * delta[0]);
    printf("(%.3f, %.3f, %.3f)\n", para->x + \
    para->px * delta[1], para->y + para->py * delta[1], para->z + \
    para->pz * delta[1]);
    exit(0);
}