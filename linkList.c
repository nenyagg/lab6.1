/*************************************************************************************************/
/* Copyright (C)   163.com, nenyagg@gmail, 2014-2015                                             */
/*                                                                                               */
/*  FILE NAME           :linklist.c                                                              */
/*  AUTHOR              :Nenyagg                                                                 */
/*  MODULE NAME         :Operation list                                                          */
/*  LANGUAGE            :c                                                                       */
/*  TARGET ENVIROMENT   :any                                                                     */
/*  DATE OF RELEASE     :2014/12/20                                                              */
/*  DESCRIPTION         :This is simple calculator                                               */
/*************************************************************************************************/
/*
  * revision log
  *:
  *
  * create by vanny 2014/12/20
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkList.h"
#include "linkTable.h"

int SearchCondition(tLinkTableNode * pLinkTableNode, void * args)
{
    char * cmd = (char *)args;
    tDataNode * pNode = (tDataNode *)pLinkTableNode;
    if(strcmp(pNode->cmd, cmd) == 0)
    {
        return  SUCCESS;  
    }
    return FAILURE;        
}

tDataNode * FindCmd(tLinkTable * head, char * cmd)
{
   return  (tDataNode*)SearchLinkTableNode(head,SearchCondition, (void *)cmd);
}

int ShowAllCmd(tLinkTable * head)
{
    if(head == NULL)
    {
        return FAILURE;
    }

    tDataNode * pNode = (tDataNode *) GetLinkTableHead(head);
    printf("Menu List:\n");
    while(pNode != NULL)
    {
        printf("%-10s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode *)GetNextLinkTableNode(head, (tLinkTableNode *)pNode);
    }

    return SUCCESS;
}
