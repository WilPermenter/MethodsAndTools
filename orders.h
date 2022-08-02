#pragma once
#include <string>


class Orders {

    private: 
        vector<item>;

        int orderID;
        int userID;
        int cartID;
        int totalPrice;


    public:
        Orders(vector<item> items, int userID, int cartID, int totalPrice);

        int getOrderID();
        int getUserID();
        int getCartID();
}