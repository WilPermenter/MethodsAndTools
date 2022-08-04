#include "headers/cart.h"


Cart::Cart() {

    //TO DO: initialize vector

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