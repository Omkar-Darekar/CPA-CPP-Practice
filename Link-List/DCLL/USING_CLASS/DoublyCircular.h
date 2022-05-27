#ifndef __DOUBLY_CIRCULAR_H__
#define __DOUBLY_CIRCULAR_H__

#include <stdio.h>
#include <stdlib.h>

class node {
    friend class list;
    private:
        int data;
        node* next;
        node* prev;
        node(int iNewData);
};

class list {
    private:
        node* plist = NULL;
        bool Generic_Insert(node* beg, node* mid, node* last);
        node* Is_Data_Present(int iSearchData) const;
        bool Is_List_Empty() const;
        bool Generic_Delete(node* beg, node* mid, node* last);
    public:
        list();
        ~list();

        bool Insert_First(int iNewData);
        bool Insert_Last(int iNewData);

        bool Insert_Before(int iPresentData, int iNewData);
        bool Insert_After(int iPresentData, int iNewData);

        bool Remove_First();
        bool Remove_Last();

        bool Remove_Before(int iPresentData);
        bool Remove_After(int iPresentData);

        unsigned int Get_Lenght() const;
        bool Get_First(int* iRet) const;
        bool Get_Last(int* iRet) const;

        bool Get_After(int iPresentData, int* iRet) const;
        bool Get_Before(int iPresentData, int* iRet) const;

        void Show_List() const;

        bool Pop_First(int* iRet);
        bool Pop_Last(int* iRet);

};

#endif //__DOUBLY_CIRCULAR_H__