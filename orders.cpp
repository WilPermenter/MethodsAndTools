#include orders.h

Orders::Order() {
    //TO DO: Initialize item vector

    orderID = -1;
    userID = -1;
    cartID = -1;
    totalPrice = -1;
}

//TO DO: Get vector?

int Orders::getOrderID() { return orderID; }
int Orders::getUserID() { return userID; }
int Orders::getCartID() { return cartID; }
int Orders::getTotalPrice() { return totalPrice; }