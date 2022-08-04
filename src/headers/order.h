#pragma once
#include <string>
#include <vector>
#include "item.h"

//PLEASE CHECK MY VECTOR STUFF

class Order {

    private: 
        std::vector<Item> items;

        int orderID;
        int userID;
        int cartID;
        float totalPrice;


    public:
        Order();
        Order(std::vector<Item> items, int userID, int cartID, float totalPrice);
    
        int getOrderID();
        int getUserID();
        int getCartID();
        float getTotalPrice();
    
        void setOrderID(int orderID);
        void setUserID(int userID);
        void setCartID(int cartID);
        void setTotalPrice(float totalPrice);
    
        void push(Item newEntry);
    
        void pop(int index);
    
        ~Order();
};
