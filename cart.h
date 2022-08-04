#pragma once
#include <vector>

class Cart {

    private:
        vector<int> items;

        int cartID;

    public:
        Cart();
        Cart(cartID, items);
     
        int getCartID();

        void setCartID(int cartID);
        
        void Item::push(int newEntry);
    
        void Item::pop(int index);
};

