int count=0;
#include "declarations2.h"


int count_reqs=0,k=0,log_ind=0;
users *req_up[1000]={NULL};

int menu_general() {
    int select;
    printf("1) sign up\n");
    printf("2) login\n");
    printf("3) logout\n");
    printf("4) sort\n");
    printf("5) goto seller menu\n");
    printf("6) show all advertises\n");
    printf("7) goto agent menu\n");
    printf("8) goto admin menu\n");
    printf("9) exit the app\n");
    printf("10) current user\n");
    //others later
    printf("select the action :\n");
    scanf("%d",&select);
    return select;
}


int seller_menu(){
    int select;
    printf("1) request advertisement.\n");
    printf("2) show user ads.\n");
    printf("3) Edit.\n");
    printf("4) Filter\n");
    printf("5) sort\n");
    printf("6) show all ads\n");
    printf("7) request for upgrade\n");
    printf("8) sort the user ads\n");
    printf("9) exit the menu.\n");
    printf("select the action :\n");
    scanf("%d",&select);
    return select;
}



void get_action_seller(users *all_users[],struct house *requests[],users *current_user,int index,FILE *file){
    int select;

    while (1){
        system("cls");
        house *temp;
        select=seller_menu();
        switch (select) {
            case 1:
                system("cls");
                temp= request_adv(current_user,index,all_users,file,requests);
                if (temp!=NULL)
                    requests[count_reqs++]=temp;
                break;
            case 2:
                system("cls");
                show_ads_general(current_user->ptr,seller,1);
                break;
            case 3:
                system("cls");
                edit_item(current_user,file,requests);
                break;
            case 4:
                system("cls");
                filter(requests,current_user);
                break;
            case 5:
                system("cls");
                sorting(requests,seller,0);
                break;
            case 6:
                system("cls");
                show_ads_general(requests,current_user->type,0);
                break;
            case 7:
                system("cls");
                req_up[k]=(users *) malloc(sizeof (users));
                strcpy(req_up[k]->username,current_user->username);
                strcpy(req_up[k]->pass,current_user->pass);
                req_up[k]->type=seller;
                k++;
                printf("%s\n",req_up[k-1]->username);
                system("pause");
                break;
            case 8:
                system("cls");
                sorting(current_user->ptr,seller,1);
                break;
            case 9:
                system("cls");
                return;
        }
    }
}


int agent_menu(){
    int select;
    printf("1) request advertisement.\n");
    printf("2) show user ads.\n");
    printf("3) Edit.\n");
    printf("4) Filter\n");
    printf("5) sort\n");
    printf("6) agent things\n");
    printf("7) show all ads\n");
    printf("8) sort the user ads\n");
    printf("9) exit the menu.\n");
    printf("select the action :\n");
    scanf("%d",&select);
    return select;
}

void get_action_agent(users *all_users[],struct house *requests[],users *current_agent,int index,FILE *file,FILE *log,struct log *all_logs[]){
    int select;

    house *temp_house;
    while (1){
        system("cls");
        house *temp;
        select=agent_menu();
        switch (select) {
            case 1:
                system("cls");
                temp= request_adv(current_agent,index,all_users,file,requests);
                if (temp!=NULL)
                    requests[count_reqs++]=temp;
                break;
            case 2:
                system("cls");
                show_ads_general(current_agent->ptr,current_agent->type,1);
                break;
            case 3:
                system("cls");
                edit_item(current_agent,file,requests);
                break;
            case 4:
                system("cls");
                filter(requests,current_agent);
                break;
            case 5:
                system("cls");
                sorting(requests,agent,0);
                break;
            case 6:
                system("cls");
                temp_house=agent_things(current_agent,requests,all_users,file);
                if (temp_house->cond==reject)
                    break;
                fprintf(log,"%s %s %s ",temp_house->house_name,temp_house->user_name,current_agent->username);
                all_logs[log_ind]=(struct log *) malloc(sizeof (struct log));
                strcpy(all_logs[log_ind]->house_name,temp_house->house_name);
                strcpy(all_logs[log_ind]->seller,temp_house->user_name);
                strcpy(all_logs[log_ind]->agent,current_agent->username);
                log_ind++;
                break;
            case 7:
                system("cls");
                show_ads_general(requests,current_agent->type,0);
                break;
            case 8:
                system("cls");
                sorting(current_agent->ptr,agent,1);
                break;
            case 9:
                system("cls");
                return;
        }
    }
}

