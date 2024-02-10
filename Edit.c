#include "declarations2.h"
#include "my_structs.h"
extern int count_reqs;


int select_editor(int index,users *current){
    int select;
    printf("Select the item which you want to edit for %s:\n",current->ptr[index-1]->house_name);
    printf("1) Edit district.\n");
    printf("2) Edit area.\n");
    printf("3) Edit price.\n");
    printf("4) Edit room numbers.\n");
    printf("5) Edit floor number.\n");
    printf("Select your choice :\n");
    scanf("%d",&select);
    system("cls");
    return select;
}




void edit_item(users *current,FILE *file,house *all_house[]){
    int select;
    int index= show_ads_general(current->ptr,current->type,1);
    if (!index)
        return;
    int prev_value, new_value;
    double prev_area,new_area;
    select=select_editor(index,current);
    if (!select)
        return;
    switch(select){

        case 1:
            prev_value = current->ptr[index-1]->district;
            printf("Here is the previous value: %d\n", prev_value);
            printf("Enter the new value: ");
            scanf("%d", &new_value);
            current->ptr[index-1]->district=new_value;
            break;
        case 2:
            prev_area = current->ptr[index-1]->area;
            printf("Here is the previous value: %lf\n", prev_area);
            printf("Enter the new value: ");
            scanf("%lf", &new_area);
            current->ptr[index-1]->area = new_area;
            break;
        case 3:
            prev_value = current->ptr[index-1]->price;
            printf("Here is the previous value: %d\n", prev_value);
            printf("Enter the new value: ");
            scanf("%d", &new_value);
            current->ptr[index-1]->price = new_value;
            break;
        case 4:
            prev_value = current->ptr[index-1]->rooms;
            printf("Here is the previous value: %d\n", prev_value);
            printf("Enter the new value: ");
            scanf("%d", &new_value);
            current->ptr[index-1]->rooms = new_value;
            break;
        case 5:
            prev_value = current->ptr[index-1]->floor;
            printf("Here is the previous value: %d\n", prev_value);
            printf("Enter the new value: ");
            scanf("%d", &new_value);
            current->ptr[index-1]->floor = new_value;
            break;
        default:
            printf("Invalid selection.\n");
            break;
    }
    int i;
    char shit[30],c;
    int temp;
    double temp2;
    int index2= binary_search2(5,current->ptr[index-1]->house_name,NULL,all_house,count_reqs);
    fseek(file,0,SEEK_SET);
    FILE *file_temp= fopen("temp.txt","a+");
    if (file_temp==NULL) {
        printf("couldn't open the file.\n");
        return;
    }
    for ( i=0;i<count_reqs;i++){

        fprintf(file_temp,"%s ",all_house[i]->user_name);

        fprintf(file_temp,"%s ",all_house[i]->house_name);
        if (i==index2){
            if (select==1)
                fprintf(file_temp,"%d ",new_value);
            else
                fprintf(file_temp,"%d ",all_house[i]->district);
            if (select==2)
                fprintf(file_temp,"%lf ",new_area);
            else
                fprintf(file_temp,"%lf ",all_house[i]->area);
            if (select==3)
                fprintf(file_temp,"%d ",new_value);
            else
                fprintf(file_temp,"%d ",all_house[i]->price);
            if (select==4)
                fprintf(file_temp,"%d ",new_value);
            else
                fprintf(file_temp,"%d ",all_house[i]->rooms);
            if (select==5)
                fprintf(file_temp,"%d ",new_value);
            else
                fprintf(file_temp,"%d ",all_house[i]->floor);
        } else {
            fprintf(file_temp, "%d ", all_house[i]->district);

            fprintf(file_temp, "%.2lf ", all_house[i]->area);

            fprintf(file_temp, "%d ", all_house[i]->price);

            fprintf(file_temp, "%d ", all_house[i]->rooms);

            fprintf(file_temp, "%d ", all_house[i]->floor);

            fprintf(file_temp, "%d ", all_house[i]->cond);
        }
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
    system("cls");
}
