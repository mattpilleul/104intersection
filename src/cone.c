/*
** EPITECH PROJECT, 2020
** Project
** File description:
** cone
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

parac_t fill_parac(parac_t *parac)
{
    parac->a = 0;
    parac->b = 0;
    parac->c = 0;
    parac->xm = 0;
    parac->ym = 0;
    parac->zm = 0;
    parac->xm1 = 0;
    parac->ym1 = 0;
    parac->zm1 = 0;
    parac->xm2 = 0;
    parac->ym2 = 0;
    parac->zm2 = 0;
    parac->lambda = 0;
    parac->lambda1 = 0;
    parac->lambda2 = 0;
    parac->delta = 0;
    parac->rrad = 0;
}

void op1(parac_t *parac, para_t *para)
{
    fill_parac(parac);
    parac->rrad = tan((para->r * 2 * M_PI) / 180);
    parac->a = (powf(para->px, 2) + powf(para->py, 2) - \
    (pow(para->pz, 2) / pow((parac->rrad), 2)));
    parac->b = ((2 * para->px * para->x) + (2 *para->py * para->y) - \
    ((2 * para->pz * para->z) / powf(parac->rrad, 2)));
    parac->c = (powf(para->x, 2) + powf(para->y, 2) - (pow(para->z, 2) \
    / pow(parac->rrad, 2)));
    parac->delta = pow(parac->b, 2) - 4*parac->a*parac->c;
}

void op2(parac_t *parac, para_t *para)
{
    printf("1 intersection point:\n");
    parac->lambda = -parac->b / 2 * parac->a;
    parac->xm = para->x + parac->lambda * para->px;
    parac->ym = para->y + parac->lambda * para->py;
    parac->zm = para->z + parac->lambda * para->pz;
    printf("(%.3f, %.3f, %.3f)\n", parac->xm, parac->ym, parac->zm);
}

void op3(parac_t *parac, para_t *para)
{
    printf("2 intersection points:\n");
    parac->lambda = (-parac->b - sqrt(parac->delta)) / (2 * parac->a);
    parac->lambda2 = (-parac->b + sqrt(parac->delta)) / (2 * parac->a);
    parac->xm1 = para->x + parac->lambda * para->px;
    parac->ym1 = para->y + parac->lambda * para->py;
    parac->zm1 = para->z + parac->lambda * para->pz;
    parac->xm2 = para->x + parac->lambda2 * para->px;
    parac->ym2 =para->y + parac->lambda2 * para->py;
    parac->zm2 =para->z + parac->lambda2 * para->pz;
    printf("(%.3f, %.3f, %.3f)\n", parac->xm2, parac->ym2, parac->zm2);
    printf("(%.3f, %.3f, %.3f)\n", parac->xm1, parac->ym1, parac->zm1);
}

void cone(para_t *para)
{
    parac_t *parac = malloc(sizeof(parac_t));

    op1(parac, para);
    if (parac->a == 0 && parac->b == 0 && parac->c == 0)
        printf("There is an infinite number of intersection points.\n");
    else {
        if (parac->delta < 0)
            printf("No intersection point.\n");
        if (parac->delta == 0)
            op2(parac, para);
        else if (parac->delta > 0)
            op3(parac, para);
    }
}
