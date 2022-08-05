#include <string.h>
#include <sqlite3.h>
#include "headers/user.h"
#include "headers/item.h"

using namespace std;

class DBInteract {
private:
    int rc;
    string sql;
    sqlite3 *db;

public: 
    DBInteract();

    void addUser(User& user);
    
    Item getItem(int ID);

};
