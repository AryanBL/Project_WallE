#include "declarations.h"
#include "my_structs.h"

extern int count_reqs;


void show_completely(house *ptr){
    // system("cls");
    printf("The owner : %s\n",ptr->user_name);
    printf("House name : %s\n",ptr->house_name);
    printf("Area of the house : %.2lf\n",ptr->area);
    printf("district : %d\n",ptr->district);
    printf("Price : %d\n",ptr->price);
    printf("Number of rooms : %d\n",ptr->rooms);
    printf("%dth floor\n",ptr->floor);
    system("pause");
    getchar();
}



int show_ads_general(house *ptr[],enum types type,int flag){
    int i=0,pages,t,l,select,choice,fake_page,fake_count=0;
    house *temp[1000];
    fake_page=0;
    for (int j = 0; j < count_reqs && ptr[j]!=NULL; j++) {
        if (flag==2 ) {
            if (ptr[j]->cond == 0)
                temp[fake_page++] = ptr[j];
        }
        else {
            if (ptr[j]->cond != 1 && (type != admin && type != agent) && !flag)
                continue;
            temp[fake_page++] = ptr[j];
        }
    }
    pages=fake_page/10;
    char c;
    getchar();
    while (1) {
        t = (i+1) * 10;
        l=(i)*10;
        for (int j = l; j < t && j < fake_page; j++) {
            printf("%d ) House name : %s\n", j+1, temp[j]->house_name);
            printf("   Price : %d\n\n", temp[j]->price);
        }
        printf("page : [%d/%d]\n",i+1,pages+1);
        printf("1) select the page\n");
        printf("2) show the ad completely\n");
        printf("3) take any action on it\n");
        printf("4) just exit\n");
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
                    printf("Which one ?\n");
                    scanf("%d", &select);
                    if (select && type != general && type != seller && !flag)
                        show_completely_seller(temp[select - 1]);
                    else
                        show_completely(temp[select - 1]);
                    system("cls");
                    break;
                case '3':
                    printf("Choose the specific ad\n");
                    scanf("%d", &select);
                    return select;
                case '4':
                    system("cls");
                    return 0;
            }
        }

    }

}
