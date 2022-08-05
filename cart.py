import sqlite3

class cart:
    def __init__(self):
        self.cartID = -1
        self.items = ""


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
    def checkout():
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
            c.execute("DELETE FROM carts WHERE ?",(self.cartID))
            conn.commit()
            conn.close()
        except:
            return False
            
        return True

    def getCart(cartId):
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("DELETE items FROM carts WHERE ?",(cartId))
            items = c.fetchone
            conn.close()
        except:
            return cart(-1,"")
        return cart(cartId,items)

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
    
    def getNextID(self):
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