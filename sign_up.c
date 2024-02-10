
#include "declarations.h"
extern int count;


void sign_up(FILE *file,users *user_ptr[]){
    char username[MAXUSER],c;
    users *ptr=(users *) malloc(sizeof (users));
    printf("Please enter the type of user :\n");
    scanf("%d",&ptr->type);
    printf("Please enter the username :\n");
    scanf("%s", ptr->username);
    int len= strlen(ptr->username);
    printf("%d\n",len);
    ptr->username[len]='\0';
    int *res= binary_search(ptr->type,ptr->username,NULL,user_ptr);
    if (res[0]){
        printf("This user has already exists.\n");
        system("pause");
        system("cls");
       // getchar();
        free(ptr);
        return;
    }
    printf("Please enter the password :\n");
    scanf("%s", ptr->pass);
    ptr->next=0;
    user_ptr[count++]=ptr;

    fseek(file,0,SEEK_END);
    fprintf(file,"%s ",ptr->username);
    fprintf(file,"%s ",ptr->pass);
    fprintf(file,"%d ",ptr->type);
    system("cls");
}

