#include <stdio.h>

#include "types.h"
#include "board.h"

// Group 1: Brown
property pettah = {
    .name = "Pettah",
    .color = "Brown",
    .purchace_price = 1,
    .mortage_value = 1250,
    .base_rental = 500,
    .house_construction_cost = 750,
    .hotel_construction_cost = 750,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

property maradana = {
    .name = "Maradana",
    .color = "Brown",
    .purchace_price = 1,
    .mortage_value = 1250,
    .base_rental = 500,
    .house_construction_cost = 750,
    .hotel_construction_cost = 750,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

// Group 2: Light Blue
property bambalapitiya = {
    .name = "Bambalapitiya",
    .color = "Light Blue",
    .purchace_price = 1,
    .mortage_value = 1750,
    .base_rental = 750,
    .house_construction_cost = 1000,
    .hotel_construction_cost = 1000,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

property wellawatte = {
    .name = "Wellawatte",
    .color = "Light Blue",
    .purchace_price = 1,
    .mortage_value = 1750,
    .base_rental = 750,
    .house_construction_cost = 1000,
    .hotel_construction_cost = 1000,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

property mount_lavinia = {
    .name = "Mount Lavinia",
    .color = "Light Blue",
    .purchace_price = 1,
    .mortage_value = 1750,
    .base_rental = 750,
    .house_construction_cost = 1000,
    .hotel_construction_cost = 1000,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

// Group 3: Pink
property nugegoda = {
    .name = "Nugegoda",
    .color = "Pink",
    .purchace_price = 1,
    .mortage_value = 2250,
    .base_rental = 1000,
    .house_construction_cost = 1250,
    .hotel_construction_cost = 1250,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

property maharagama = {
    .name = "Maharagama",
    .color = "Pink",
    .purchace_price = 1,
    .mortage_value = 2250,
    .base_rental = 1000,
    .house_construction_cost = 1250,
    .hotel_construction_cost = 1250,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

property kottawa = {
    .name = "Kottawa",
    .color = "Pink",
    .purchace_price = 1,
    .mortage_value = 2250,
    .base_rental = 1000,
    .house_construction_cost = 1,
    .hotel_construction_cost = 1250,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

// Group 4: Orange
property negombo = {
    .name = "Negombo",
    .color = "Orange",
    .purchace_price = 1,
    .mortage_value = 2750,
    .base_rental = 1250,
    .house_construction_cost = 1500,
    .hotel_construction_cost = 1500,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

property katunayake = {
    .name = "Katunayake",
    .color = "Orange",
    .purchace_price = 1,
    .mortage_value = 2750,
    .base_rental = 1250,
    .house_construction_cost = 1500,
    .hotel_construction_cost = 1500,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

property ja_ela = {
    .name = "Ja-Ela",
    .color = "Orange",
    .purchace_price = 1,
    .mortage_value = 2750,
    .base_rental = 1250,
    .house_construction_cost = 1500,
    .hotel_construction_cost = 1500,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

// Group 5: Red
property kandy_city = {
    .name = "Kandy City",
    .color = "Red",
    .purchace_price = 1,
    .mortage_value = 3250,
    .base_rental = 1500,
    .house_construction_cost = 2000,
    .hotel_construction_cost = 2000,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

property peradeniya = {
    .name = "Peradeniya",
    .color = "Red",
    .purchace_price = 1,
    .mortage_value = 3250,
    .base_rental = 1500,
    .house_construction_cost = 2000,
    .hotel_construction_cost = 2000,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

property katugastota = {
    .name = "Katugastota",
    .color = "Red",
    .purchace_price = 1,
    .mortage_value = 3250,
    .base_rental = 1500,
    .house_construction_cost = 2000,
    .hotel_construction_cost = 2000,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

// Group 6: Yellow
property galle_fort = {
    .name = "Galle Fort",
    .color = "Yellow",
    .purchace_price = 1,
    .mortage_value = 4000,
    .base_rental = 2000,
    .house_construction_cost = 2500,
    .hotel_construction_cost = 2500,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

property unawatuna = {
    .name = "Unawatuna",
    .color = "Yellow",
    .purchace_price = 1,
    .mortage_value = 4000,
    .base_rental = 2000,
    .house_construction_cost = 2500,
    .hotel_construction_cost = 2500,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

property hikkaduwa = {
    .name = "Hikkaduwa",
    .color = "Yellow",
    .purchace_price = 8000,
    .mortage_value = 4000,
    .base_rental = 2000,
    .house_construction_cost = 2500,
    .hotel_construction_cost = 2500,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

// Group 7: Green
property jaffna_town = {
    .name = "Jaffna Town",
    .color = "Green",
    .purchace_price = 10000,
    .mortage_value = 5000,
    .base_rental = 2500,
    .house_construction_cost = 3000,
    .hotel_construction_cost = 3000,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

property nallur = {
    .name = "Nallur",
    .color = "Green",
    .purchace_price = 10000,
    .mortage_value = 5000,
    .base_rental = 2500,
    .house_construction_cost = 3000,
    .hotel_construction_cost = 3000,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

property trincomalee = {
    .name = "Trincomalee",
    .color = "Green",
    .purchace_price = 10000,
    .mortage_value = 5000,
    .base_rental = 2500,
    .house_construction_cost = 3000,
    .hotel_construction_cost = 3000,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

// Group 8: Dark Blue
property nuwara_eliya = {
    .name = "Nuwara Eliya",
    .color = "Dark Blue",
    .purchace_price = 12000,
    .mortage_value = 6000,
    .base_rental = 3000,
    .house_construction_cost = 4000,
    .hotel_construction_cost = 4000,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

property galle_face = {
    .name = "Galle Face",
    .color = "Dark Blue",
    .purchace_price = 12000,
    .mortage_value = 6000,
    .base_rental = 3000,
    .house_construction_cost = 4000,
    .hotel_construction_cost = 4000,
    .owned = 0,
    .mortaged = 0,
    .insuaranced = 0,
    .no_of_buildings = 0
};

cell board[40] = {
    // 0: Start
    [0]  = { .name = "GO", .type = "Start", .ptr.property = NULL },
    
    // 1: Brown Property
    [1]  = { .name = "Pettah", .type = "Property", .ptr.property = &pettah },
    
    // 2: Event
    [2]  = { .name = "Community Development Fund", .type = "Event", .ptr.property = NULL },
    
    // 3: Brown Property
    [3]  = { .name = "Maradana", .type = "Property", .ptr.property = &maradana },
    
    // 4: Tax
    [4]  = { .name = "Income Tax", .type = "Tax", .ptr.property = NULL },
    
    // 5: Railway
    [5]  = { .name = "Colombo Fort Railway Station", .type = "Railway", .ptr.property = NULL },
    
    // 6: Light Blue Property
    [6]  = { .name = "Bambalapitiya", .type = "Property", .ptr.property = &bambalapitiya },
    
    // 7: Event
    [7]  = { .name = "National Event Card", .type = "Event", .ptr.property = NULL },
    
    // 8: Light Blue Property
    [8]  = { .name = "Wellawatte", .type = "Property", .ptr.property = &wellawatte },
    
    // 9: Light Blue Property
    [9]  = { .name = "Mount Lavinia", .type = "Property", .ptr.property = &mount_lavinia },
    
    // 10: Special
    [10] = { .name = "Jail / Just Visiting", .type = "Special", .ptr.property = NULL },
    
    // 11: Pink Property
    [11] = { .name = "Nugegoda", .type = "Property", .ptr.property = &nugegoda },
    
    // 12: Utility
    [12] = { .name = "Ceylon Electricity Board", .type = "Utility", .ptr.property = NULL },
    
    // 13: Pink Property
    [13] = { .name = "Maharagama", .type = "Property", .ptr.property = &maharagama },
    
    // 14: Pink Property
    [14] = { .name = "Kottawa", .type = "Property", .ptr.property = &kottawa },
    
    // 15: Railway
    [15] = { .name = "Kandy Railway Station", .type = "Railway", .ptr.property = NULL },
    
    // 16: Orange Property
    [16] = { .name = "Negombo", .type = "Property", .ptr.property = &negombo },
    
    // 17: Insurance
    [17] = { .name = "Sri Lanka Insurance", .type = "Insurance", .ptr.property = NULL },
    
    // 18: Orange Property
    [18] = { .name = "Katunayake", .type = "Property", .ptr.property = &katunayake },
    
    // 19: Orange Property
    [19] = { .name = "Ja-Ela", .type = "Property", .ptr.property = &ja_ela },
    
    // 20: Special
    [20] = { .name = "Free Parking", .type = "Special", .ptr.property = NULL },
    
    // 21: Red Property
    [21] = { .name = "Kandy City", .type = "Property", .ptr.property = &kandy_city },
    
    // 22: Event
    [22] = { .name = "National Event Card", .type = "Event", .ptr.property = NULL },
    
    // 23: Red Property
    [23] = { .name = "Peradeniya", .type = "Property", .ptr.property = &peradeniya },
    
    // 24: Red Property
    [24] = { .name = "Katugastota", .type = "Property", .ptr.property = &katugastota },
    
    // 25: Railway
    [25] = { .name = "Galle Railway Station", .type = "Railway", .ptr.property = NULL },
    
    // 26: Yellow Property
    [26] = { .name = "Galle Fort", .type = "Property", .ptr.property = &galle_fort },
    
    // 27: Yellow Property
    [27] = { .name = "Unawatuna", .type = "Property", .ptr.property = &unawatuna },
    
    // 28: Utility
    [28] = { .name = "National Water Supply and Drainage Board", .type = "Utility", .ptr.property = NULL },
    
    // 29: Yellow Property
    [29] = { .name = "Hikkaduwa", .type = "Property", .ptr.property = &hikkaduwa },
    
    // 30: Special
    [30] = { .name = "Go To Jail", .type = "Special", .ptr.property = NULL },
    
    // 31: Green Property
    [31] = { .name = "Jaffna Town", .type = "Property", .ptr.property = &jaffna_town },
    
    // 32: Green Property
    [32] = { .name = "Nallur", .type = "Property", .ptr.property = &nallur },
    
    // 33: Insurance
    [33] = { .name = "Ceylinco Insurance", .type = "Insurance", .ptr.property = NULL },
    
    // 34: Green Property
    [34] = { .name = "Trincomalee", .type = "Property", .ptr.property = &trincomalee },
    
    // 35: Railway
    [35] = { .name = "Jaffna Railway Station", .type = "Railway", .ptr.property = NULL },
    
    // 36: Event
    [36] = { .name = "National Event Card", .type = "Event", .ptr.property = NULL },
    
    // 37: Dark Blue Property
    [37] = { .name = "Nuwara Eliya", .type = "Property", .ptr.property = &nuwara_eliya },
    
    // 38: Bank
    [38] = { .name = "Bank of Ceylon", .type = "Bank", .ptr.property = NULL },
    
    // 39: Dark Blue Property
    [39] = { .name = "Galle Face", .type = "Property", .ptr.property = &galle_face }
};

//move players
int move_player(player* player, int steps){
    if(player -> position + steps > 39){
        player -> vault += 3000;
        player -> position = (player -> position + steps) - 40;

        printf("\n %s passed GO \n", player -> name);
        printf("Collected Rs.2000\n");
        printf("Current Balance: %d \n", player -> vault);

        return player -> position;
    }
    else{
         player -> position += steps;
         return player -> position;
    }
}