/*************************************************************************************************/
/* Copyright (C)   163.com, nenyagg@gmail, 2014-2015                                             */
/*                                                                                               */
/*  FILE NAME           :test.c                              		                             */
/*  AUTHOR              :Nenyagg                                                                 */
/*  SUBSYSTEM NAME      :SimpleCalculator                                                        */
/*  MODULE NAME         :test                                                                    */
/*  LANGUAGE            :c                                                                       */
/*  TARGET ENVIROMENT   :any                                                                     */
/*  DATE OF RELEASE     :2014/12/20                                                              */
/*  DESCRIPTION         :This is simple calculator                                               */
/*************************************************************************************************/
/*
  * revision log
  *
  *
  * create by vanny 2014/12/20
*/
#include <stdio.h>
#include <stdlib.h>
#include "attion.h"
#include "menu.h"

int main(int argc, char *argv[])
{
   	MenuConfig(2, "version", "SimpleCalculator program v2.5", version);
   	MenuConfig(3, "quit", "Quit from program.", quit);
   	MenuConfig(4, "add", "Two numbers together", add);
   	MenuConfig(5, "sub", "Subtract two numbers", sub);
	MenuConfig(6, "mul", "Multiplying two numbers", mul);
	MenuConfig(7, "divi", "Divided by the number two", divi);
	MenuConfig(8, "mod", "Take the remainder of two numbers", mod);

   	ExecuteMenu();

    return 0;       
}
