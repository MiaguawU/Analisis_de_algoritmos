#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ERROR  false
#define MAX    100000


bool arr_rand(int *arr, int n);
bool gen_arr(int n, int **arr);

bool quick_sort(int n, int *arr, bool aleatorio);
bool subcon_min(int *arr, int n);

#endif