
def main(): 
    print("Welcome!\n")
    
    loginloop = True

    while loginloop:
        choice = input("(1) login\n(2) new account\n(3) exit\n")

        if choice == "1":
            print(" ")
            loginloop = False
        elif choice == "2":
            print(" ")
            loginloop = False
        elif choice == "3":
            print("Goodbye")
            return
        else:
            print("Invalid choice.\n")

    loopy = True

    while loopy:
        choice = input("\n(1) Check cart\n(2) User Info\n(3) Shop!\n(4) Exit program\n")

        if choice == "1":
            print("Navigating to cart...\n")
        elif choice == "2":
            print("Accessing user info...\n")
        elif choice == "3":
            
            shoploop = True

            while shoploop:
                choice = input("\n(1) View all items\n(2) Add item to cart\n(3) Go back\n")

                if choice == "1":
                    print("Items avaliable:\n")
                elif choice == "2":
                    input("Please enter the ID of the item you want to add:\n")
                elif choice == "3":
                    break
                else:
                    print("Invalid choice.\n")

        elif choice == "4":
            print("Goodbye")
            return
        else:
            print("Invalid choice.\n")

main()
