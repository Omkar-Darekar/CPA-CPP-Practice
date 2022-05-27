#include "DoublyCircular.h"

int main(void) {
    list* plist = new list();

    plist->Show_List();

    int data = -100;
    if(plist->Pop_First(&data)) {
        printf("Pop_First : Popped data : %d\n", data);
    } 
    else {
        puts("Pop_First : Popped failed\n\n");
    }

    if(plist->Pop_Last(&data)) {
        printf("Pop_Last : Popped data : %d\n", data);
    } 
    else {
        puts("Pop_Last : Popped failed\n\n");
    }

    plist->Insert_First(10);
    plist->Show_List();
    if(plist->Pop_First(&data)) {
        printf("Pop_First : Popped data : %d\n", data);
    } 
    else {
        puts("Pop_First : Popped failed\n\n");
    }
    plist->Show_List();
    plist->Insert_First(990);
    plist->Show_List();
    if(plist->Pop_Last(&data)) {
        printf("Pop_Last : Popped data : %d\n", data);
    } 
    else {
        puts("Pop_Last : Popped failed\n\n");
    }
    plist->Show_List();

    if(plist->Get_After(10, &data)) {
        printf("data : %d\n\n", data);
    }
    else {
        puts("\n**ERROR**\n");
    }

    if(plist->Get_Before(10, &data)) {
        printf("data : %d\n\n", data);
    }
    else {
        puts("\n**ERROR**\n");
    }

    plist->Insert_First(10);

    if(plist->Get_After(10, &data)) {
        printf("data : %d\n\n", data);
    }
    else {
        puts("\n**ERROR**\n");
    }

    if(plist->Get_Before(10, &data)) {
        printf("data : %d\n\n", data);
    }
    else {
        puts("\n**ERROR**\n");
    }

    plist->Insert_First(50);
    plist->Insert_Last(100);

    if(plist->Get_After(10, &data)) {
        printf("data : %d\n\n", data);
    }
    else {
        puts("\n**ERROR**\n");
    }

    if(plist->Get_Before(10, &data)) {
        printf("data : %d\n\n", data);
    }
    else {
        puts("\n**ERROR**\n");
    }

    plist->Show_List();
    plist->Insert_First(50);
    plist->Remove_Before(50);
    plist->Remove_After(50);
    plist->Show_List();

    puts("\n----------------\n");

    plist->Insert_First(51);
    plist->Show_List();
    puts("\n----------------\n");
    plist->Remove_Before(50);
    plist->Insert_First(53);
    plist->Show_List();
    plist->Remove_After(50);
    plist->Show_List();

    
    plist->Remove_First();
    plist->Remove_Last();
    plist->Insert_After(10, 20);
    plist->Insert_Before(10, 30);

    plist->Insert_First(10);

    plist->Remove_Last();
    plist->Show_List();
    puts("\n----------------\n");
    plist->Insert_First(50);
    plist->Insert_First(60);
    plist->Insert_First(70);
    plist->Insert_First(80);
    plist->Show_List();
    puts("\n----------------\n");
    plist->Remove_First();
    plist->Show_List();
    puts("\n----------------\n");
    plist->Insert_Last(20);
    plist->Show_List();

    puts("\n----------------\n");

    plist->Insert_After(10, 20);
    plist->Insert_Before(10, 30);
    plist->Show_List();

    delete (plist);
    puts("**Delete plist**\n\n");
    return (0);
}