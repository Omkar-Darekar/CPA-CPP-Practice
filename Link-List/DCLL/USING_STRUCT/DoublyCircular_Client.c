#include "DoublyCircular.h"
#define MAX 50000
int main(void) {
    struct node* plist = Create_List();

    Print_List(plist);
    printf("Length : %d\n", Get_Length(plist));
    int data = 0;
    if(Pop_First(plist, &data) != 0) {
        printf("Pop_First : %d\n", data);
    }
    else {
        printf("Pop_First : NO DATA\n");
    }

    if(Pop_Last(plist, &data) != 0) {
        printf("Pop_Last : %d\n", data);
    }
    else {
        printf("Pop_Last : NO DATA\n");
    }

    if(Get_First(plist, &data) >= 0) {
        printf("Get_First : %d\n", data);
    }
    else {
        printf("Get_First : NO DATA\n");
    }

    if(Get_Last(plist, &data) >= 0) {
        printf("Get_Last : %d\n", data);
    }
    else {
        printf("Get_Last : NO DATA\n");
    }

    Remove_After(plist, 10);
    Remove_Before(plist, 10);
    
    Remove_First(plist);
    Remove_Last(plist);

    Insert_After(plist, 10, 9);
    Insert_Before(plist, 10, 9);

    Insert_First(plist, 10);
    Print_List(plist);

    Remove_After(plist, 10);
    Remove_Before(plist, 10);

    Insert_After(plist, 10, 9);
    Insert_Before(plist, 10, 9);
    Print_List(plist);
    
    for (int i = 0; i < MAX; i++) {
        Insert_First(plist, i);
    }
    //Print_List(plist);
    puts("Insert_First complete\n");
    
    for (int i = 0; i < MAX; i++) {
        Insert_Last(plist, i*10);
    }
    //Print_List(plist);
    puts("Insert_Last complete\n");

    for (int i = 0; i < MAX; i++) {
        Insert_After(plist, i, i*11);
    }
    //Print_List(plist);
    puts("Insert_After complete\n");

    for (int i = 0; i < MAX; i++) {
        Insert_Before(plist, i, i*33);
    }
    //Print_List(plist);
    puts("Insert_Before complete\n");

    
    for (int i = 0; i < MAX*4; i++) {
        Remove_First(plist);
    }
    Print_List(plist);
    puts("Remove_First complete\n");

    Destroy_List(&plist);
    puts("Destroy_List complete\n");

    return (0);
}