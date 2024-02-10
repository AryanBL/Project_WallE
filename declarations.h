//
// Created by bragl on 1/22/2024.
//

#ifndef PROJECT_WALLE_DECLARATIONS_H
#define PROJECT_WALLE_DECLARATIONS_H
#include <stdio.h>
#include <stdlib.h>
#include "my_structs.h"
#include <string.h>
typedef struct users users;
typedef struct house house;
typedef struct log log;
void show_all_logs(log *all_logs[], int count);
int show_all_users(users *all_users[],int count);
void q_sort2(struct house *ptr[], int left, int right);
void insertion(users *ptr[], users *user);
void get_all_ads(FILE *file,struct house *p_house[],users *p_user[]);
int strcmmp(char *a,char *b);
void get_all_users(FILE *file, users *ptr[]);
int * binary_search(enum types type,char *username,char *password,users *ptr[]);
int  binary_search2(enum types type,char *username,char *password,struct house *ptr[],int end);
void show_completely_seller(house *ptr);
void show_completely(house *ptr);
void get_logs(FILE *log,struct log *all_logs[]);

#endif //PROJECT_WALLE_DECLARATIONS_H
