//
// Created by bragl on 1/28/2024.
//

#ifndef PROJECT_WALLE_DECLARATIONS2_H
#define PROJECT_WALLE_DECLARATIONS2_H
#include "declarations.h"
void admin_things(users *all_users[],FILE *ads,log *all_logs[]);
house * agent_things(users *current_agent,house *all_houses[],users *all_users[],FILE *file);
void sorting(house *all_ads[],enum types type,int flag);
int show_ads_general(house *ptr[],enum types type,int flag);
void filter(house *all_ads[],users *current);
int suggest(int district,int floor,int rooms,double area);
void edit_item(users *current,FILE *file,house *all_house[]);
int show_user_ads(users *list);
house * request_adv(users *current,int index,users *all_users[],FILE *file,house *all_ads[]);
users * login(FILE *file, users *list[],int *ind_curr);
void sign_up(FILE *file,users *user_ptr[]);
#endif //PROJECT_WALLE_DECLARATIONS2_H
