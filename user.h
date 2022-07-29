#pragma once
#include <string>

using std::string;

class User {
private:
    string username;
    string password;
    string streetAddress;
    string state;
    string city;
    string paymentInfo;

    int zip;
    int cartID;

    bool isLoggedIn;

public:
    User();

    string getUsername();
    string getPassword();
    string getStreetAddress();
    string getState();
    string getCity();
    string getPaymentInfo();
    int getZip();
    int getCartID();

    void setUsername(string username);
    void setPassword(string password);
    void setStreetAddress(string address);
    void setState(string state);
    void setCity(string city);
    void setPaymentInfo(string payment);
    void setZip(int zip);
    void setCartID(int cartID);   
    
    void createNewUser(string uname, string pwd);
    void assignCart();
    void login(string pwd);

    void deleteUser();

};
