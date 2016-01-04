
#ifndef __COMMON__
#define __COMMON__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef bool B;
typedef int L;
typedef float F;
typedef double E;
typedef char C, *S;
typedef int Token;

#define R return
#define P printf

#define DOI(n,x)for(L i=0,i2=n;i<i2;i++){x;}
#define PN() printf("\n")


// struct

typedef struct T_token
{
    union{
        L v_int;
        F v_flt;
        E v_dbv;
        S v_chr;
        C v_op[6];
    };
    L type;
    L row, col; //debug info
    struct T_token *nxt;
}*TK, TK0;

#define AL(t, n) (t*)malloc(sizeof(t) * (n))
#define ALC(n) (S)malloc(n+1)

extern TK headk;

#endif