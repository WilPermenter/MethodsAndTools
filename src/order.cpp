#include "headers/orders.h"

Order::Order() {
    items(-1);

    orderID = -1;
    userID = -1;
    cartID = -1;
    totalPrice = -1.00;
}
Order::Order(std::vector<Item> items (check vector work), int orderID, int userID, int cartID, float totalPrice) {
    //TO DO: Initialize item vector
    
    this->orderID = orderID;
    this->userID = userID;
    this->cartID = cartID;
    this->totalPrice = totalPrice;
    
}

int Order::getOrderID() { return orderID; }
int Order::getUserID() { return userID; }
int Order::getCartID() { return cartID; }
float Order::getTotalPrice() { return totalPrice; }

void Order::setOrderID(int orderID) {
    this->orderID = orderID;
}
void Order::setUserID(int userID) {
    this->userID = userID;
}
void Order::setCartID(int cartID) {
    this->cartID = cartID;
}
void Order::setTotalPrice(float totalPrice) {
    this->totalPrice = totalPrice;
}

void Item::push(int newEntry) {
    items.push(newEntry);
}
    
void Item::pop(int index) {
    items.pop(index);
}
