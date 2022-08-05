import sqlite3
from orders import *
from item import *

class Cart:
    def __init__(self):
        self.cartID = -1
        self.items = ""

    def cartTotal(self):
        arr = self.items.split(',')
        arr.pop[-1]

        total = 0
        for item in arr:
            total += Item.getItem(item).price

        return total


    def addToCart(self,itemID):
        try:
            self.items = self.items + ("{},",itemID)
        except:
            return False
        return True


    def removeFromCart(self,itemID):
        try:
            self.items = self.items.replace(("?,",{itemID}), "")
            self.updateCart()
        except:
            return False
        return True

    #TODO: DO
    def checkout(self,userID,userCart):
        temp = Cart(Order.getNextID(),self.items,userID,userCart,self.cartTotal())
        newOrder = Order()
        newOrder.orderID = Order.getNextOrderID()
        newOrder.items = temp.items
        newOrder.userID = userID
        newOrder.cartID = temp.cartID
        newOrder.totalPrice = temp.cartTotal

        if(newOrder.createOrder()):
            return True
        else:
            return False

    def createCart(self):
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("INSERT INTO carts VALUES (?,?)",(self.cartID,self.items))
            conn.commit()
            conn.close()
        except:
            return False
        return True

    def deleteCart(self):
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("DELETE FROM carts WHERE cartID = ?",(self.cartID,))
            conn.commit()
            conn.close()
        except:
            return False
            
        return True

    def getCart(cartId):
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("SELECT items FROM carts WHERE cartID = ?",(cartId,))
            items = c.fetchone
            conn.close()
        except:
            temp = Cart()
            temp.cartId = cartId
            return temp
        return Cart(cartId,items)

    def getItemName(self,Index):
        try:
            items = self.items.split(",")
            return items[Index].replace(',','')
        except:
            return ""
    
    def updateCart(self):
        if(self.deleteCart):
            self.createCart
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
            return -1
            
        return highestID
