#ifndef TYPES_H
#define TYPES_H

typedef struct player player;
typedef struct property  property;
typedef struct bank bank;
typedef struct color_groups color_groups;

struct color_groups{
    char color[10];
    int no_of_properties;
};

struct property{
        char name[300];
        char color[40];
        int purchace_price;
        int mortage_value;
        int base_rental;
        int house_construction_cost;
        int hotel_construction_cost;
        union {
            bank *bank;
            player *player;
        }owner;
        int owned;
        int mortaged;
        int insuaranced;
        int no_of_buildings;
        /// complete
};

struct player{
        char* name;
        int vault;
        int bankrupt;
        int no_of_loans;
        int dice_value;
        color_groups player_color_list[8];
        int position;
        int jailed;
        int no_of_properties;
        property *properties[22];
};

struct bank{
        char* name;
        char* options; // options -> 1. obtain a loan, 2 repay a existing loan, 3 refinance a existing loan, 4 increase loan amount 5 repay loan in full
};


typedef struct{
        char* name;
        int purchace_price;
        int mortage_value;
        int owned;
        player* owner;
        int mortaged;
        int insuaranced;
    }railway;


typedef struct{
        char* name;
        int no_of_rounds;
        int max_no_of_rounds;
        char* policy;

    }insuarance;

typedef struct{
        char* name;
        char* rental;  // one utility, rent -> 4 times the dice roll, two utilities, rent -> 10 times the dice roll
        int purchace_price;
        int mortage_value;
        int owned;
        player* owner;
        int mortaged;
        int insuaranced;
    }utility;

typedef struct{
    char name[50];
}special;

typedef struct{
        union {
            property *property;
            bank *bank;
            insuarance *insuarance;
            utility *utility;
            railway *railway;
            special *special;
        } ptr;
        char type[50];
        char name[400];
    }cell;

#endif