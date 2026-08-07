#ifndef TYPES_H
#define TYPES_H

typedef struct player player;
typedef struct property  property;
typedef struct bank bank;
typedef struct color_groups color_groups;
typedef struct utility utility;
typedef struct railway railway;
typedef struct insuarance_term insuarance_term;
typedef struct insuarance insuarance;
typedef struct loan loan;

typedef enum{
    FIRE = 1,
    FLOOD = 2,
    RIOT = 3,
    VANDALISM = 4
}insuarance_protectors;

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
        insuarance *insuarance;
        /// complete
};

struct loan{
    int loan_round;
    int initial_pass;
    int loan_amount;
    player *borrower;
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
        int loan_round;
        int no_of_utilities;
        int no_of_railways;
        int no_of_properties;
        property *properties[22];
        utility *utilities[2];
        railway *railways[2];
        loan *loan;
};

struct bank{
        char* name;
        char* options; // options -> 1. obtain a loan, 2 repay a existing loan, 3 refinance a existing loan, 4 increase loan amount 5 repay loan in full
};

struct railway{
        char* name;
        int purchace_price;
        int mortage_value;
        int owned;
        player* owner;
        int mortaged;
        int insuaranced;
        int collateralized;
    };


struct insuarance{
        char* name;
        int no_of_rounds;
        int max_no_of_rounds;
        char* policy;
        int compensation;
        int premium;
        insuarance_protectors protect_against[4];
};

struct utility{
        char* name;
        char* rental;  // one utility, rent -> 4 times the dice roll, two utilities, rent -> 10 times the dice roll
        int purchace_price;
        int mortage_value;
        int owned;
        player* owner;
        int mortaged;
        int insuaranced;
        int collateralized;
    };

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

typedef enum{
    Aggresive_Invester,
    Conservative_Banker,
    Risk_Taker,
    Opportunistic_Trader
}player_type;



#endif