int admin_menu(){
    int select;
    printf("1) request advertisement.\n");
    printf("2) show user ads.\n");
    printf("3) Edit.\n");
    printf("4) Filter\n");
    printf("5) sort\n");
    printf("6) admin things\n");
    printf("7) show all ads\n");
    printf("8) sort the user ads\n");
    printf("9) exit the menu.\n");
    printf("select the action :\n");
    scanf("%d",&select);
    return select;
}

void get_admin_action(users *all_users[],struct house *requests[],users *current_user,FILE *file_users,FILE *file_ads,log *all_logs[]){
    int select;
    int static flag=0;
    if (!flag)
        current_user->next=0;
    flag++;
    while (1){
        system("cls");
        house *temp;
        select=admin_menu();
        switch (select) {
            case 1:
                system("cls");
                temp= request_adv(current_user,0,all_users,file_ads,requests);
                if (temp!=NULL)
                    requests[count_reqs++]=temp;
                break;
            case 2:
                system("cls");
                show_ads_general(current_user->ptr,current_user->type,1);
                break;
            case 3:
                system("cls");
                edit_item(current_user,file_ads,requests);
                break;
            case 4:
                system("cls");
                filter(requests,current_user);
                break;
            case 5:
                system("cls");
                sorting(requests,admin,0);
                break;
            case 6:
                system("cls");
                admin_things(all_users,file_users,all_logs);
                break;
            case 7:
                system("cls");
                show_ads_general(requests,current_user->type,0);
                break;
            case 8:
                system("cls");
                sorting(current_user->ptr,admin,1);
                break;
            case 9:
                system("cls");
                return;
        }
    }
}


int main() {
    system("cls");
    FILE *file,*file2,*log;
    int select,ind_curr,y;
    file= fopen("users.txt","a+");
    file2= fopen("ads.txt","a+");
    log= fopen("log.txt","a+");
    users *list[1000]={NULL};
    house *requests[1000]={NULL};
    users *current_user=NULL;
    get_all_users(file,list);
    for (int i=0;i<count;i++)
        list[i]->next=0;
    get_all_ads(file2,requests,list);
    int u=count_reqs;
    q_sort2(requests,0,u-1);
    char username[MAXUSER],pass[MAXPASS];
    struct log *all_logs[1000]={NULL};
    get_logs(log,all_logs);
    enum types type;
    while (1){

        select=menu_general();
        switch (select) {
            case 1:
                system("cls");
                sign_up(file,list);
                break;
            case 2:
                system("cls");
                if (current_user!=NULL){
                    printf("a user is currently logged in\n");
                    system("pause");
                    break;
                }
                current_user=login(file,list,&ind_curr);
                break;
            case 3:
                system("cls");
                if (current_user!=NULL) {
                    free(current_user);
                    current_user=NULL;
                    printf("User logged out\n");
                    system("pause");
                    system("cls");
                }
                else {
                    printf("There is no current user\n");
                    system("pause");
                    system("cls");
                }
                break;
            case 4:
                system("cls");
                sorting(requests,general,0);
                break;
            case 5:
                system("cls");
                if (current_user!=NULL && (current_user->type==seller || current_user->type==agent)){
                    get_action_seller(list,requests,current_user,ind_curr,file2);
                }
                break;

            case 6:
                system("cls");
                if (current_user!=NULL){
                    y=current_user->type;
                } else{
                    y=general;
                }
                show_ads_general(requests,y,0);
                break;
            case 7:
                system("cls");
                if (current_user!=NULL &&  current_user->type==agent)
                    get_action_agent(list,requests,current_user,ind_curr,file2,log,all_logs);
                break;
            case 8:
                system("cls");
                if (current_user!=NULL &&  current_user->type==admin)
                    get_admin_action(list,requests,current_user,file,file2,all_logs);
                    break;
            case 9:
                system("cls");
                fclose(file2);
                fclose(file);
                exit(0);
            case 10:
                if (current_user==NULL) {
                    printf("There is no current user\n");
                    system("pause");
                    system("cls");
                    break;
                }
                printf("Username : %s\n",current_user->username);
                printf("Type : %d\n",current_user->type);
                system("pause");
                system("cls");
                break;
            default:
                printf("Invalid input!!!\n");
        }
    }

}
