
#pragma once
#include <string>

using std::string;

class Item {

    private:
      string genre;
      string name;
      
      float price;
      
      int itemID
      int quantity;  

    public:
        Item();

        string getGenre;
        string getName;

        float getPrice;

        int getItemID;
        int getQuantity;


        void setGenre(string genre);
        void setName(string name);
        void setPrice();
        void setItemID();
        void setQuantity();

        void editStock;
        
};