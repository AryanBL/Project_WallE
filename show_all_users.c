#include "declarations.h"



int show_all_users(users *all_users[],int count){
    int i=0,select,pages,t,l,choice;
    pages=count/10;
    char c;
    getchar();
    printf("all users :\n\n");
    while (1) {
        t = (i+1) * 10;
        l=i*10;
        for (int j = l; j < t  && j < count; j++) {
            printf("%d ) username : %s\n", j + 1, all_users[j]->username);
            printf("   user type : %d\n\n", all_users[j]->type);
        }
        printf("page : [%d/%d]\n",i+1,pages+1);
        printf("1) select the page\n");
        printf("2) take any action on it\n");
        printf("3) just exit\n");
        printf("[N/P] goto the next or prev page\n");
        scanf("%c",&c);
        if (c=='P' || c=='N'){
            system("cls");
            if (c=='P' && i>0)
                i--;
            else if (i!=pages)
                i++;
            getchar();
        } else {
            switch (c) {
                case '1':
                    printf("which page :\n");
                    scanf("%d", &choice);
                    i = choice - 1;
                    break;
                case '2':
                    printf("Choose the specific ad\n");
                    scanf("%d", &select);
                    return select;
                case '3':
                    system("cls");
                    return 0;
            }
        }

    }
}