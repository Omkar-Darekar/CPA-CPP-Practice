#include "SinglyLinkList.h"


node::node(int _data) : data(_data) {
    //Parameterised Constructor
}

list::list() {
    pNode = new node(-100);
    pNode->next = NULL;
}

int list::Generic_Insert(node* p_beg, node* p_mid, node* p_end) {
    p_mid->next = p_end;
    p_beg->next = p_mid;

    return (1);
}

int list::Insert_Start(int data) {
    Generic_Insert(pNode, new node(data), pNode->next);
    return (1);
}

void list::Show_List() const {
    node* run = pNode;
    printf("List : [\t");
    for(run = run->next; run != NULL; run = run->next) {
        printf("%d\t", run->data);
    }
    puts("]");
}

int list::Insert_End(int data) {
    node* run = pNode;
    while(run->next != NULL) {
        run = run->next;
    }
    Generic_Insert(run, new node(data), run->next);
    return (1);
}

bool list::Insert_After(int iPresentData, int iNewData) {
    node* p_Current_Node = NULL;
    if(!IsDataAvailable(iPresentData, &p_Current_Node)) {
        printf("Data not found\n");
        return (false);
    }

    Generic_Insert(p_Current_Node, new node(iNewData), p_Current_Node->next);
    return (true);
}

bool list::Insert_Before(int iPresentData, int iNewData) {
    node* run = NULL;
    if(!IsDataAvailable(iPresentData, &run)) {
        printf("Data not found\n");
        return (false);
    }

    run = pNode;
    while(run->next->data != iPresentData) {
        run = run->next;
    }

    Generic_Insert(run, new node(iNewData), run->next);

    return (true);
}

bool list::IsDataAvailable(int data, node** p_Current_Node) {
    node* run = pNode->next;
    while(run != NULL) {
        if(run->data == data) {
            *p_Current_Node = run;
            return (true);
        }   
        run = run->next;
    }

    return (false);
}

bool list::IsListEmpty() const{
    return ((pNode->next == NULL) ? true : false);
    
}

bool list::Get_Start(int* _data) {
    if(IsListEmpty()) {
        printf("List is empty\n");
        return (false);
    }
    *_data = pNode->next->data;
    return (true);
}

bool list::Get_Last(int* data) {
    if(IsListEmpty()) {
        printf("List is empty\n");
        return (false);
    }

    node* run = pNode;
    while(run->next != NULL) {
        run = run->next;
    }

    *data = run->data;
    return (true);
}

int list::Get_Length() {
    if(IsListEmpty()) {
        printf("List is empty\n");
        return (-1);
    }

    node* run = pNode;
    int cnt = 0;
    while(run->next != NULL) {
        run = run->next;
        cnt++;
    }

    return (cnt);
}

bool list::Pop_First(int* data) {
    if(IsListEmpty()) {
        puts("List is empty\n");
        return (false);
    }

    *data = pNode->next->data;
    node* tmp = pNode->next;
    pNode->next = pNode->next->next;
    delete (tmp);
    tmp = NULL;

    return (true);
}

bool list::Pop_Last(int* data) {
    if(IsListEmpty()) {
        puts("List is empty\n");
        return (false);
    }

    node* run = pNode;
    while(run->next->next != NULL) {
        run = run->next;
    }

    *data = run->next->data;
    delete (run->next);
    run->next = NULL;

    return (true);
}

bool list::Remove_After(int data) {
    node* DataNode = NULL;
    if(!IsDataAvailable(data, &DataNode)) {
        printf("Input data not found\n");
        return (false);
    }

    if(DataNode->next == NULL) {
        puts("No next data present\n");
        return (false);
    }

    Generic_Delete(DataNode, DataNode->next, DataNode->next->next);
    return (true);
}

void list::Generic_Delete(node* beg, node* mid, node* last) {
    beg->next = last;
    delete (mid);
}

bool list::Remove_Before(int data) {
    if(IsListEmpty()) {
        puts("List is empty\n");
        return (false);
    }

    if(pNode->next->data == data) {
        puts("No before data present\n");
        return (false);
    }

    node* run = pNode->next;
    node* tmp = pNode;

    while(run->next->data != data) {
        run = run->next;
        tmp = tmp->next;
    }

    if(run->next->data == data) {
        Generic_Delete(tmp, run, run->next);
        return (true);
    }

    return (false);
}

list::~list() {
    node* run = pNode->next;
    node* run_next = NULL;
    while(run != NULL) {
        run_next = run->next;
        delete (run);
        run = run_next;
    }
    delete (pNode);
    pNode = NULL;

    puts("\n*Removed all the nodes*\n");
}

bool list::Remove_First() {
    if(IsListEmpty()) {
        puts("Remove_First : List is empty\n");
        return (false);
    }
    Generic_Delete(pNode, pNode->next, pNode->next->next);
    return (true);
}

bool list::Remove_Last() {
    if(IsListEmpty()) {
        puts("Remove_Last : List is empty\n");
        return (false);
    }
    node* run = pNode, *tmp = NULL;
    while(run->next->next != NULL) {
        run = run->next;
    }
    tmp = run->next;
    run->next = NULL;
    free (tmp);
    tmp = NULL;
    return (true);
}
