
#pragma once
#include <string>

using std::string;

class Item {

    private:
      string genre;
      string name;
      
      float price;
      
      int itemID;
      int quantity;  

    public:
        Item();
        Item(string genre, string name, float price, int itemID, int quantity);

        string getGenre();
        string getName();

        float getPrice();

        int getItemID();
        int getQuantity();


        void setGenre(string genre);
        void setName(string name);
        void setPrice(float price);
        void setItemID(int itemID);
        void setQuantity(int quantity);

        void editStock(int itemID, int quantity);
    
        void Item::push(int newEntry);
    
        void Item::pop(int index);
    
        ~Item();
        
};
