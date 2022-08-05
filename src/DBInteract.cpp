#include "headers/DBInteract.h"

// constructor 
DBInteract::DBInteract() {
    // open the database 
    rc = sqlite3_open("data/shoppingDB-methodstools.db", &db);
}

void DBInteract::addUser(User& user) {

    char* messageError;

    string name = user.getUsername();
    string pwd = user.getPassword();
    string add = user.getStreetAddress();
    string state = user.getState();
    string city = user.getCity();
    string payment = user.getPaymentInfo();
    string zip = to_string(user.getZip());
    string cartID = to_string(user.getCartID());
    
    // no idea if this actually works
    sql = "INSERT INTO USER VALUES(" + name + ", " + pwd + ", " + add + ", "
        + state + ", " + city + ", " + payment + ", " + zip + ", " + cartID 
        + ");";

    sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);
}
