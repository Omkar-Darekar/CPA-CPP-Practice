#include "DoublyCircular.h"

node::node(int iNewData) :
    next(NULL),
    prev(NULL),    
    data(iNewData)
{

}

list::list() {
    plist = new node(-100);
    if(plist == NULL) {
        puts("No virtual space. EXITING..\n");
        exit (0);
    }
    plist->next = plist;
    plist->prev = plist;
}

bool list::Generic_Insert(node* beg, node* mid, node* last) {
    mid->next = last;
    mid->prev = beg;
    beg->next = mid;
    last->prev = mid;
    //printf("\n%d inserted\n", mid->data);
    return (true);
}

bool list::Insert_First(int iNewData) {
    return (Generic_Insert(plist, new node(iNewData), plist->next));
}

bool list::Insert_Last(int iNewData) {
    return (Generic_Insert(plist->prev, new node(iNewData), plist));
}

void list::Show_List() const {
    node* prun = plist->next;
    printf("[");
    while(prun != plist) {
        printf ("\t%d", prun->data);
        prun = prun->next;
    }
    puts("\t]");
}

node* list::Is_Data_Present(int iSearchData) const {
    node* run = plist->next;
    while(run != plist) {
        if(run->data == iSearchData) {
            return (run);
        }
        run = run->next;
    }
    return (NULL);
}

bool list::Insert_Before(int iPresentData, int iNewData) {
    node* p_PresentNode = NULL;
    if((p_PresentNode = Is_Data_Present(iPresentData)) == NULL) {
        puts("Insert_Before : Entered data is not present in the list.\n");
        return (false);
    }
    return (Generic_Insert(p_PresentNode->prev, new node(iNewData), p_PresentNode));
}

bool list::Insert_After(int iPresentData, int iNewData) {
    node* p_PresentNode = NULL;
    if((p_PresentNode = Is_Data_Present(iPresentData)) == NULL) {
        puts("Insert_After : Entered data is not present in the list.\n");
        return (false);
    }
    return (Generic_Insert(p_PresentNode, new node(iNewData), p_PresentNode->next));
}

bool list::Is_List_Empty() const {
    return (plist->next == plist ? true : false);
}

bool list::Generic_Delete(node* beg, node* mid, node* last) {
    beg->next = last;
    last->prev = beg;

    mid->next = NULL;
    mid->prev = NULL;
    delete (mid);
    return (true);
}

bool list::Remove_First() {
    if(Is_List_Empty()) {
        puts("Remove_First : List is empty. \n");
        return (false);
    }
    return (Generic_Delete(plist, plist->next, plist->next->next));
}

bool list::Remove_Last() {
    if(Is_List_Empty()) {
        puts("Remove_last : List is empty. \n");
        return (false);
    }
    return (Generic_Delete(plist->prev->prev, plist->prev, plist));
}

bool list::Remove_Before(int iPresentData) {
    node* p_PresentNode = NULL;
    if((p_PresentNode = Is_Data_Present(iPresentData)) == NULL) {
        puts("Remove_Before : Entered data is not present in the list\n");
        return (false);
    }
    if(p_PresentNode->prev == plist) {
        puts("Remove_Before : No element to remove\n");
        return (false);
    }

    return (Generic_Delete(p_PresentNode->prev->prev, p_PresentNode->prev, p_PresentNode));
}

bool list::Remove_After(int iPresentData) {
    node* p_PresentNode = NULL;
    if((p_PresentNode = Is_Data_Present(iPresentData)) == NULL) {
        puts("Remove_After : Entered data is not present in the list\n");
        return (false);
    }
    if(p_PresentNode->next == plist) {
        puts("Remove_After : No element to remove\n");
        return (false);
    }
    return (Generic_Delete(p_PresentNode, p_PresentNode->next, p_PresentNode->next->next));
}

unsigned int list::Get_Lenght() const {
    node* run = plist->next;
    unsigned int cnt = 0;
    while(run != plist) {
        cnt++;
        run = run->next;
    }
    return (cnt);
}

bool list::Get_First(int* iRet) const {
    if(plist->next == plist) {
        puts("Get_First : List is empty\n");
        return (false);
    }
    *iRet = plist->next->data;
    return (true);
}

bool list::Get_Last(int* iRet) const {
    if(plist->prev == plist) {
        puts("Get_Last : List is empty\n");
        return (false);
    }
    *iRet = plist->prev->data;
    return (true);
}


