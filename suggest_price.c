#include "declarations2.h"

int suggest(int district,int floor,int rooms,double area){
    int base_price,final_price;
    double base_per_square,first_price;
    switch (district) {
        case 1:
            base_price=1000;
            base_per_square=55;
            break;
        case 2:
            base_price=900;
            base_per_square=50;
            break;
        case 3:
            base_price=800;
            base_per_square=45;
            break;
        case 4:
            base_price=700;
            base_per_square=40;
            break;
        case 5:
            base_price=600;
            base_per_square=35;
            break;
        case 6:
            base_price=500;
            base_per_square=30;
            break;
        case 7:
            base_price=400;
            base_per_square=25;
            break;
        case 8:
            base_price=300;
            base_per_square=20;
            break;
        case 9:
            base_price=200;
            base_per_square=15;
            break;
        case 10:
            base_price=100;
            base_per_square=10;
    }
    base_per_square=(rooms*2)+(12-floor+1)*1.5+base_per_square;
    first_price=base_per_square*area;
    final_price=(int)first_price+base_price;
    return final_price;
}

