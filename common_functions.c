#include <stdio.h>
#include <stdlib.h>
#include "my_structs.h"
#include <string.h>
#define STRING(n) ((n)==0 ? "users" : "house")
extern int count,log_ind;
extern int count_reqs;
typedef struct users users;
void insertion(users *ptr[], users *user);
void q_sort(users *ptr[], int left, int right );
int strcmmp(char *a,char *b);
void swap(void *a[],int i,int j);
void hard_copy(users *ptr[],users *user,int index){
    strcpy(ptr[index]->username,user->username);
    strcpy(ptr[index]->pass,user->pass);
    ptr[index]->type=user->type;
}


void q_sort(users *ptr[], int left, int right) {
    int last = left, i;
    if (left >= right)
        return;

    swap((void *)ptr, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (strcmmp(ptr[i]->username, ptr[left]->username) < 0)  {
            swap((void *)ptr, ++last, i);
        }
    }
    swap((void *)ptr, last, left);
    q_sort(ptr, left, last - 1);
    q_sort(ptr, last + 1, right);
}

int strcmmp(char *a,char *b){
    if (a==NULL)
        return -1;
    for (;*a==*b;){
        if (*a=='\0' || *b=='\0')
            return 0;
        a++;b++;
    }
//    if (*a=='\0' || *b=='\0')
//        return 0;
    return *a-*b;
}

void get_all_users(FILE *file, users *ptr[]){
    users *pt_user=(users *) malloc(sizeof (users));
    users *user;

    if (feof(file))
        return;
    user=( users *) malloc(sizeof (users));
    while (fscanf(file,"%s",user->username)!=EOF){
        fscanf(file,"%s",user->pass);
        fscanf(file,"%d",&user->type);
//        strcpy(pt_user->username,user->username);
//        strcpy(pt_user->pass,user->pass);
//        pt_user->type=user->type;
//        ptr[count]=user;
        ptr[count]=(users *) malloc(sizeof (users));
        strcpy(ptr[count]->username,user->username);
        strcpy(ptr[count]->pass,user->pass);
        ptr[count]->type=user->type;


      //  printf("%d\n",count);
       //insertion(ptr,pt_user);
        count++;

        if (feof(file)) {
            q_sort((void *)ptr,0,count-1);
            return;
        }
    }
    q_sort(ptr,0,count-1);
    //free(user);

}



void swap(void *a[],int i,int j){
    void *temp;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}



void q_sort2(struct house *ptr[], int left, int right) {
    int last = left, i;
    if (left >= right)
        return;

    swap((void *)ptr, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (strcmmp(ptr[i]->house_name, ptr[left]->house_name) < 0)  {
            swap((void *)ptr, ++last, i);
        }
    }
    swap((void *)ptr, last, left);
    q_sort2(ptr, left, last - 1);
    q_sort2(ptr, last + 1, right);
}


void insertion(users *ptr[], users *user) {
    int index;
    users *temp_user,*pt;
    if (ptr[0] == NULL) {
        ptr[0]= (users *)malloc(sizeof (users));
        hard_copy(ptr,user,0);
        return;
    }
    for (index = 0; strcmmp(user->username, ptr[index]->username) > 0; index++) {
        if (ptr[index] == NULL) {
            ptr[index]=(users *) malloc(sizeof (users));
            hard_copy(ptr,user,index);
            return;
        }
    }

    pt=ptr[index];
    for (int i=index;pt!=NULL;i++){
        temp_user=ptr[i+1];
        if (ptr[i+1]==NULL){
            ptr[i+1]=(users *) malloc(sizeof (users));
        }
        hard_copy(ptr,pt,i+1);
        pt=temp_user;
    }

    hard_copy(ptr,user,index);
}





int * binary_search(enum types type,char *username,char *password,users *ptr[]){
    int mid=count/2,right=count-1,left=0,*res= malloc(sizeof (int)*4);
    while (left<=right){
        if (!strcmmp(username,ptr[mid]->username)){
            res[0]=1;res[1]=(!strcmmp(password,ptr[mid]->pass));
            res[2]=(type==ptr[mid]->type);
            res[3]=mid;
            return res;
        }
        if (strcmmp(username,ptr[mid]->username)<0){
            right=mid-1;
            mid=(left+right)/2;
        } else{
            left=mid+1;
            mid=(left+right)/2;
        }
    }
    res[0]=0;res[1]=0;res[2]=0;res[3]=0;
    return res;
}

int  binary_search2(enum types type,char *username,char *password,struct house *ptr[],int end){
    int mid=end/2,right=end-1,left=0,res;
    while (left<=right){
        if (!strcmmp(username,ptr[mid]->house_name)){
            res=mid;
            return res;
        }
        if (strcmmp(username,ptr[mid]->house_name)<0){
            right=mid-1;
            mid=(left+right)/2;
        } else{
            left=mid+1;
            mid=(left+right)/2;
        }
    }

    return -1;
}





void get_all_ads(FILE *file,struct house *p_house[],users *p_user[]){
    int index=0,*res,next;
    if (feof(file))
        return;
    p_house[index]=(struct house *) malloc(sizeof (struct house));
    while (fscanf(file,"%s",p_house[index]->user_name)){
        fscanf(file,"%s",p_house[index]->house_name);
        fscanf(file,"%d",&p_house[index]->district);
        fscanf(file,"%lf",&p_house[index]->area);
        fscanf(file,"%d",&p_house[index]->price);
        fscanf(file,"%d",&p_house[index]->rooms);
        fscanf(file,"%d",&p_house[index]->floor);
        fscanf(file,"%d",&p_house[index]->cond);

        res= binary_search(0,p_house[index]->user_name,NULL,p_user);
        if (!res[0]) {

            return;
        }
        count_reqs++;
        next=p_user[res[3]]->next;
        p_user[res[3]]->ptr[next]=p_house[index];
        p_user[res[3]]->next++;
        index++;
        p_house[index]=(struct house *) malloc(sizeof (struct house));
      //  fgetc(file);
        if (feof(file))
            return;
    }
}

void get_logs(FILE *log,struct log *all_logs[]){
    all_logs[log_ind]=(struct log *) malloc(sizeof (struct log));
    while (fscanf(log,"%s",all_logs[log_ind]->house_name)>0){
        fscanf(log,"%s",all_logs[log_ind]->seller);
        fscanf(log,"%s",all_logs[log_ind]->agent);
        log_ind++;
        if (feof(log))
            return;
        all_logs[log_ind]=(struct log *) malloc(sizeof (struct log));
    }
}


