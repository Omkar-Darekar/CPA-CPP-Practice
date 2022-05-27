#include "DoublyCircular.h"

struct node* Create_List(void) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL) {
        puts("No virtual memory. Exiting...\n");
        exit (EXIT_FAILURE);
    }
    new_node->next = new_node;
    new_node->prev = new_node;
    new_node->data = -100;
    return (new_node); //Returning head node
}

int Insert_First(struct node* plist, int iNewData) {
    struct node* new_node = Get_Node(iNewData);
    if(new_node == NULL) {
        puts("Insert_First : ERROR\n");
        return (0);
    }
    return (Generic_Insert(plist, new_node, plist->next));
}

int Insert_Last(struct node* plist, int iNewData) {
    struct node* new_node = Get_Node(iNewData);
    if(new_node == NULL) {
        puts("Insert_Last : ERROR\n");
        return (0);
    }
    return (Generic_Insert(plist->prev, new_node, plist));
}

int Remove_First(struct node* plist) {
    if(Is_List_Empty(plist)) {
        puts("Remove_First : List is empty\n");
        return (0);
    }
    return (Generic_Delete(plist, plist->next, plist->next->next));
}

int Remove_Last(struct node* plist) {
    if(Is_List_Empty(plist)) {
        puts("Remove_Last : List is empty\n");
        return (0);
    }
    return (Generic_Delete(plist->prev->prev, plist->prev, plist));
}

int Insert_After(struct node* plist, int iPresentData, int iNewData) {
    struct node* CurrentNode = NULL;
    if((CurrentNode = Is_Data_Available(plist, iPresentData)) == NULL) {
        puts("Insert_After : No data found\n");
        return (0);
    }
    struct node* new_node = Get_Node(iNewData);
    if(new_node == NULL) {
        puts("Insert_After : ERROR\n");
        return (0);
    }
    return (Generic_Insert(CurrentNode, new_node, CurrentNode->next));
}

int Insert_Before(struct node* plist, int iPresentData, int iNewData) {
    struct node* CurrentNode = NULL;
    if((CurrentNode = Is_Data_Available(plist, iPresentData)) == NULL) {
        puts("Insert_Before : No data found\n");
        return (0);
    }
    struct node* new_node = Get_Node(iNewData);
    if(new_node == NULL) {
        puts("Insert_Before : ERROR\n");
        return (0);
    }
    return (Generic_Insert(CurrentNode->prev, new_node, CurrentNode));
}

int Remove_After(struct node* plist, int iPresentData) {
    struct node* CurrentNode = NULL;
    if((CurrentNode = Is_Data_Available(plist, iPresentData)) == NULL) {
        puts("Remove_After : No data found\n");
        return (0);
    }
    if(CurrentNode->next == plist) {
        puts("Remove_After : No next node present\n");
        return (0);
    }
    return (Generic_Delete(CurrentNode, CurrentNode->next, CurrentNode->next->next));
}

int Remove_Before(struct node* plist, int iPresentData) {
    struct node* CurrentNode = NULL;
    if((CurrentNode = Is_Data_Available(plist, iPresentData)) == NULL) {
        puts("Remove_Before : No data found\n");
        return (0);
    }
    if(CurrentNode->prev == plist) {
        puts("Remove_Before : No previous node present\n");
        return (0);
    }
    return (Generic_Delete(CurrentNode->prev->prev, CurrentNode->prev, CurrentNode));
}

int Get_First(struct node* plist, int* iRet) {
    if(Is_List_Empty(plist)) {
        puts("Get_First : List is empty\n");
        return (-100);
    }
    return (plist->next->data);
}

int Get_Last(struct node* plist, int* iRet) {
    if(Is_List_Empty(plist)) {
        puts("Get_Last : List is empty\n");
        return (-100);
    }
    return (plist->prev->data);
}

int Pop_First(struct node* plist, int* iRet) {
    if(Is_List_Empty(plist)) {
        puts("Pop_First : List is empty\n");
        return (0);
    }
    *iRet = plist->next->data;
    return (Generic_Delete(plist, plist->next, plist->next->next));
}

int Pop_Last(struct node* plist, int* iRet) {
    if(Is_List_Empty(plist)) {
        puts("Pop_Last : List is empty\n");
        return (0);
    }
    *iRet = plist->prev->data;
    return (Generic_Delete(plist->prev->prev, plist->prev, plist));
}

int Destroy_List(struct node** plist) {
    struct node* run = (*plist)->next, *run_next = NULL;
    while(run != (*plist)) {
        run_next = run->next;
        free(run);
        run = run_next;
    }
    free (*plist);
    plist = NULL;
    puts("List destroyed successfully\n");
    return (1);
}

int Get_Length(struct node* plist) {
    unsigned int cnt = 0;
    struct node* run = plist->next;
    while(run != plist) {
        cnt++;
        run = run->next;
    }
    return (cnt);
}

void Print_List(struct node* plist) {
    struct node* run = plist->next;
    printf("[ list ] : [");
    while(run != plist) {
        printf("\t%d", run->data);
        run = run->next;
    }
    puts("\t]\n");
}



//Auxillary Function
static struct node* Get_Node(int iNewData) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL) {
        puts("No virtual space.\n");
        return (NULL);
    }
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->data = iNewData;
    return (new_node);
}

static int Is_List_Empty(struct node* plist) {
    return ((plist->next == plist) && (plist->prev == plist));
}

static int Generic_Insert(struct node* beg, struct node* mid, struct node* end) {
    mid->next = end;
    mid->prev = beg;
    beg->next = mid;
    end->prev = mid;
    return (1);
}
static int Generic_Delete(struct node* beg, struct node* mid, struct node* end) {
    beg->next = end;
    end->prev = beg;
    mid->next = NULL;
    mid->prev = NULL;
    free (mid);
    mid = NULL;
    return (1);
}

static struct node* Is_Data_Available(struct node* plist, int iSearchData) {
    struct node* run = plist->next;
    while(run != plist) {
        if(run->data == iSearchData) {
            return (run);
        }
        run = run->next;
    }
    return (NULL);
}


