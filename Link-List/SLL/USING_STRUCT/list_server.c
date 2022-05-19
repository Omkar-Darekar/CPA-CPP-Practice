#include "list.h"

struct node* Create_List() {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL) {
        printf("No virtual space \n");
        exit(0);
    }

    new_node->data = -100;
    new_node->next = new_node;
    return (new_node);
}

struct node* Get_Node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL) {
        printf("No virtual space \n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;

    return (new_node);
}

int Insert_Start(struct node* plist, int data) {
    struct node* new_node = Get_Node(data);
    if(plist->next == plist) {
        plist->next = new_node;
    }
    else {
        struct node* tmp = plist->next;
        plist->next = new_node;
        new_node->next = tmp;
        tmp = NULL;
    }

    new_node = NULL;

    return (1);
}

void Show_List(struct node* plist) {
    if(!IsListEmpty(plist)) {
        printf("[");
        for(struct node* prun = plist->next; prun != NULL; prun = prun->next) {
            printf("\t%d", prun->data);
        }

        puts("\t]\n");
    }
    else    printf("[\t]\n");

    plist = NULL;
}

int Insert_Last(struct node* plist, int data) {
    struct node* new_node = Get_Node(data);
    if(plist->next == plist) {
        plist->next = new_node;
    }
    else {
        while(plist->next != NULL) {
            plist = plist->next;
        }
        plist->next = new_node;
    }

    new_node = NULL;

    return (1);
}

static int IsListEmpty(struct node* plist) {
    return (plist->next == plist);
}

int Insert_After(struct node* plist, int iExistingData, int iNewData) {
    struct node* new_node = Get_Node(iNewData);
    if(IsListEmpty(plist)) {
        printf("List is empty. Adding data initially\n");
        plist->next = new_node;
    }
    else {
        struct node* tmp = Search_Node(plist, iExistingData);
        if(tmp == NULL) {
            free (new_node);
            new_node = NULL;
            return (0);
        }
        else {
            new_node->next = tmp->next;
            tmp->next = new_node;
        }
        tmp = NULL;
    }

    new_node = NULL;

    return (1); 
}

static struct node* Search_Node(struct node* plist, int iData) {
    if(IsListEmpty(plist)){
        return (NULL);
    }

    while(plist != NULL) {
        plist = plist->next;
        if(plist->data == iData) {
            return (plist);
        }
    }
    
    return (NULL);
}

int Insert_Before(struct node* plist, int iExistingData, int iData) {
    if(IsListEmpty(plist)) {
        printf("List is empty. Inserting at start\n");
        struct node* new_node = Get_Node(iData);
        plist->next = new_node;

        new_node = NULL;
        plist = NULL;
        return (1);
    }
    else {
        if(!IsDataPresent(plist, iExistingData))
            return (0);
        
        while(plist != NULL) { 
            if(plist->next->data == iExistingData) {
                struct node* new_node = Get_Node(iData);
                new_node->next = plist->next;
                plist->next = new_node;
                new_node = NULL;
                plist = NULL;
                return (1);
            }
            plist = plist->next;   
        }
    }
    plist = NULL;
    return (0);
}

static int IsDataPresent(struct node* plist, int iExistingData) {
    if(IsListEmpty(plist)) {
        plist = NULL;
        return (-100);
    }
    else {
        while(plist != NULL) {
            plist = plist->next;
            if(plist->data == iExistingData) {
                plist = NULL;
                return(1);
            }
        }
    }

    plist = NULL;
    return (0);
}

int Get_Start(struct node* plist) {
    if(IsListEmpty(plist)) {
        printf("List is empty\n");
        return (-100);
    }
    
    return (plist->next->data);
}

int Get_End(struct node* plist) {
    if(IsListEmpty(plist)) {
        printf("List is empty\n");
        return (-100);
    }
    
    while(plist->next != NULL) {
        plist = plist->next;
    }

    return (plist->data);
}

int Pop_Start(struct node* plist) {
    if(IsListEmpty(plist)) {
        printf("List is empty\n");
        return (-100);
    }
    int iPoppedData = -100;

    if(plist->next->next == NULL) {
        iPoppedData = plist->next->data;
        free (plist->next);
        plist->next = plist;
        return (iPoppedData);
    }

    struct node* tmp = plist->next->next;
    iPoppedData = plist->next->data;
    free (plist->next);
    plist->next = tmp;
    tmp = NULL;
    return (iPoppedData);
}

int Pop_End(struct node* plist) {
    if(IsListEmpty(plist)) {
        printf("List is empty\n");
        return (-100);
    }

    int iPoppedData = -100;
    
    if(plist->next->next == NULL) {
        iPoppedData = plist->next->data;
        free (plist->next);
        plist->next = plist;
        return (iPoppedData);
    }

    struct node* tmp = NULL;

    while(plist->next != NULL) {
        tmp = plist;
        plist = plist->next;
    }

    iPoppedData = plist->data;
    free (plist);
    tmp->next = NULL;

    tmp = NULL;

    return (iPoppedData);
}

int Remove_Start(struct node* plist) {
    if(IsListEmpty(plist)) {
        printf("List is Empty\n");
        return (-100);
    }
    
    if(plist->next->next == NULL) {
        free (plist->next);
        plist->next = plist;
        return (1);
    }

    struct node* tmp = plist->next->next;
    free (plist->next);
    plist->next = tmp;
    tmp = NULL;

    return (1);
}

int Remove_End(struct node* plist) {
    if(IsListEmpty(plist)) {
        printf("List is Empty \n");
        return (-100);
    }

    if(plist->next->next == NULL) {
        free (plist->next);
        plist->next = plist;
        return (1);
    }

    struct node* tmp = NULL;
    while(plist->next != NULL) {
        tmp = plist;
        plist = plist->next;
    }
    free (plist);
    tmp->next = NULL;

    return (1);

}

int List_Length(struct node* plist) {
    if(IsListEmpty(plist)) {
        return (0);
    }

    int iCnt = 0;
    while(plist != NULL) {
        plist = plist->next;
        iCnt++;
    }
    return (iCnt);
}

void Destroy_List(struct node** plist) {
    struct node* list = *plist;
    if(list->next == list) {
        free(list);
        *plist = NULL;
    }
    else {
        struct node* tmp = NULL;

        while(list != NULL) {
            tmp = list;
            list = list->next;
            free (tmp);
            tmp = NULL;
        }
        *plist = NULL;
    }
}

