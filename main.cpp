#include "user.h"
#include <iostream>

using std::cin;
using std::cout;
using std::getline;

int main() {
    
    string userChoice;
    bool loopVar = true;

    while (loopVar) {
        cout << "Welcome!\n";
        cout << "Login or create new account:\n";
        cout << "1. Login.\n";
        cout << "2. Create new account.\n";
        cout << "3. Exit program.\n";

        getline(cin, userChoice);

        if (userChoice == "1") {
            // code for login
            cout << "Welcome!\n";
            loopVar = false;
        }
        else if (userChoice == "2") {
            // code for new account 
            cout << "Welcome!\n";
            loopVar = false;
        }
        else if (userChoice == "3") {
            cout << "Goodbye!\n";
            return 0;
        }
        else {
            // invalid choice 
            cout << "Error: Invalid selection.\n";
        }

    }


    return 0;
}
