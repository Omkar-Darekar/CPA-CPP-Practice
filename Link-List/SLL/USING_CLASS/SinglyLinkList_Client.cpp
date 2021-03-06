#include "SinglyLinkList.h"

int main(void) {

    list* pList = new list();

    pList->Remove_First();
    pList->Remove_Last();

    pList->Insert_Start(200);
    pList->Show_List();
    
    pList->Remove_First();

    pList->Insert_Start(300);
    pList->Show_List();

    pList->Remove_Last();
    pList->Show_List();

    for(int i = 0; i < 10; i++) {
        pList->Insert_End(i * 2);
    }

    pList->Show_List();

    for(int i = 0; i < 10; i++) {
        pList->Insert_Start(i);
    }

    pList->Show_List();

    pList->Insert_After(2, 299);
    pList->Show_List();

    pList->Remove_Before(9);
    pList->Show_List();

    pList->Remove_After(100);

    int k;
    printf("Lenght of list : %d\n\n", pList->Get_Length());
    
    if(pList->Pop_First(&k))
        printf("first Popped data : %d\n\n", k);

    if(pList->Pop_Last(&k))
        printf("Last Popped data : %d\n\n", k);

    printf("Lenght of list : %d\n\n", pList->Get_Length());
    
    if(pList->Get_Start(&k))
        printf("k : %d\n", k);
    
    if(pList->Get_Last(&k))
        printf("k : %d\n", k);

    pList->Show_List();

    pList->Insert_Before(2, 599);

    for(int i = 0; i < 10; i++) {
        pList->Insert_Start(i);
    }
    pList->Show_List();

    pList->Insert_Before(2, 599);
    pList->Insert_After(2, 999);
    pList->Insert_Before(9, 599);
    pList->Show_List();

    if(pList->Get_Start(&k))
        printf("k : %d\n", k);
    
    if(pList->Get_Last(&k))
        printf("k : %d\n", k);

    printf("Lenght of list : %d\n\n", pList->Get_Length());

    pList->Pop_First(&k);
    printf("first Popped data : %d\n\n", k);

    pList->Pop_Last(&k);
    printf("Last Popped data : %d\n\n", k);

    pList->Show_List();

    pList->Remove_After(1);
    pList->Show_List();

    puts("-----------------------");
    pList->Remove_Before(1);
    pList->Show_List();

    pList->Remove_Before(9);
    pList->Show_List();

    pList->Remove_First();
    pList->Remove_Last();
    pList->Show_List();

    delete (pList);
    return (0);
}