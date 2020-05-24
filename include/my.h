/*
** EPITECH PROJECT, 2019
** Project
** File description:
** functions
*/

#ifndef MY_H
#define MY_H
#define	PI 3.14159265359

#include <stddef.h>
#include <math.h>

typedef struct para {
    float x;
    float y;
    float z;
    float px;
    float py;
    float pz;
    float angle;
    float r;
}para_t;

typedef struct parac {
    float a;
    float b;
    float c;
    float xm;
    float ym;
    float zm;
    float xm1;
    float ym1;
    float zm1;
    float xm2;
    float ym2;
    float zm2;
    float lambda;
    float lambda1;
    float lambda2;
    float delta;
    float rrad;
}parac_t;

void cylinder(const char **av);
void cone(para_t *para);
void disp_1_intersec(para_t *para, float *delta);
void disp_2_intersec(para_t *para, float *delta);
void sphere(const char **av);
void display_help(void);
int my_getnbr(const char *str);
void disp_ans(para_t *para, char *fig);
void error(int ac, const char **av);

#endif
