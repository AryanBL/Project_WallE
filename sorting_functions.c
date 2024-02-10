#include "my_structs.h"
#include "declarations2.h"
extern int count_reqs;
int insert(house *all_ads[],house *temp[],enum types type,int flag);
#define STRING(n) ((n)==1 ? "district" : (n)==2 ? "area" : (n)==3 ? "price" : (n)==4 ? "room numbers" : "floor number")
#define SELECT(n) ((n)==1 ? "district" : (n)==2 ? "area" : (n)==3 ? "price" : (n)==4 ? "rooms" : "floor")
int show_sorted_ads(house *sorted[],int select,int type);
void insert_sort(house *all_ads[],house *temp[],int select,enum types type);
void q_sort_3(house *temp[],int left,int right,int select);
void selection_sort(house *temp[],int select,int num);
void show_completely_seller(house *ptr);
int select_sort(){
    int select;
    printf("1) sort based on district.\n");
    printf("2) sort based on area.\n");
    printf("3) sort based on price.\n");
    printf("4) sort based on room numbers.\n");
    printf("5) sort based on floor number.\n");
    printf("Select your choice :\n");
    scanf("%d",&select);
    return select;
}



void sorting(house *all_ads[],enum types type,int flag){
    int select=select_sort();
    house *temp[1000]={NULL};
    int num=insert(all_ads,temp,type,flag);
   // q_sort_3(temp,0,count_reqs,select);
  //  insert_sort(all_ads,temp,select,type);
    selection_sort(temp,select,num);
    printf("All ads sorted based on %s :\n", STRING(select));
    show_ads_general(temp,type,flag);
}


double compare_sort(house *a,house *b,int select){
    int x,y;
    double z,t;
    switch (select) {
        case 1:
            x=a->district;
            y=b->district;
            return x-y;
        case 2:
            z=a->area;
            t=b->area;
            return z-t;
        case 3:
            x=a->price;
            y=b->price;
            return x-y;
        case 4:
            x=a->rooms;
            y=b->rooms;
            return x-y;
        case 5:
            x=a->floor;
            y=b->floor;
            return x-y;
    }
}

void swap2(house *all_ads[],int a,int b){
    house *temp;
    temp=all_ads[a];
    all_ads[a]=all_ads[b];
    all_ads[b]=temp;
}


int insert(house *all_ads[],house *temp[],enum types type,int flag){
    int i,k=0;
    for (i=0;i<count_reqs && all_ads[i]!=NULL;i++){
        if (((type==general && all_ads[i]->cond!=1)) || ((type==seller && !flag) && all_ads[i]->cond!=1))
            continue;
        temp[k++]=all_ads[i];
    }
    return k;
}



void selection_sort(house *temp[],int select,int num){
     int i,j;
     house *min;
    double min_area;
    if (select==2)
        min_area=temp[0]->area;

    int k;

    for (i=0;i<num-1;i++){
        min=temp[i];
        k=i;
        for ( j=i+1;j<num;j++){
            if (compare_sort(temp[j],min,select)<0.0) {
                min = temp[j];
                k=j;
            }
        }
        house * p=temp[i];
        temp[i]=min;
        int p2=min->price;
        temp[k]=p;
    }
}




void q_sort_3(house *temp[],int left,int right,int select){
    int i,last=left;
    if (left>=right)
        return;
    swap2(temp,left,(left+right)/2);
    for (i=left+1;i<right;i++){
        if (compare_sort(temp[i],temp[left],select)<0){
            swap2(temp,i,++last);
        }
    }
    swap2(temp,left,last);
    q_sort_3(temp,left,last-1,select);
    q_sort_3(temp,last+1,right,select);
}




void insert_sort(house *all_ads[],house *temp[],int select,enum types type){
    int i,j,k;int price;
    house *t1;house *t2;
    for (i=0;all_ads[i]!=NULL;i++){
        if (type==general && all_ads[i]->cond!=1)
            continue;
        for (j=0; temp[j]!=NULL && compare_sort(all_ads[i],temp[j],select)>0.0;j++);
        price=all_ads[i]->price;
        if (temp[j]==NULL)
            temp[j]=all_ads[i];
        else{
            t1=temp[k];
            for (k=j;temp[k+1]!=NULL;k++){
                t2=temp[k+1];
                temp[k+1]=t1;
                t1=t2;
            }
            temp[k+1]=t1;
            temp[j]=all_ads[i];
        }
    }
}





//
//int show_sorted_ads(house *sorted[],int select,int type){
//    int i=0,pages,t,l,select2;
//    pages=count_reqs/10;
//    char c;
//    getchar();
//    printf("all ads sorted based on %s:\n\n", STRING(select));
//    while (1) {
//        t = (i+1) * 10;
//        l=i*10;
//        for (int j = l; j < t  && j < count_reqs && sorted[j]!=NULL; j++) {
//            printf("%d ) House name : %s\n", j + 1, sorted[j]->house_name);
//            int p=sorted[j]->price;
//            printf("   Price : %d\n\n", sorted[j]->price);
//        }
//        if (i==pages)
//            printf("First page\n");
//        if (i==(pages+1)){
//            printf("The last page.\n");
//            printf("Previous/Current page : [P/C]\n");
//            scanf("%c", &c);
//            getchar();
//            if (c=='C') {
//                printf("Press the number of house to show the ad completely or press 0 to return :\n");
//                scanf("%d", &select2);
//                break;
//            }
//        } else {
//            printf("Next/Previous/Current page : [N/P/C]\n");
//            scanf("%c", &c);
//            getchar();
//        }
//        if (c == 'N') {
//            i++;
//            system("cls");
//        }
//        if (c == 'P' ) {
//            i--;
//            system("cls");
//        }
//        if (c == 'C') {
//            printf("Press the number of house to show the ad completely or press 0 to return :\n");
//            scanf("%d", &select2);
//            break;
//        }
//
//    }
//
//
//    if (select2)
//        show_completely_seller(sorted[select2-1]);
//    return select;
//}

