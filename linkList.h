/*************************************************************************************************/
/* Copyright (C)   163.com, nenyagg@gmail, 2014-2015                                             */
/*                                                                                               */
/*  FILE NAME           :linklist.h                                                              */
/*  AUTHOR              :Nenyagg                                                                 */
/*  MODULE NAME         :linklist                                                                */
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

/* Data struct and its operations*/
#include "linkTable.h"

typedef struct DataNode
{
    struct  tDataNode* pNext;
    int     no;
    char*   cmd;
    char*   desc;
    int     (*handler)(int argc, char *argv[]);
 }tDataNode;

/* cmd in the linklist and return the datanode point */
tDataNode* FindCmd(tLinkTable * head, char * cmd);
/* Show all command in linklist*/
int ShowAllCmd(tLinkTable * head);

int SearchCondition(tLinkTableNode * pLinkTableNode, void * args);

