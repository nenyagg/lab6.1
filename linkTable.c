/***************************:w**********************************************************************/
/* Copyright (C)   163.com, nenyagg@gmail, 2014-2015                                             */
/*                                                                                               */
/*  FILE NAME           :linkTable.c                                                             */
/*  AUTHOR              :Nenyagg                                                                 */
/*  MODULE NAME         :linkTable                                                               */
/*  LANGUAGE            :c                                                                       */
/*  TARGET ENVIROMENT   :any                                                                     */
/*  DATE OF RELEASE     :2014/12/25                                                              */
/*  DESCRIPTION         :linkTable                                                               */
/*************************************************************************************************/
/*
  * revision log
  *
  *
  * create by vanny 2014/12/25
*/
#include <stdio.h>
#include <stdlib.h>
#include "linkTable.h"
/*
 * LInkTable Type
 */
typedef  struct LinkTable
{
    tLinkTableNode *    pHead;
    tLinkTableNode *    pTail;
    int                 sumOfNode;
    pthread_rwlock_t    rwlock;
    
}tLinkTable;

/*
* Create a LinkTable
*/
tLinkTable * CreateLinkTable()
{
    tLinkTable * hard = (tLinkTable *)malloc(sizeof(tLinkTable));
    if(NULL == hard)
    {
        printf("CreateLinkTable Error!!!\n");
        exit(0);
    }
    hard->pHead = NULL;
    hard->pTail = NULL;
    hard->sumOfNode = 0;
    pthread_rwlock_init(&(hard -> rwlock), NULL);
    return hard;
}

/*
 * Delete a LinkTable
 */
int DeleteLinkTable(tLinkTable * pLinkTable)
 {
    if(pLinkTable == NULL)
    {
        return FAILURE;
    }
    pthread_rwlock_wrlock(&(pLinkTable -> rwlock));
    while(pLinkTable->pHead != NULL)
    {
        tLinkTableNode * tHard = pLinkTable->pHead;
        pLinkTable->pHead = pLinkTable->pHead->pNext;
        pLinkTable->sumOfNode -= 1;
    }
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->sumOfNode = 0;

    pthread_rwlock_destroy(&(pLinkTable -> rwlock));
    free(pLinkTable);
    return SUCCESS;
 }

/*
 * Add a LinkTableNode to LinkTable
 */
int AddLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode)
{
    if(pNode == NULL || pLinkTable == NULL)
    {
        return FAILURE;
    }
    pNode->pNext = NULL;
    pthread_rwlock_wrlock(&(pLinkTable -> rwlock));
    if(pLinkTable->pHead == NULL)
    {
        pLinkTable->pHead = pNode;
    }
    if(pLinkTable->pTail == NULL)
    {
        pLinkTable->pTail = pNode;
    }
    else
    {
        pLinkTable->pTail->pNext = pNode;
        pLinkTable->pTail = pNode;
    }
    pLinkTable->sumOfNode += 1;
    pthread_rwlock_unlock(&(pLinkTable -> rwlock));
    return SUCCESS;
}

/*
 * Delete a LinkTableNode from LinkTable
 */
int DelLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode)
{
    if(pNode == NULL || pLinkTable == NULL)
    {
        return FAILURE;
    }
    pthread_rwlock_wrlock(&(pLinkTable -> rwlock));
    if(pLinkTable->pHead == pNode)
    {
        pLinkTable->pHead = pLinkTable->pHead->pNext;
        pLinkTable->sumOfNode -= 1;
        free(pNode);
        if (pLinkTable->sumOfNode == 0)
        {
            pLinkTable->pTail = NULL;
        }
        pthread_rwlock_unlock(&(pLinkTable -> rwlock));
        return SUCCESS;
    }

    tLinkTableNode * pTempNode = pLinkTable->pHead;
    while(pTempNode != NULL)
    {
        if(pTempNode->pNext == pNode)
        {
            pTempNode->pNext = pTempNode->pNext->pNext;
            pLinkTable->sumOfNode -= 1;
           if (pLinkTable->sumOfNode == 0)
            {
                pLinkTable->pTail = NULL;
            }
            pthread_rwlock_unlock(&(pLinkTable -> rwlock));
            return SUCCESS;
        }
        pTempNode = pTempNode->pNext;
    }
    pthread_rwlock_unlock(&(pLinkTable -> rwlock));
    return FAILURE;
}

/*
 * Search a LinkTableNode from LinkTable
 * int Conditon(tLinkTableNode * pNode, void * args);
 */
tLinkTableNode * SearchLinkTableNode(tLinkTable *pLinkTable, int Conditon(tLinkTableNode * pNode, void * args), void * args)
{
    if(pLinkTable == NULL || Conditon == NULL)
    {
        return NULL;
    }
    pthread_rwlock_rdlock(&(pLinkTable -> rwlock));
    tLinkTableNode * pNode = pLinkTable->pHead;
    while(pNode != NULL)
    {    
        if(Conditon(pNode, args) == SUCCESS)
        {
            return pNode;                   
        }
        pNode = pNode->pNext;
    }
    pthread_rwlock_unlock(&(pLinkTable -> rwlock));
    return NULL;
}


/*
 * get LinkTableHead
 */
tLinkTableNode * GetLinkTableHead(tLinkTable * pLinkTable)
{
    if(pLinkTable == NULL)
    {
        return NULL;
    }    
    return pLinkTable->pHead;
}

/*
 * get next LinkTableNode
 */
tLinkTableNode * GetNextLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode)
{
    if(pNode == NULL || pLinkTable == NULL)
    {
        return NULL;
    }
    pthread_rwlock_rdlock(&(pLinkTable -> rwlock));
    tLinkTableNode * pTempNode = pLinkTable->pHead;
    while(pTempNode != NULL)
    {
        if(pTempNode == pNode)
        {
            pthread_rwlock_unlock(&(pLinkTable -> rwlock));
            return pTempNode->pNext;
        }
        pTempNode = pTempNode->pNext;
    }
    pthread_rwlock_unlock(&(pLinkTable -> rwlock));
    return NULL;
}

