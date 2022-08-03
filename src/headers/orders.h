#pragma once
#include <string>
#include <vector>
#include "item.h"

class Orders {

    private: 
        std::vector<Item> items;

        int orderID;
        int userID;
        int cartID;
        int totalPrice;


    public:
        Orders(std::vector<Item> items, int userID, int cartID, int totalPrice);

        int getOrderID();
        int getUserID();
        int getCartID();
        int getPrice();
};