#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
class Item {
private:
    int m_id;
    std::string m_name;
    std::string m_type;
    int m_damage;
    int m_durability;
    std::string m_rarity;
    double m_price;
    int m_stock;
    int m_supplier_id;
public:
    int getId() const;
    std::string getName() const;
    std::string getType() const;
    int getDamage() const;
    int getDurability() const;
    std::string getRarity() const;
    double getPrice() const;
    int getStock() const;
    int getSupplierId() const;
    void setId(const int id);
    void setName(const std::string& name);
    void setType(const std::string& type);
    void setDamage(const int damage);
    void setDurability(const int durability);
    void setRarity(const std::string& rarity);
    void setPrice(const double price);
    void setStock(const int stock);
    void setSupplierId(const int supplierId);
};

std::ostream& operator<< (std::ostream& out, const Item& item);
std::istream& operator>> (std::istream& in, Item& item);

#endif
