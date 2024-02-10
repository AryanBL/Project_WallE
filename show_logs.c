#include "declarations.h"



void show_all_logs(log *all_logs[], int count){
    int i=1,select,pages,t,l,choice;
    pages=count/10;
    char c;

    getchar();
    printf("all users :\n\n");
    while (1) {
        t = i * 10;
        l=(i-1)*10;
        for (int j = l; j < t  && j < count; j++) {
            printf("%d ) House name : %s\n", j + 1, all_logs[j]->house_name);
            printf("   seller : %s\n", all_logs[j]->seller);
            printf("   seconder : %s\n\n", all_logs[j]->agent);
        }

        printf("page : [%d/%d]\n",i+1,pages+1);
        printf("1) select the page\n");
        printf("2) just exit\n");
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
                    system("cls");
                    return;
            }
        }

    }

}
