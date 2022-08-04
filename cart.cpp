#include "headers/cart.h"


Cart::Cart() {

    std::vector<int> itemID;

    cartID = -1;
}
Cart::Cart(int cartID, //std::vector<Item> items (check vector work)) {
    //TO DO: initialize vector

    this->cartID = cartID;
}

//TO DO: set/get vector

int Cart::getCartID() { return cartID; }

void Cart::setCartId(int cartID) {
    this->cartID = cartID;
}
