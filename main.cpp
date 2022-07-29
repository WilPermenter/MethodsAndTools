#include "user.h"
#include <iostream>

using std::cin;
using std::cout;

int main() {
    
    int userChoice;
    bool loopVar;

    while (loopVar) {
        cout << "Welcome!\n";
        cout << "Login or create new account:\n";
        cout << "1. Login.\n";
        cout << "2. Create new account:\n";

        cin >> userChoice;

        switch(userChoice) {
            case 1:
                // add code for login here
                loopVar = false;
            case 2:
                // add code for creating a new user here
                loopVar = false;
            default:
                cout << "Please select a valid choice (1 or 2).\n";
        }
    }


    return 0;
}