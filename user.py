import sqlite3


class user:
    def __init__(self, username, password, address, city, state, zip_code, payment, cart_Id, isLoggedIn):
        self.username = username
        self.password = password
        self.address = address
        self.city = city
        self.state = state
        self.zip_code = zip_code
        self.payment = payment
        self.cart_Id = cart_Id
    
    @property
    def registerUser(self):
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("INSERT INTO users VALUES (?,?,?,?,?,?,?,?,?)",(self.username,self.password,self.address,self.city,self.city,self.state,self.zip_code,self.payment,self.cart_Id))
            conn.commit()
            conn.close()
        except:
            return False
            
        return True

    @property
    def assignCart(self):
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("SELECT cart_ID FROM users")
            ids = c.fetchall()
            conn.commit()
            conn.close()

            highestID = 0
            for id in ids:
                if( id > highestID):
                    highestID = id
            self.cart_Id = highestID + 1
        except:
            return False
            
        return True

    @property
    def login(self):
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("SELECT * FROM users WHERE username=?",(self.username))
            temp = c.fetchone()

            conn.commit()
            conn.close()
        except:
            return user('Does Not  Exist')

        if(temp[0] == self.username and temp[1] == self.password):
            return user(temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[5],temp[6],temp[7])
        else:    
            return user()

    @property
    def deleteUser(self):
        try:
            conn =  sqlite3.connect('BookStore.db')
            c = conn.cursor()
            c.execute("DELETE FROM users WHERE ?",(self.username))
            conn.commit()
            conn.close()
        except:
            return False
            
        return True