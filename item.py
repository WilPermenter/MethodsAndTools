import sqlite3

class Item:
    def __init__(self, itemID = 0, quantity = 0, price = 0, itemName = "", genre = ""):
        self.itemID = itemID
        self.quantity = quantity
        self.price = price
        self.itemName = itemName
        self.genre = genre

    def getAllItems():
        itemList = []
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("SELECT * FROM items")
            temp = c.fetchall()
            conn.close()
            
            for i in temp:
                itemList.append(Item(i[0],i[1],i[2],i[3],i[4]))
        except:
            return Item()
        return itemList

    def getItem(itemId):
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("SELECT * FROM items WHERE item_ID = ? ",(itemId,))
            temp = c.fetchone()
            conn.close()
        except:
            return Item()
        return Item(itemId,temp[1],temp[2],temp[3],temp[4])

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
            c.execute("DELETE FROM items WHERE itemID = ?",(self.itemID,))
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
