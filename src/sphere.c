/*
** EPITECH PROJECT, 2019
** sphere.c
** File description:
** disp
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/my.h"

void init_para_sphere(const char **av, para_t *para)
{
    para->x = my_getnbr(av[2]);
    para->y = my_getnbr(av[3]);
    para->z = my_getnbr(av[4]);
    para->px = my_getnbr(av[5]);
    para->py = my_getnbr(av[6]);
    para->pz = my_getnbr(av[7]);
    para->r = my_getnbr(av[8]);
}

void calc_delta_sph(para_t *para, float *abc, float *delta)
{
    float d = pow(abc[1], 2) - 4 * abc[0] * abc[2];
    char *fig = "Sphere";

    disp_ans(para, fig);
    if (d == 0) {
        delta[0] = - abc[1] / (2 * abc[0]);
        disp_1_intersec(para, delta);
    } else if (d > 0) {
        delta[0] = (- abc[1] + sqrt(d)) / (2 * abc[0]);
        delta[1] = (- abc[1] - sqrt(d)) / (2 * abc[0]);
        disp_2_intersec(para, delta);
    } else {
        printf("\nNo intersection point.\n");
        exit(0);
    }
}

void sphere(const char **av)
{
    float t;
    float *abc = malloc(sizeof(float) * 4);
    float *delta = malloc(sizeof(float) * 3);
    para_t *para = malloc(sizeof(para_t));

    init_para_sphere(av, para);
    abc[0] = pow(para->px, 2) + pow(para->py, 2) + pow(para->pz, 2);
    abc[1] = 2 * (para->px * para->x + para->py * para->y + para->pz * para->z);
    abc[2] = pow(para->x, 2) + pow(para->y, 2) + pow(para->z, 2) - \
    pow(para->r, 2);
    calc_delta_sph(para, abc, delta);
}