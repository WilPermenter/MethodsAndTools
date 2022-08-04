#pragma once
#include <vector>

#include "item.h"

class Cart {

    private:
        vector<Item> items;

        int cartID;

    public:
        Cart();
        Cart(cartID, items);
     
        int getCartID();

        void setCartID(int cartID);
        
        void push(Item newEntry);
    
        void pop(int index);
};

