#ifndef ITEMREPOSITORY_H
#define ITEMREPOSITORY_H
#include "Item.h"
#include "Database.h"
#include <iostream>
#include <vector>
class ItemRepository {
private:

public:
    std::vector<Item> getAll();
    Item getById(const int id);
    void add(const Item& item);
    void update(const Item& item);
    void remove(const int id);
    std::vector<Item> filterByRarity(const std::string& rarity);
    std::vector<Item> filterByType(const std::string& type);
};

#endif
