#ifndef __DOUBLY_CIRCULAR_C_H__
#define __DOUBLY_CIRCULAR_C_H__

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* Create_List(void);
int Insert_First(struct node* plist, int iNewData);
int Insert_Last(struct node* plist, int iNewData);

int Remove_First(struct node* plist);
int Remove_Last(struct node* plist);

int Insert_After(struct node* plist, int iPresentData, int iNewData);
int Insert_Before(struct node* plist, int iPresentData, int iNewData);

int Remove_After(struct node* plist, int iPresentData);
int Remove_Before(struct node* plist, int iPresentData);

int Get_First(struct node* plist, int* iRet);
int Get_Last(struct node* plist, int* iRet);

int Pop_First(struct node* plist, int* iRet);
int Pop_Last(struct node* plist, int* iRet);

int Destroy_List(struct node** plist);

int Get_Length(struct node* plist);

void Print_List(struct node* plist);

//Auxillary Function
static struct node* Get_Node(int iNewData);
static int Is_List_Empty(struct node* plist);
static int Generic_Insert(struct node* beg, struct node* mid, struct node* end);
static int Generic_Delete(struct node* beg, struct node* mid, struct node* end);
static struct node* Is_Data_Available(struct node* plist, int iSearchData);

#endif // __DOUBLY_CIRCULAR_C_H__
