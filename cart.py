import sqlite3
import random
from orders import *
from item import *

class Cart:
    def __init__(self, cartID = -1, items = ("",)):
        self.cartID = cartID
        self.items = items

    def cartNameList(self):
        arr = self.items[0].split(',')
        arr.pop(len(arr) - 1 )

        outstr = ""
        for item in arr:
            outstr += (str(arr.index(item) + 1)  +") " + Item.getItem(item).itemName + "\n")

        return outstr

    def cartTotal(self):
        arr = self.items[0].split(',')
        arr.pop(len(arr) - 1)

        total = 0
        for item in arr:
            total += Item.getItem(item).price

        return total


    def addToCart(self,itemID):
        #try:
        self.items = (self.items[0] + str(itemID) + ",",)
        #except:
            #return False
        return True


    def removeFromCart(self,selected):
        try:
            arr = self.items[0].split(',')
            arr.pop(len(arr) - 1 )
            arr.pop(int(selected) - 1)

            temp = ""
            for i in arr:
                temp += (i + ",")
            self.items = (temp,)
        except:
            return False
        return True

    def checkout(self,userID):
        newOrder = Order()
        newOrder.orderID = Order.getNextOrderID()
        newOrder.items = self.items
        newOrder.user = userID
        newOrder.cartID = self.cartID
        newOrder.totalPrice = self.cartTotal()

        if(newOrder.createOrder()):
            return True
        else:
            return False

    def createCart(self):
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("INSERT INTO carts VALUES (?,?)",(self.cartID,self.items[0]))
            conn.commit()
            conn.close()
        except:
            return False
        return True

    def deleteCart(self):
        try:
            conn = sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("DELETE FROM carts WHERE cart_ID = ?",(self.cartID,))
            conn.commit()
            conn.close()
        except:
            return False
            
        return True

    def getCart(cartId):
        try:
            conn = sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("SELECT items FROM carts WHERE cart_ID = ?",(cartId,))
            items = c.fetchone()
            conn.close()
        except:
            temp = Cart()
            temp.cartID = cartId
            return temp
        return Cart(cartId,items)

    def getItemName(self,Index):
        try:
            items = self.items.split(",")
            return items[Index].replace(',','')
        except:
            return ""
    
    def updateCart(self):
        if(self.deleteCart()):
            self.createCart()
        else:
            return False
        return True
    
    def getNextID():
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("SELECT cart_ID FROM carts")
            ids = c.fetchall()
            conn.commit()
            conn.close()

            highestID = 0
            for id in ids:
                if( id > highestID):
                    highestID = id
        except:
            return random.randint(10,100)
            
        return highestID
