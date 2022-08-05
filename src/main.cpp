#include <string>  // for string, basic_string, operator+, to_string, char_traits
#include <stdexcept>
#include <iostream>

#include "headers/user.h" // for user class

User * loginScreen(){
    std::string userName;
    std::string password;

    std::string streetAddress;
    std::string state;
    std::string city;
    std::string payment;
    int zip;

    //Welcome Screen
    std::cout << "Welcome to The Minecraft Book Store!\n";
    //Login Option
    std::cout << "Type 1 to login, Type 2 to Create an Account: ";
    int createAccount = 0;
    std::cin >> createAccount;
    
    switch(createAccount){
        case 1:
            std::cout << "\nPlease Input Your Username: ";
            std:: cin >> userName;
            std::cout << "\nPlease Input Your Password: ";
            std:: cin >> password;
            //Check Username 
            if(true){
                std::cout << "\n Welcome! \n";
                //return userObjectloggedIn
                return(new User());
            }
            break;
        case 2:
            std::cout << "\nPlease Input Your Username: ";
            std:: cin >> userName;
            if(/*check for duplicate username*/ false){
                std::cout <<"\n Duplacate User Name";
                throw(std::runtime_error("DuplacateUser"));
                break;
            }
            std::cout << "\nPlease Input Your Password: ";
            std:: cin >> password;
            std::cout << "\nPlease Input Your Street Address: ";
            std:: cin >> streetAddress;
            std::cout << "\nPlease Input Your State: ";
            std:: cin >> state;
            std::cout << "\nPlease Input Your City: ";
            std:: cin >> city;
            std::cout << "\nPlease Input Your Payment Method: ";
            std:: cin >> payment;
            std::cout << "\nPlease Input Your Zip: ";
            std:: cin >> zip;

            User * tempUser = new User();

            tempUser->setZip(zip);

            return tempUser;

            break;
        default:
            throw(std::runtime_error("Wrong Input"));
    }
}


void editUser(){
             std::cout << "Please choose which item you would like to edit" << endl;
             std::cout << "1: Username" << endl;
             std::cout << "2: Password" << endl;
             std::cout << "3: Address" << endl;
             std::cout << "4: Payment info" << endl;
             
             std::cin >> editAccount;
    
    switch(editAccount){
            
         case 1:
             
         case 2:
             
         case 3:
            
             switch(editAddress) {
                std::cout << "Please choose which item you would like to edit" << endl;
                std::cout << "1: Street address" << endl;
                std::cout << "2: State" << endl;
                std::cout << "3: City" << endl;
                std::cout << "4: ZIP code" << endl;                 
                
                std::cin >> editAddress;
                     
                 case 1:
                     
                 case 2:
                     
                 case 3:
                 
                 case 4:
             }
         case 4:
             
     }    
    return;
};

void shop(){
    return;
}

void viewOrder(){
    return;
}

int main(int argc, const char* argv[]) {
    bool LoggedIn = false;
    while(!LoggedIn){
        try
        {
        auto currentUser = loginScreen();
        }
        catch(const std::exception& e)
        {
            std::cout << "Input Error, Read options more carefully!";
        }
    }

    while(LoggedIn){
        try{
            int userInput;
            std::cout << "Main Menu, 1) Shop , 2) User Settings , 3) View Order, 4) Log Out";
            std::cin >> userInput;
            switch(userInput){
                case 1:
                    shop();
                    break;
                case 2:
                    editUser();
                    break;
                case 3:
                    viewOrder();
                    break;
                case 4:
                    LoggedIn = false;
                    break;
                default:
                    std::cout << "No Action matches that input";
            };
        }
        catch(const std::exception& e){
            std::cout << "Input Error, Be More Carefull!";
        }
    }
     std::cout << "Thanks For Shopping With Us!";
     std::cin;
};

    
