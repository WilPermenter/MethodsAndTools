#include "headers/cart.h"


Cart::Cart() {

    items(-1);

    cartID = -1;
}
Cart::Cart(int cartID, //std::vector<Item> items (check vector work)) {
    //TO DO: initialize vector

    this->cartID = cartID;
}


int Cart::getCartID() { return cartID; }

void Cart::setCartId(int cartID) {
    this->cartID = cartID;
}
void Cart::push(Item newEntry) {
    items.push(newEntry);
}
    
void Cart::pop(int index) {
    items.pop(index);
} 
           
           
           
