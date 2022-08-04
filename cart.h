#pragma once
#include <vector>

class Cart {

    private:
        std::vector<item> items;

        int cartID;

    public:
        Cart();
        Cart(cartID, //vector stuff);

        //Vector set/get needed
        int getCartID();

        void setCartID(int cartID);
        
};

