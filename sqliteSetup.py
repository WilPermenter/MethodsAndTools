import sqlite3

def createDatabase(path):
    try:
        conn = sqlite3.connect(path)
        c = conn.cursor()

        #Create User Table
        c.execute("""CREATE TABLE users (
        username text,
        password text,
        address text,
        city text,
        state text,
        zipCode integer,
        payment text,
        cart_Id intiger,
        is_logged_in intiger
)
""")
        conn.commit()

        #Create Carts Table
        c.execute("""CREATE TABLE carts (
        cart_ID integer,
        items text
)
""")
        conn.commit()

        #Create Items Table
        c.execute("""CREATE TABLE items (
        item_ID integer,
        quanitity integer,
        price integer,
        itemName text,
        genre text
)
""")
        conn.commit()

        #Create Orders Table
        c.execute("""CREATE TABLE orders (
        order_ID integer,
        items text,
        user_ID integer,
        cart_ID integer,
        total integer
)
""")
        conn.commit()

        conn.close()
    except:
        return False
    return True