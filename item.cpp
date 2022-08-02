#include "item.h"

Item::Item() {
    genre = "N/A";
    name = "N/A";
    price = -1;
    itemID = -1;
    quantity = -1;
}


string Item::getGenre() { return genre; }
string Item::getName() { return name; }
float Item::getPrice() { return price; }
int Item::getItemID() { return itemID; }
int Item::getQuantity() { return quantity; }

