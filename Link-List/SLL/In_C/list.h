
#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;  
};

struct node* Create_List (void);
struct node* Get_Node(int);

int Insert_Start(struct node*, int);
int Insert_Last(struct node*, int);

int Insert_After(struct node*, int, int);
int Insert_Before(struct node*, int, int);

int Get_Start(struct node*);
int Get_End(struct node*);

int Pop_Start(struct node*);
int Pop_End(struct node*);

int Remove_Start(struct node*);
int Remove_End(struct node*);

int List_Length(struct node*);

void Destroy_List(struct node**);

void Show_List(struct node*);

//Auxilary function
static int IsListEmpty(struct node*);
static struct node* Search_Node(struct node*, int);
static int IsDataPresent(struct node*, int);
#endif //__LIST_H__

