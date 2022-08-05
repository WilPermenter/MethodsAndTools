import sqlite3

class Order:
    def __init__(self):
        self.orderID = 0
        self.items = "N/A"
        self.userID = 0
        self.cartID = 0
        self.totalPrice = 0

    def createOrder(self):
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("INSERT INTO orders VALUES (?,?,?,?,?)",(self.orderID,self.items,self.userID,self.cartID,self.totalPrice))
            conn.commit()
            conn.close()
        except:
            return False
        return True

    def getNextOrderID():
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("SELECT order_ID FROM orders")
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

    def lookUpOrder(orderID):
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("SELECT * FROM orders WHERE order_ID = ?",(orderID))
            temp = c.fetchone()

            conn.commit()
            conn.close()
        except:
            return Order()
        return Order(temp[0],temp[1])

    