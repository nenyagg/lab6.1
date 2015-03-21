/*************************************************************************************************/
/* Copyright (C)   163.com, nenyagg@gmail, 2014-2015                                             */
/*                                                                                               */
/*  FILE NAME           :linkTable.h                                                             */
/*  AUTHOR              :Nenyagg                                                                 */
/*  MODULE NAME         :linkTable.h                                                             */
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

#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_

#include <pthread.h>

#define SUCCESS 0
#define FAILURE (-1)
/*
 * LinkTable Node Type
 */
typedef struct LinkTableNode
{
    struct LinkTableNode * pNext;    
}tLinkTableNode;

/*
 * LInkTable Type
 */
typedef struct LinkTable tLinkTable;

/*
* Create a LinkTable
*/
tLinkTable * CreateLinkTable();

/*
 * Delete a LinkTable
 */
int DeleteLinkTable(tLinkTable * pLinkTable);

/*
 * Add a LinkTableNode to LinkTable
 */
int AddLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);

/*
 * Delete a LinkTableNode from LinkTable
 */
int DelLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);

/*
 * Search a LinkTableNode from LinkTable
 * int Conditon(tLinkTableNode * pNode, void * args);
 */
tLinkTableNode * SearchLinkTableNode(tLinkTable *pLinkTable, int Conditon(tLinkTableNode * pNode, void * args), void * args);

/*
 * get LinkTableHead
 */
tLinkTableNode * GetLinkTableHead(tLinkTable * pLinkTable);

/*
 * get next LinkTableNode
 */
tLinkTableNode * GetNextLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);

#endif /* _LINK_TABLE_H_ */
