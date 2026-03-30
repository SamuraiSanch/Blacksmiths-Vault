#include "Item.h"

int Item::getId() const {
    return m_id;
}
std::string Item::getName() const {
    return m_name;
}
std::string Item::getType() const {
    return m_type;
}
int Item::getDamage() const {
    return m_dagame;
}
int Item::getDurability() const {
    return m_durability;
}
std::string Item::getRarity() const {
    return m_rarity;
}
double Item::getPrice() const {
    return m_price;
}
int Item::getStock() const {
    return m_stock;
}
int Item::getSupplierId() const {
    return m_supplier_id;
}
void Item::setId(const int id) {
    m_id = id;
}
void Item::setName(const std::string& name) {
    m_name = name;
}
void Item::setType(const std::string& type) {
    m_type = type;
}
void Item::setDamage(const int damage) {
    m_dagame = damage;
}
void Item::setDurability(const int durability) {
    m_durability = durability;
}
void Item::setRarity(const std::string& rarity) {
    m_rarity = rarity;
}
void Item::setPrice(const double price) {
    m_price = price;
}
void Item::setStock(const int stock) {
    m_stock = stock;
}
void Item::setSupplierId(const int supplierId) {
    m_supplier_id = supplierId;
}