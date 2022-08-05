class Item:
    def __init__(self):
        self.itemID = 0
        self.quantity = 0
        self.price = 0
        self.itemName = "N/A"
        self.genre = "N/A"

    def get_itemID(self): 
        return self.itemID
    
    def get_genre(self):
        return self.genre

    def get_quantity(self):
        return self.quantity

    def get_price(self):
        return self.price
    
    def get_itemName(self):
        return self.itemName

    def set_itemID(self, x):
        self.itemID = x

    def set_quantity(self, x):
        self.quantity = x

    def set_price(self, x):
        self.price = x

    def set_itemName(self, x):
        self.itemName = x

    def set_genre(self, x):
        self.genre = x