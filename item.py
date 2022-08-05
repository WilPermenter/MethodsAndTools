import sqlite3

class Item:
    def __init__(self):
        self.itemID = 0
        self.quantity = 0
        self.price = 0
        self.itemName = "N/A"
        self.genre = "N/A"

    def createItem(self):
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("INSERT INTO items VALUES (?,?,?,?,?)",(self.itemID,self.quantity,self.price,self.itemName,self.genre))
            conn.commit()
            conn.close()
        except:
            return False
            
        return True

    def deleteItem(self):
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("DELETE FROM items WHERE ?",(self.itemID))
            conn.commit()
            conn.close()
        except:
            return False
        return True

    def getNextItemID():
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("SELECT item_ID FROM items")
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