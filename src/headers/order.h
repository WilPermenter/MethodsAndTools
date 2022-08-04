#pragma once
#include <string>
#include <vector>
#include "item.h"

//PLEASE CHECK MY VECTOR STUFF

class Order {

    private: 
        std::vector<Item> item;

        int orderID;
        int userID;
        int cartID;
        float totalPrice;


    public:
        Order();
        Order(std::vector<Item> items (check vector work), int userID, int cartID, float totalPrice);
    
        int getOrderID();
        int getUserID();
        int getCartID();
        float getTotalPrice();
    
        void setOrderID(int orderID);
        void setUserID(int userID);
        void setCartID(int cartID);
        void setTotalPrice(float totalPrice);
};
