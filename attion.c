/*************************************************************************************************/
/* Copyright (C)   163.com, nenyagg@gmail, 2014-2015                                             */
/*                                                                                               */
/*  FILE NAME           :attion.c                                                                */
/*  AUTHOR              :Nenyagg                                                                 */
/*  SUBSYSTEM NAME      :SimpleCalculator                                                        */
/*  MODULE NAME         :attion                                                                  */
/*  LANGUAGE            :c                                                                       */
/*  TARGET ENVIROMENT   :any                                                                     */
/*  DATE OF RELEASE     :2014/12/25                                                              */
/*  DESCRIPTION         :This is calculator attion                                               */
/*************************************************************************************************/
/*
  * revision log
  *
  *
  * create by vanny 2014/12/25
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "attion.h"
#include "linkTable.h"

#define FONTSIZE 10

int PrintMenuOS()
{
    int i, j;
    char data_M[FONTSIZE][FONTSIZE] =
    {
        "          ",
        "  *    *  ",
        " ***  *** ",
        " * *  * * ",
        " * *  * * ",
        " *  **  * ",
        " *      * ",
        " *      * ",
        " *      * ",
        "          "
    };
    char data_e[FONTSIZE][FONTSIZE] =
    {
        "          ",
        "          ",
        "    **    ",
        "   *  *   ",
        "  *    *  ",
        "  ******  ",
        "  *       ",
        "   *      ",
        "    ***   ",
        "          "
    };
    char data_n[FONTSIZE][FONTSIZE] =
    {
        "          ",
        "          ",
        "    **    ",
        "   *  *   ",
        "  *    *  ",
        "  *    *  ",
        "  *    *  ",
        "  *    *  ",
        "  *    *  ",
        "          "
    };
    char data_u[FONTSIZE][FONTSIZE] =
    {
        "          ",
        "          ",
        "  *    *  ",
        "  *    *  ",
        "  *    *  ",
        "  *    *  ",
        "  *    *  ",
        "   *  **  ",
        "    **  * ",
        "          "
    };
    char data_O[FONTSIZE][FONTSIZE] =
    {
        "          ",
        "   ****   ",
        "  *    *  ",
        " *      * ",
        " *      * ",
        " *      * ",
        " *      * ",
        "  *    *  ",
        "   ****   ",
        "          "
    };
    char data_S[FONTSIZE][FONTSIZE] =
    {
        "          ",
        "    ****  ",
        "   **     ",
        "  **      ",
        "   ***    ",
        "     **   ",
        "      **  ",
        "     **   ",
        "  ****    ",
        "          "
    };

    for(i=0; i<FONTSIZE; i++)
    {
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_M[i][j]);
        }
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_e[i][j]);
        }
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_n[i][j]);
        }
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_u[i][j]);
        }
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_O[i][j]);
        }
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_S[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int Quit(int argc, char *argv[])
{
    /* add XXX clean ops */
}

int Time(int argc, char *argv[])
{
    time_t tt;
    struct tm *t;
    tt = time(NULL);
    t = localtime(&tt);
    printf("time:%d:%d:%d:%d:%d:%d\n",t->tm_year+1900, t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    return 0;
}

int TimeAsm(int argc, char *argv[])
{
    time_t tt;
    struct tm *t;
    asm volatile(
        "mov $0,%%ebx\n\t"
        "mov $0xd,%%eax\n\t" 
        "int $0x80\n\t" 
        "mov %%eax,%0\n\t"  
        : "=m" (tt) 
    );
    t = localtime(&tt);
    printf("time:%d:%d:%d:%d:%d:%d\n",t->tm_year+1900, t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    return 0;
}

int version(int argc, char *argv[])
{
    printf("SimpleCalculator program v2.5\n");
    return SUCCESS;
}

int quit(int argc, char *argv[])
{
    printf("Good bye!\n");
    exit(0);
}

int add(int argc, char *argv[])
{
    int a; 
    int b;
    if(argv[1] != NULL && argv[2] != NULL)
    {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
    }
    else
    {
        printf("Please enter two integer. Example: 20 30\n");
        scanf("%d %d", &a, &b);
        getchar();
    }
    printf("%d + %d = %d\n", a, b, a + b);
    return SUCCESS;
}

int sub(int argc, char *argv[])
{
    int a; 
    int b;
    if(argv[1] != NULL && argv[2] != NULL)
    {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
    }
    else
    {
        printf("Please enter two integer. Example: 20 30\n");
        scanf("%d %d", &a, &b);
        getchar();
    }
    printf("%d - %d = %d\n", a, b, a - b);
    return SUCCESS;
}

int mul (int argc, char *argv[])
{
    int a; 
    int b;
    if(argv[1] != NULL && argv[2] != NULL)
    {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
    }
    else
    {
        printf("Please enter two integer. Example: 20 30\n");
        scanf("%d %d", &a, &b);
        getchar();
    }
    printf("%d * %d = %d\n", a, b, a * b);
    return SUCCESS;
}

int divi(int argc, char *argv[])
{
    int a; 
    int b;
    if(argv[1] != NULL && argv[2] != NULL)
    {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
    }
    else
    {
        printf("Please enter two integer. Example: 20 30\n");
        scanf("%d %d", &a, &b);
        getchar();
    }
    if(b == 0)
    {
        printf("Error!!!!\nDividend can not be 0\n");
        return FAILURE;
    }
    else
    {
        printf("%d / %d = %d\n", a, b, a / b);
        return SUCCESS;
    }
}

int mod(int argc, char *argv[])
{
    int a; 
    int b;
    if(argv[1] != NULL && argv[2] != NULL)
    {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
    }
    else
    {
        printf("Please enter two integer. Example: 20 30\n");
        scanf("%d %d", &a, &b);
        getchar();
    }
    printf("%d %% %d = %d\n", a, b, a % b);
    return SUCCESS;
}
