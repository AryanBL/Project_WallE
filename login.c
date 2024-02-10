#include "declarations.h"
extern users *req_up[1000];
extern int k;

users * login(FILE *file, users *list[],int *ind_curr){
    users *ptr;
    int *res,type;
    ptr=(users *) malloc(sizeof (users));
    char username[MAXUSER],c;
    printf("Please enter the type of user :\n");
    scanf("%d",&type);
    if (type==admin){
        char temp_str[30];
        printf("Please enter the username :\n");
        scanf("%s",temp_str);
        if (strcmmp(temp_str,"admin")){
            printf("Wrong username\n");
            return NULL;
        }
        else{
            strcpy(ptr->username,temp_str);
            printf("please enter the password :\n");
            scanf("%s",temp_str);
            if (strcmmp(temp_str,"@dmin")){
                printf("Wrong password\n");
                return NULL;
            }
            strcpy(ptr->pass,temp_str);
        }
        printf("User login successful\n");
        system("pause");
        system("cls");
        ptr->type=admin;
        return ptr;
    }
    ptr->type=type;
    printf("Please enter the username :\n");
    scanf("%s",ptr->username);
    printf("please enter the password :\n");
    scanf("%s",ptr->pass);
    res=binary_search(ptr->type,ptr->username,ptr->pass,list);
    if (!res[0]){
        printf("Username not found\n");
        free(res);
        free(ptr);
        system("pause");
        getchar();
        return NULL;
    }
    if (!res[1]){
        printf("incorrect password\n");
        free(ptr);
        free(res);
        system("pause");
        getchar();
        return NULL;
    }
    if (!res[2]){
        printf("User type conflict\n");
        free(ptr);
        free(res);
        system("pause");
        getchar();
        return NULL;
    }
    printf("User login successful\n");
    *ind_curr=res[3];
    for (int i=0;i<list[*ind_curr]->next;i++){
        ptr->ptr[i]=list[*ind_curr]->ptr[i];
    }
    ptr->next=list[*ind_curr]->next;
    system("cls");
    return ptr;
}