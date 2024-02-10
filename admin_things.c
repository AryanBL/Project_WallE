#include "declarations.h"
extern int count,k,log_ind;
extern users *req_up[];
void copy_to_file(users *all_users[],int index,FILE *file,int action);


void admin_things(users *all_users[],FILE *file,log *all_logs[]) {
    int choice, t, index, *ind, action;
    char c;
    while (1) {
        printf("Choose which list to show\n");
        printf("1) Upgrade requests\n");
        printf("2) All users\n");
        printf("3) Show log\n");
        printf("0) to exit\n");
        scanf("%d", &choice);
        system("cls");
        if (!choice)
            return;
        if (choice == 1) {
            t = show_all_users(req_up, k);
            if (t) {
                ind = binary_search(5, req_up[t - 1]->username, NULL, all_users);
                index = ind[3];
                getchar();
                printf("Do you want to take any action ? [Y/N]\n");
                scanf("%c", &c);
                if (c == 'Y') {
                    scanf("%d", &action);
                    if (action)
                        printf("User %s has been upgraded to agent.\n", all_users[index]->username);
                    all_users[index]->type = action;
                    copy_to_file(all_users,index, file, action);
                    system("pause");
                    system("cls");
                }
            }
        }
        if (choice == 2) {
                t = show_all_users(all_users, count);
                system("cls");
                if (t) {
                    index = t - 1;
                    getchar();
                    printf("Do you want to take any action ? [Y/N]\n");
                    scanf("%c", &c);
                    if (c == 'Y') {
                        printf("Take your action : [0:seller/1:agent]\n");
                        scanf("%d", &action);
                        if (action)
                            printf("User %s has been upgraded to agent.\n", all_users[index]->username);
                        else
                            printf("User %s has been downgraded to seller.\n", all_users[index]->username);
                        all_users[index]->type = action;
                        copy_to_file(all_users,index,file,action);
                        system("pause");
                        system("cls");
                    }
                }
            }
            if (choice == 3) {
                show_all_logs(all_logs, log_ind);
                system("cls");
            }
        }
}


void copy_to_file(users *all_users[],int index,FILE *file,int action){
    FILE *file_temp= fopen("temp.txt","a+");

    fseek(file,0,SEEK_SET);
    for (int y=0; y < count; y++){
        fprintf(file_temp,"%s ",all_users[y]->username);
        fprintf(file_temp,"%s ",all_users[y]->pass);
        if (y == index) {
            fprintf(file_temp, "%d ", action);
        }
        else
            fprintf(file_temp,"%d ",all_users[y]->type);

    }
    fclose(file);
    if (!remove("users.txt"))
        printf("File deleted successfully\n");
    else
        printf("File was not deleted\n");
    fclose(file_temp);
    if (!rename("temp.txt","users.txt"))
        printf("File was renamed successfully\n");
    else
        printf("File was not renamed\n");
    file= fopen("users.txt","a+");
    fseek(file,0,SEEK_END);
}
