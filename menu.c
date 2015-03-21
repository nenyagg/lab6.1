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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkList.h"
#include "attion.h"
#include "linkTable.h"

tLinkTable * head = NULL;

#define CMD_MAX_ARGC_NUM    32
#define CMD_MAX_LEN         128
#define DESC_LEN            1024
#define CMD_NUM             10

int help()
{
    printf("This is a simple calculator, you can through the command to complete some simple calculation.\n");
    printf("When you use the command, you can enter the two integer,and after the output, you can continue\n");
    ShowAllCmd(head);
    return SUCCESS;
}

int init(char * pcmd, int argc, char *argv[])
{
    if(pcmd == NULL)
    {
        return FAILURE;
    }
    /* conver cmd to argc/argv */
    pcmd = strtok(pcmd, " ");
    while(pcmd != NULL && argc < CMD_MAX_ARGC_NUM)
    {
        argv[argc] = pcmd;
        argc++;
        pcmd = strtok(NULL, " ");
    }
    if(argc == 1)
    {
        int len = strlen(argv[0]);
        *(argv[0] + len - 1) = '\0';
    }

    return SUCCESS;
}

int MenuConfig(int no, char * cmd, char * desc, int (*handler)(int argc, char *argv[]))
{
	tDataNode * pNode = NULL;
	if(head == NULL)
	{
		head = CreateLinkTable();
	    tDataNode * pNode = (tDataNode*)malloc(sizeof(tDataNode));
	    pNode->cmd = "help";
	    pNode->desc = "This is help cmd.";
	    pNode->handler = help;
	    AddLinkTableNode(head, (tLinkTableNode *)pNode);
	}
	pNode = (tDataNode*)malloc(sizeof(tDataNode));
	pNode->cmd = cmd;
	pNode->desc = desc;
	pNode->handler = handler;
	AddLinkTableNode(head, (tLinkTableNode *)pNode);

	return SUCCESS;
}

int ExecuteMenu()
{
	while(1)
	{
        int argc = 0;
        char *argv[CMD_MAX_ARGC_NUM];
	    char cmd[CMD_MAX_LEN];
        char *pcmd = NULL;
	    printf("Input a cmd > ");
		/* scanf("%s", cmd); */
        pcmd = fgets(cmd, CMD_MAX_LEN, stdin);

        init(pcmd, argc, argv);
	    tDataNode *pTempNode = FindCmd(head, cmd);
	    if(pTempNode == NULL)
	    {
	        printf("Error!!!\nWithout this command.Please enter \"help\" command to view or enter \"quit\" to exit\n");
	    }
	    else
	    {
	        pTempNode->handler(argc, argv);
	    }
        argv[1] = NULL;
        argv[2] = NULL;
	}

	return SUCCESS;
}
