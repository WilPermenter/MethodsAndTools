#include "user.h"

User::User() {
    username = "";
    password = "";
    streetAddress = "";
    state = "";
    city = "";
    paymentInfo = "";
    zip = -1;
    cartID = -1;
}
User::User(string username, string password, string streetAddress, string state, 
    string city, string paymentInfo, int zip, int cartID) {
    
    this->username = username;
    this->password = password; 
    this->streetAddress = streetAddress;
    this->state = state;
    this->city = city;
    this->paymentInfo = paymentInfo;
    this->zip = zip;
    this->cartID = cartID;

}

string User::getUsername() { return username; }
string User::getPassword() { return password; }
string User::getStreetAddress() { return streetAddress; }
string User::getState() { return state; } 
string User::getCity() { return city; }
string User::getPaymentInfo() { return paymentInfo;}

int User::getZip() { return zip; }
int User::getCartID() { return cartID; }

bool User::isLoggedIn() { return loggedIn; }

void User::setUsername(string username) { 
    this->username = username; 
}
void User::setPassword(string password) {
    this->password = password;
}
void User::setStreetAddress(string address) {
    this->streetAddress = address;
}
void User::setState(string state) {
    this->state = state;
}
void User::setCity(string city) {
    this->city = city;
}
void User::setPaymentInfo(string paymentInfo) {
    this->paymentInfo = paymentInfo;
}

void User::setZip(int zip) {
    this->zip = zip;
}
void User::setCartID(int cartID) {
    this->cartID = cartID;
}

bool User::login(string password) {
    if (password == this->password) {
        loggedIn = true;
        return loggedIn;
    }
    else {
        loggedIn = false;
        return loggedIn;
    }
}
