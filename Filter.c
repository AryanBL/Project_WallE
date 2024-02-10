#include "my_structs.h"
#include "declarations2.h"
extern int count_reqs;
int show_filter(house *ptr[],int select,void *value,int type);
int filter_price(house *ptr[],int low_price,int high_price,int type);
void show_completely_seller(house *ptr);

int selector(){
    int select;
    printf("1) Filter district.\n");
    printf("2) Filter area.\n");
    printf("3) Filter price.\n");
    printf("4) Filter rooms.\n");
    printf("5) Filter floor.\n");
    printf("select your choice :\n");
    scanf("%d",&select);
    return select;
}






void filter(house *all_ads[],users *current){
    int select;
    int district,low_price,high_price,rooms,floor;
    double area;
    select=selector();
    switch (select) {
        case 1:

            printf("Enter district:\n");

            scanf("%d", &district);
            show_filter(all_ads,select,(void *)(&district),current->type);

            break;
        case 2:

            printf("Enter area:\n");

            scanf("%lf", &area);
            show_filter(all_ads,select,(void *)(&area),current->type);

            break;
        case 3:

            printf("Enter low price:\n");
            scanf("%d", &low_price);
            printf("Enter high price:\n");
            scanf("%d",&high_price);
            filter_price(all_ads,low_price,high_price,current->type);
            break;
        case 4:

            printf("Enter number of rooms:\n");

            scanf("%d", &rooms);
            show_filter(all_ads,select,(void *)(&rooms),current->type);

            break;
        case 5:

            printf("Enter floor:\n");

            scanf("%d", &floor);
            show_filter(all_ads,select,(void *)(&floor),current->type);

            break;
        default:
            printf("Invalid selection.\n");
            break;
    }
}

int between_price(house *ptr[],int low_price,int high_price,house *temp[]){
    int i,k=0;
    for (i=0;i<count_reqs;i++){
        if (ptr[i]->price>=low_price && ptr[i]->price<=high_price)
            temp[k++]=ptr[i];
    }
    return k;
}


int filter_price(house *ptr[],int low_price,int high_price,int type) {
    int i = 0, select, pages, t, l, k = 0, indexes[1000], choice;

    house *temp[1000];
    int res = between_price(ptr, low_price, high_price, temp);
    pages = res / 10;
    char c;
    getchar();
    printf("All ads :\n\n");
//    getchar();
    while (1) {
        t = (i + 1) * 10;
        l = i * 10;

        for (int j = l; j < t && j < res && temp[j]!=NULL; j++) {

            printf("%d ) House name : %s\n", j + 1, temp[j]->house_name);
            printf("   Price : %d\n\n", temp[j]->price);
        }
        printf("page : [%d/%d]\n", i + 1, pages + 1);
        printf("1) select the page\n");
        printf("2) show the ad completely\n");
        printf("3) take any action on it\n");
        printf("4) just exit\n");
        printf("[N/P] goto the next or prev page\n");
        scanf("%c", &c);
        if (c == 'P' || c == 'N') {
            system("cls");
            if (c == 'P' && i > 0)
                i--;
            else if (i != pages)
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
                    if (select && type != general && type != seller)
                        show_completely_seller(temp[select - 1]);
                    else
                        show_completely(ptr[select - 1]);
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
int show_filter(house *ptr[], int select, void *value, int type) {
    house *temp;
    int pages = count_reqs / 10, t, i = 1, l, val, indexes[1000], k = 0, choice, select2;
    double val2;
    char c;
    printf("All adds :\n\n");
    getchar();
    while (1) {
        t = (i + 1) * 10;
        l = i * 10;
        for (int j = l; j < t && j < count_reqs; j++) {
            switch (select) {
                case 1:
                    val = *(int *) value;
                    if (ptr[j]->district == val) {
                        temp = ptr[j];
                        indexes[k++] = j;
                    } else
                        continue;
                    break;
                case 2:
                    val2 = *(double *) value;
                    if (ptr[j]->area == val2) {
                        temp = ptr[j];
                        indexes[k++] = j;
                    } else
                        continue;
                    break;
                case 4:
                    val = *(int *) value;
                    if (ptr[j]->rooms == val) {
                        temp = ptr[j];
                        indexes[k++] = j;
                    } else
                        continue;
                    break;
                case 5:
                    val = *(int *) value;
                    if (ptr[j]->floor == val) {
                        temp = ptr[j];
                        indexes[k++] = j;
                    } else
                        continue;
                    break;
                default:
                    printf("Invalid selection\n");
            }
            printf("%d ) House name : %s\n", k, temp->house_name);
            printf("   Price : %d\n\n", temp->price);
        }
        printf("page : [%d/%d]\n", i + 1, pages + 1);
        printf("1) select the page\n");
        printf("2) show the ad completely\n");
        printf("3) take any action on it\n");
        printf("4) just exit\n");
        printf("[N/P] goto the next or prev page\n");
        scanf("%c", &c);
        if (c == 'P' || c == 'N') {
            system("cls");
            if (c == 'P' && i > 0)
                i--;
            else if (i != pages)
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
                    if (select && type != general && type != seller)
                        show_completely_seller(ptr[indexes[select2 - 1]]);
                    else
                        show_completely(ptr[select - 1]);
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