#include <string.h>
#include <sqlite3.h>
#include "user.h"

using namespace std;

class DBInteract {
private:
    int rc;
    string sql;
    sqlite3 *db;

public: 
    DBInteract();

    void addUser(User& user);

    // called when the database is constructed the first time
    // almost certainly not the best way to do this
    void constructDB();
  
    bool isEmpty();

};