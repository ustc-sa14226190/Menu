
/**************************************************************************************************/
/* Copyright (C) SSE@USTC,2014-2015                                                               */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AURTHOR     :  LiYunpeng                                                            */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATA OF FIRST RELEASE :  2014/09/11                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by LiYunpeng, 2014/09/11
 *
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define CMD_NUM 10
#define CMD_LEN 10
#define DESC_LEN 100

typedef struct DataNode
{
    char   cmd[CMD_LEN];
    char   desc[DESC_LEN];
    struct DataNode * next;
} tDataNode;

/* initiate the command array */
void init(tDataNode **head);
/* display the command array */
void display(tDataNode *head);
/* search command */
void search(tDataNode *head);

main()
{
    tDataNode * head = NULL;
    init(&head);
    display(head);
    search(head);
	free(head);
}

void init(tDataNode **head)
{
    int i;
    char cmdName[CMD_NUM][CMD_LEN]={"1","2","3","4","5","6","7","8","help","version"};
    char cmdSequ[CMD_NUM][CMD_LEN]={"1st","2nd","3rd","4th","5th","6th","7th","8th","help","version"};    
    tDataNode * p;
    for (i=CMD_NUM-1; i>=0; --i)
    {
        p = (tDataNode*)malloc(sizeof(tDataNode));
        snprintf(p->cmd, CMD_LEN,"%s", cmdName[i]);
        snprintf(p->desc, DESC_LEN, "This is the %s command!",cmdSequ[i]);
        p->next = *head;
        *head = p;
    }
}

void display(tDataNode *head)
{
    tDataNode * p = head;
	while (p != NULL)
    {
        printf("%s\t-  %s\n",p->cmd,p->desc);
        p = p->next;    
    }    
}

void search(tDataNode * head)
{
    char cmdName [CMD_LEN];
    printf("To stop searching enter exit\n");    
    printf("Enter the command :");
    scanf("%s",cmdName);
    while(strcmp(cmdName,"exit"))
    {
        tDataNode *p = head;
        while (p != NULL)
        {
            if(!strcmp(cmdName,p->cmd))
            {
                printf("%s\n",p->desc);
				break;
            }
            p = p->next;
        }   
        if (p == NULL)
        {
            printf("There is no this command!\n");
        }
		printf("Enter the command :");
		scanf("%s",cmdName);
    }
}
