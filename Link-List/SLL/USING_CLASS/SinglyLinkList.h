#ifndef __SINGLY_LINK_LIST__H__
#define __SINGLY_LINK_LIST__H__

#include <stdio.h>
#include <stdlib.h>

class node {
    friend class list;
    private:
        int data;
        node* next;
        node (int _data);
};

class list {
    private:
        node* pNode = NULL;
        int Generic_Insert(node* p_beg, node* p_mid, node* p_end);
        bool IsDataAvailable(int data, node** p_Current_Node);
        bool IsListEmpty() const;
    public:
        list();
        int Insert_Start(int data);
        int Insert_End(int data);

        void Show_List() const;
        
        bool Insert_After(int iPresentData, int iNewData);
        bool Insert_Before(int iPresentData, int iNewData);

        bool Get_Start(int* _data);
        bool Get_Last(int* data);

        int Get_Length();

        bool Pop_First(int* data);
        bool Pop_Last(int* data);
};

#endif //__SINGLY_LINK_LIST__H__