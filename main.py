from os.path import exists

from user import *
from item import *
from orders import *
from  cart import *
from sqliteSetup import *

DATABASE_PATH = "BookStore.db"

def login():

    loginloop = True

    while loginloop:
        choice = input("(1) login\n(2) new account\n(3) exit\n")

        if choice == "1":
            print("Attempting to log in...\n")
            username = input("Enter your username: ")
            password = input("Enter your password: ")

            existingUser = user(username, password)

            tempUser = existingUser.login() 

            if not tempUser.username == "-1":
                return tempUser

            print("Incorrect username/password")

        elif choice == "2":
            
            print("Creating new account...\n")
            username = input("Enter username: ")
            password = input("Enter password: ")
            address = input("Enter address: ")
            city = input("Enter city: ")
            state = input("Enter state: ")
            zip = input("Enter ZIP code: ")
            payment = input("Enter payment method: ")

            newuser = user(username, password, address, city, state, zip, payment, -1, True)

            if newuser.registerUser():
                print("\nAccount successfully registered!\n")
                newuser.assignCart()
                return newuser
            else:
                print("\nFailed to register account.\n")

        elif choice == "3":
            print("Goodbye")
            return
        else:
            print("Invalid choice.\n")


def shopping(activeCart, activeUser):

    shoploop = True

    while shoploop:
        choice = input("\n(1) View all items\n(2) Add item to cart\n(3) Checkout\n(4) Go back\n")

        if choice == "1":
            print("Items avaliable:\n")
        elif choice == "2":
            input("Please enter the ID of the item you want to add:\n")
        elif choice == "3":
            if activeCart.checkout(activeUser.username, activeCart):
                print("Checkout successful!")
            else: 
                print("Checkout failed...")
        else:
            print("Invalid choice.\n")


def storefront(activeUser):
    loopy = True
    activeCart = Cart()
    activeCart.cartID = activeUser.cart_Id
    activeCart.createCart()

    while loopy:
        choice = input("\n(1) Check cart\n(2) User Info\n(3) Shop!\n(4) Exit program\n")

        if choice == "1":
            activeCart = Cart.getCart(activeCart.cartID)
            print(activeCart.items)

        elif choice == "2":
            print("Accessing user info...")
            print("Username: " + activeUser.username)
            print("Address: " + activeUser.address)
            print("City: " + activeUser.city)
            print("State: " + activeUser.state)
            print("ZIP: " + activeUser.zip_code)
            print("Payment method: " + activeUser.payment)

        elif choice == "3":
            shopping(activeCart,activeUser)

        elif choice == "4":
            print("Goodbye")
            return
        else:
            print("Invalid choice.\n")

def main(): 
    print("Welcome!\n")

    #Database stuffs
    if(not exists(DATABASE_PATH)):
        if(createDatabase(DATABASE_PATH)):
            print("Data Base Created!")
        else:
            print("Data Base Creation Error!")
            return 0
    else:
        print("Data Base Found!")
    
    activeUser = login()

    storefront(activeUser)

if __name__ == "__main__":
    main()
