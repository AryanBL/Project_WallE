#include "declarations.h"
#include "my_structs.h"
extern int count_reqs;
void show_completely_seller(house *ptr);

int show_user_ads(users *current){
    int i=1,select,pages,t,l;
    pages=current->next/10;
    char c;
    getchar();
    printf("all ads for %s :\n\n",current->username);
    while (1) {
        t = i * 10;
        l=(i-1)*10;
        for (int j = l; j < t  && j < current->next; j++) {
            printf("%d ) House name : %s\n", j + 1, current->ptr[j]->house_name);
            printf("   Price : %d\n\n", current->ptr[j]->price);
        }
        if (i==pages)
            printf("First page\n");
        if (i==(pages+1)){
            printf("The last page.\n");
            printf("Previous/Current page : [P/C]\n");
            scanf("%c", &c);
            if (c=='C') {
                printf("Press the number of house to show the ad completely or press 0 to return :\n");
                scanf("%d", &select);
                break;
            }
        }else {
            printf("Next/Previous/Current page : [N/P/C]\n");
            scanf("%c", &c);
        }
        if (c == 'N' && i != pages ) {
            i++;
        }
        if (c == 'P' && i != 1)
            i--;
        if (c == 'C') {
            printf("Press the number of house to show the ad completely or press 0 to return :\n");
            scanf("%d", &select);
            break;
        }
    }

    if (select)
        show_completely_seller(current->ptr[select-1]);
    return select;
}

void show_completely_seller(house *ptr){
   // system("cls");
    printf("The owner : %s\n",ptr->user_name);
    printf("House name : %s\n",ptr->house_name);
    printf("Area of the house : %.2lf\n",ptr->area);
    printf("district : %d\n",ptr->district);
    printf("Price : %d\n",ptr->price);
    printf("Number of rooms : %d\n",ptr->rooms);
    printf("%dth floor\n",ptr->floor);
    printf("Condition : %d\n",ptr->cond);
    system("pause");
    getchar();
}