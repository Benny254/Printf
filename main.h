#ifndef _PRINTF.H
#define _PRINTF.H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define used(x) void(x)
#define buf_size 1024

#define f_zero
#define f_space
#define f_minus
#define f_plus
#define f_hash

/* sizes */
#define s_short
#define s_long

/**
 * struct fmt - to struct op
 *
 * @fmt: format
 * @fn1: the function to be associated
 */
struct fmt
{
        char fmt;
        int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - the struct op
