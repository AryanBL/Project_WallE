#include "declarations2.h"


typedef struct house house;
extern int count_reqs;
house * request_adv(users *current,int index,users *all_users[],FILE *file,house *all_ads[]){
    house *house1=(house *) malloc(sizeof (house));
    if (current==NULL){
        printf("You have to sign in first to register an advertise.\n");
        system("pause");
        getchar();
        return NULL;
    }
    strcpy(house1->user_name,current->username);
    printf("Name of the house :\n");
    scanf("%s",house1->house_name);
    printf("Which district :\n");
    scanf("%d",&house1->district);
    printf("The area of your house :\n");
    scanf("%lf",&house1->area);
    printf("Number of rooms :\n");
    scanf("%d",&house1->rooms);
    printf("Number of floor :\n");
    scanf("%d",&house1->floor);
    house1->cond=request;
   int suggestion=suggest(house1->district,house1->floor,house1->rooms,house1->area);
    printf("The suggested price for your house : %d\n",suggestion);
    printf("The price of your house :\n");
    scanf("%d",&house1->price);

    fseek(file,0,SEEK_END);
    fprintf(file,"%s ",house1->user_name);
    fprintf(file,"%s ",house1->house_name);
    fprintf(file,"%d ",house1->district);
    fprintf(file,"%.2lf ",house1->area);
    fprintf(file,"%d ",house1->price);
    fprintf(file,"%d ",house1->rooms);
    fprintf(file,"%d ",house1->floor);
    fprintf(file,"%d ",house1->cond);

    int next=all_users[index]->next;
    if (current->type!=admin) {
        all_users[index]->next++;
        all_users[index]->ptr[next] = house1;
    }
    current->ptr[next]=house1;
    all_ads[count_reqs++]=house1;
    current->next++;
    return house1;
}
