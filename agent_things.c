#include "declarations2.h"
#include "my_structs.h"
extern int count_reqs;

void show_completely_seller(house *ptr);


int find_requests(house *all_houses[],house *requests[]){
    int i,k=0;
    for (i=0;i<count_reqs;i++){
        if (all_houses[i]->cond==0)
            requests[k++]=all_houses[i];
    }
    return k;
}


//int show_all_reqs(house *current[],int counts){
//    int i=1,select,pages,t,l;
//    pages=counts/10;
//    char c;
//    getchar();
//    while (1) {
//        t = i * 10;
//        l=(i-1)*10;
//        for (int j = l; j < t  && j < counts; j++) {
//            printf("%d ) House name : %s\n", j + 1, current[j]->house_name);
//            printf("   Price : %d\n\n", current[j]->price);
//        }
//        if (i==pages)
//            printf("First page\n");
//        if (i==(pages+1)){
//            printf("The last page.\n");
//            printf("Previous/Current page : [P/C]\n");
//            scanf("%c", &c);
//            if (c=='C') {
//                printf("Press the number of house to show the ad completely or press 0 to return :\n");
//                scanf("%d", &select);
//                break;
//            }
//        }else {
//            printf("Next/Previous/Current page : [N/P/C]\n");
//            scanf("%c", &c);
//        }
//            if (c == 'N' && i != pages) {
//                i++;
//                system("cls");
//            }
//            if (c == 'P' && i != 1) {
//                i--;
//                system("cls");
//            }
//            if (c == 'C') {
//                printf("Press the number of house to show the ad completely and do agent things or press 0 to return :\n");
//                scanf("%d", &select);
//                break;
//            }
//
//    }
//
//    if (select)
//        show_completely_seller(current[select-1]);
//    return select;
//}




house * agent_things(users *current_agent,house *all_houses[],users *all_users[],FILE *file){
    double temp2;
    int temp;
    char shit[30];
    house *requests[1000];
    int counts=find_requests(all_houses,requests),select,action;
    select= show_ads_general(all_houses,agent,2);
    if (!select)
        return NULL;
    printf("Which action you want to take ? [1:accept/2:reject]\n");
    scanf("%d",&action);
    int *index= binary_search(5,requests[select-1]->user_name,NULL,all_users);
    q_sort2(all_users[index[3]]->ptr,0,all_users[index[3]]->next-1);
    int index2= binary_search2(5,requests[select-1]->house_name,NULL,all_users[index[3]]->ptr,all_users[index[3]]->next);
    int index3= binary_search2(5,requests[select-1]->house_name,NULL,all_houses,count_reqs);
    int prev=all_houses[select-1]->cond;
    all_houses[select-1]->cond=action;
    all_users[index[3]]->ptr[index2]->cond=action;
    FILE *file_temp= fopen("temp.txt","a+");
    fseek(file,0,SEEK_SET);
    for (int k=0;k<count_reqs;k++){

        fprintf(file_temp,"%s ",all_houses[k]->user_name);

        fprintf(file_temp,"%s ",all_houses[k]->house_name);

        fprintf(file_temp,"%d ",all_houses[k]->district);

        fprintf(file_temp,"%.2lf ",all_houses[k]->area);

        fprintf(file_temp,"%d ",all_houses[k]->price);

        fprintf(file_temp,"%d ",all_houses[k]->rooms);

        fprintf(file_temp,"%d ",all_houses[k]->floor);



        if (k==index3) {
            fprintf(file_temp, "%d ", action);
            printf("Condition of %s went from %d to %d\n",requests[select-1]->house_name,prev,action);
            system("pause");
            system("cls");
        }
        else
            fprintf(file_temp,"%d ",all_houses[k]->cond);

    }
    fclose(file);
    if (!remove("ads.txt"))
        printf("File deleted successfully\n");
    else
        printf("File was not deleted\n");
    fclose(file_temp);
    if (!rename("temp.txt","ads.txt"))
        printf("File was renamed successfully\n");
    else
        printf("File was not renamed\n");
    file= fopen("ads.txt","a+");
    fseek(file,0,SEEK_END);
    return all_houses[index3];
}

