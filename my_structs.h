

#ifndef PROJECT_WALLE_MY_STRUCTS_H
#define PROJECT_WALLE_MY_STRUCTS_H


#define MAXUSER 30
#define MAXPASS 30
enum types{seller,agent,admin,general};
enum condition{request,accept,reject};
struct house{
    char user_name[MAXUSER];
    char house_name[MAXUSER];
    int district;
    double area;
    int price;
    int rooms;
    int floor;
    enum condition cond;

};




struct users{
    char username[MAXUSER];
    char pass[MAXPASS];
    int next;
    struct house *ptr[1000];
    enum types type;
};


struct log{
    char seller[MAXUSER];
    char agent[MAXUSER];
    char house_name[MAXUSER];
};
#endif //PROJECT_WALLE_MY_STRUCTS_H
