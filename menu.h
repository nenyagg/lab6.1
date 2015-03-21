/***************************:w********************************************************************/
/* Copyright (C)   163.com, nenyagg@gmail, 2014-2015                                             */
/*                                                                                               */
/*  FILE NAME           :menu.h						  			   								 */
/*  AUTHOR              :Nenyagg                                                            	 */
/*  MODULE NAME         :menu                                                                    */
/*  LANGUAGE            :c                                                                 	     */
/*  TARGET ENVIROMENT   :any                                                              	     */
/*  DATE OF RELEASE     :2014/12/25                                                              */
/*  DESCRIPTION         :menu                                                                    */
/*************************************************************************************************/
/*
  * revision log
  *
  *
  * create by vanny 2015/1/14
*/

/* add cmd to menu */
 int MenuConfig(int no, char * cmd, char * desc, int (*handler)());

 /* Menu Engine Execute*/
 int ExecuteMenu();