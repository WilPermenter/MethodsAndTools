#include "user.h"

User::User() {
    username = "N/A";
    password = "N/A";
    streetAddress = "N/A";
    state = "N/A";
    city = "N/A";
    paymentInfo = "N/A";
    zip = -1;
    cartID = -1;
    loggedIn = false;
}

string User::getUsername() { return username; }
string User::getPassword() { return password; }
string User::getStreetAddress() { return streetAddress; }
string User::getState() { return state; } 
string User::getCity() { return city; }
string User::getPaymentInfo() { return paymentInfo;}
int User::getZip() { return zip; }
int User::getCartID() { return cartID; }

bool User::isLoggedIn() { 
    if (loggedIn) { return true; }
    else { return false;}
}
