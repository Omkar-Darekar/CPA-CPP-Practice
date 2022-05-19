#include "list.h"

int main() {
    struct node* plist = Create_List();

    printf("%d\n",Get_Start(plist));
    printf("%d\n",Get_End(plist));
    printf("%d\n",Pop_Start(plist));
    printf("%d\n",Pop_End(plist));

    printf("Remove Start : %d\n",Remove_Start(plist));
    printf("Remove End : %d\n",Remove_End(plist));

    printf("List Length : %d\n",List_Length(plist));

    for(int i = 0; i < 5; i++) {
        Insert_Start(plist, i);
    }
    
    Destroy_List(&plist);
    if(plist == NULL) {
        printf("List destroyed successfully \n");
    }

    plist = Create_List();


    for(int i = 0; i < 5; i++) {
        Insert_Start(plist, i);
    }

    Show_List(plist);

    for(int _i = 0; _i < 5; _i++) {
        Insert_Last(plist, _i);
    }

    Show_List(plist);

    Insert_After(plist, 0, 0);
    for(int i = 0; i < 5; i++) {
        Insert_After(plist, i, (i + 1));
    }

    Show_List(plist);

    Insert_Before(plist, 0, 0);
    for(int i = 0; i < 5; i++) {
        Insert_Before(plist, i, (i + 1));
    }

    Show_List(plist);

    printf("\nGet Start Data : %d\n",Get_Start(plist));
    Show_List(plist);

    printf("\nGet End Data : %d\n",Get_End(plist));
    Show_List(plist);
    
    for(int i = 0; i < 10; i++){
        printf("\nPopped Start Data : %d\n",Pop_Start(plist));
        Show_List(plist);
    }

    printf("\n\nGet Start Data : %d\n",Get_Start(plist));
    Show_List(plist);

    printf("\n\nGet End Data : %d\n",Get_End(plist));
    Show_List(plist);
    
    for(int i = 0; i < 5; i++) {
        Insert_Start(plist, (i * 22));
    }

    printf("\n\nGet Start Data : %d\n",Get_Start(plist));
    Show_List(plist);

    printf("\n\nGet End Data : %d\n",Get_End(plist));
    Show_List(plist);

    for(int i = 0; i < 10; i++){
        printf("\nPopped End Data : %d\n",Pop_End(plist));
        Show_List(plist);
    }

    for(int i = 0; i < 5; i++) {
        Insert_Start(plist, (i * 22));
    }

    for(int i = 0; i < 7; i++) {
        printf("Remove Start : %d\n",Remove_Start(plist));
        Show_List(plist);
    }

    for(int i = 0; i < 5; i++) {
        Insert_Start(plist, (i * 22));
    }

    for(int i = 0; i < 7; i++) {
        printf("Remove End : %d\n",Remove_End(plist));
        Show_List(plist);
    }

    Destroy_List(&plist);
    if(plist == NULL) {
        printf("List destroyed successfully \n");
    }

    return (0);
}