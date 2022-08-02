#pragma once
#include <string>

using std::string;

class User {
private:

    string username, password, streetAddress,
        state, city, paymentInfo;

    int zip, cartID;

    bool loggedIn = false;

public:
    User();
    User(string username, string password, string streetAddress, string state, 
        string city, string paymentInfo, int zip, int cartID);

    string getUsername();
    string getPassword();
    string getStreetAddress();
    string getState();
    string getCity();
    string getPaymentInfo();
    int getZip();
    int getCartID();

    bool isLoggedIn();

    void setUsername(string username);
    void setPassword(string password);
    void setStreetAddress(string address);
    void setState(string state);
    void setCity(string city);
    void setPaymentInfo(string payment);
    void setZip(int zip);
    void setCartID(int cartID);   
    
    bool login(string pwd);

    ~User();

};
