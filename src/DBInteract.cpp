#include "DBInteract.h"

// constructor 
DBInteract::DBInteract() {
    // open (or create) the database 
    rc = sqlite3_open("data.db", &db);

    // add stuff that constructs the database on first boot
    // could probably do this outside the program itself but
    // i am having trouble figuring it out
}

void DBInteract::addUser(User& user) {

}
void DBInteract::constructDB() {

    char* messageError;

    // sql for user table
    sql = "CREATE TABLE USER("
                      "USERNAME       TEXT  PRIMARY KEY   NOT NULL, "
                      "PASSWORD       TEXT         NOT NULL, "
                      "ADDRESS        CHAR(50)     NOT NULL, "
                      "STATE          CHAR(50)     NOT NULL, "
                      "CITY           CHAR(50)     NOT NULL, "
                      "ZIP            INT          NOT NULL, "
                      "PAYMENTINFO    CHAR(50)     NOT NULL, "
                      "CARTID         INT   FOREIGN KEY   NOT NULL ); ";

    // runs the sql and adds it to the database... probably
    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

    // need to add sql for the rest of the tables 
}