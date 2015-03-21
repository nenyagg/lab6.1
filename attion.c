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
#include "attion.h"
#include "linkTable.h"

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
