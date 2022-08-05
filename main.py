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
            


            newuser = user(str(username), str(password), str(address), str(city), str(state), int(zip), str(payment), -1, True)

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
        itemsForSale = Item.getAllItems()
        if choice == "1":
            print("Items avaliable:\n")
            for i in itemsForSale:
                print(str(itemsForSale.index(i) + 1)  +") " + i.itemName + "\n")
        elif choice == "2":
            addToCart = input("Please enter the item you want to add:\n")
            print(str(itemsForSale[int(addToCart)].itemID))
            activeCart.addToCart(str(itemsForSale[int(addToCart)].itemID))
            activeCart.updateCart()
        elif choice == "3":
            if activeCart.checkout(activeUser.username):
                print("Checkout successful!")
            else: 
                print("Checkout failed...")
        elif choice == "4":
            shoploop = False
            break
        else:
            print("Invalid choice.\n")

    return activeCart


def storefront(activeUser):
    loopy = True
    if activeUser.cart_Id == -1:
        activeUser.cart_Id == Cart.getNextID
        activeCart = Cart()
        activeCart.cartID = Cart.getNextID()
        activeCart.createCart()
    else:
        activeCart = Cart.getCart(activeUser.cart_Id)
    

    while loopy:
        choice = input("\n(1) Check cart\n(2) User Info\n(3) Shop!\n(4) Edit Cart\n(5) Exit program\n")

        if choice == "1":
            #activeCart = Cart.getCart(activeCart.cartID)
            print(activeCart.cartNameList())

        elif choice == "2":
            print("Accessing user info...")
            print("Username: " + str(activeUser.username))
            print("Address: " + str(activeUser.address))
            print("City: " + str(activeUser.city))
            print("State: " + str(activeUser.state))
            print("ZIP: " + str(activeUser.zip_code))
            print("Payment method: " + str(activeUser.payment))
            print("\n")
            print("Order History: ")
            for order in Order.lookUpOrderByUser(activeUser.username):
                print("Order ID: " + str(order.orderID) + "Total Price" +  order.totalPrice)


        elif choice == "3":
            activeCart = shopping(activeCart,activeUser)

        elif choice == "4":
            print(activeCart.cartNameList())
            itemToRemove = input("Select Item To Remove: ")
            if(activeCart.removeFromCart(itemToRemove) and activeCart.updateCart()):
                print("Item Remove Sucesfully")
            else:
                print("Erro Removing Item")

        elif choice == "5":
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
