#include "item.h"

Item::Item() {
    genre = "N/A";
    name = "N/A";
    price = -1;
    itemID = -1;
    quantity = -1;
}
Item::Item(string genre, string name, float price, int ItemID, int quantity){
  
  this->genre = genre;
  this->name = name;
  this->price = price;
  this->itemID = itemID;
  this->quantity = quantity;
    
}

string Item::getGenre() { return genre; }
string Item::getName() { return name; }

float Item::getPrice() { return price; }

int Item::getItemID() { return itemID; }
int Item::getQuantity() { return quantity; }

void Item::setGenre(string genre) {
    this->genre = genre;
}
void Item::setName(string name) {
    this->name = name;
}
void Item::setPrice(float price) {
    this->price = price;
}
void Item::setItemID(int itemID) {
    this->itemID = itemID;
}
void Item::setQuantity(int quantity) {
    this->quantity = quantity;
}

