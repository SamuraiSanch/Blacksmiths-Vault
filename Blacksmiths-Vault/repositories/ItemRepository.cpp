#include "ItemRepository.h"

std::vector<Item> ItemRepository::getAll() {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "SELECT * FROM items", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return {};
    }

    std::vector<Item> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Item item;
        item.setId(sqlite3_column_int(stmt, 0));
        item.setName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        item.setType(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        item.setDamage(sqlite3_column_int(stmt, 3));
        item.setDurability(sqlite3_column_int(stmt, 4));
        item.setRarity(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
        item.setPrice(sqlite3_column_double(stmt, 6));
        item.setStock(sqlite3_column_int(stmt, 7));
        item.setSupplierId(sqlite3_column_int(stmt, 8));

        result.push_back(item);
    }

    sqlite3_finalize(stmt);
    return result;
}
Item ItemRepository::getById(const int id) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "SELECT * FROM items WHERE id = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return Item{};
    }
    sqlite3_bind_int(stmt, 1, id);

    Item item;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        item.setId(sqlite3_column_int(stmt, 0));
        item.setName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        item.setType(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        item.setDamage(sqlite3_column_int(stmt, 3));
        item.setDurability(sqlite3_column_int(stmt, 4));
        item.setRarity(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
        item.setPrice(sqlite3_column_double(stmt, 6));
        item.setStock(sqlite3_column_int(stmt, 7));
        item.setSupplierId(sqlite3_column_int(stmt, 8));
    }

    sqlite3_finalize(stmt);
    return item;
}
void ItemRepository::add(const Item& item) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "INSERT INTO items (name, type, damage, durability, rarity, price, stock, supplier_id) VALUES (?, ?, ?, ?, ?, ?, ?, ?)", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return;
    }
    sqlite3_bind_text(stmt, 1, item.getName().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, item.getType().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, item.getDamage());
    sqlite3_bind_int(stmt, 4, item.getDurability());
    sqlite3_bind_text(stmt, 5, item.getRarity().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 6, item.getPrice());
    sqlite3_bind_int(stmt, 7, item.getStock());
    sqlite3_bind_int(stmt, 8, item.getSupplierId());

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}
void ItemRepository::update(const Item& item) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "UPDATE items SET name = ?, type = ?, damage = ?, durability = ?, rarity = ?, price = ?, stock = ?, supplier_id = ? WHERE id = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return;
    }
    sqlite3_bind_text(stmt, 1, item.getName().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, item.getType().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, item.getDamage());
    sqlite3_bind_int(stmt, 4, item.getDurability());
    sqlite3_bind_text(stmt, 5, item.getRarity().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 6, item.getPrice());
    sqlite3_bind_int(stmt, 7, item.getStock());
    sqlite3_bind_int(stmt, 8, item.getSupplierId());
    sqlite3_bind_int(stmt, 9, item.getId());

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}
void ItemRepository::remove(const int id) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "DELETE FROM items WHERE id = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, id);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}
std::vector<Item> ItemRepository::filterByRarity(const std::string& rarity) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "SELECT * FROM items WHERE rarity = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return {};
    }
    sqlite3_bind_text(stmt, 1, rarity.c_str(), -1, SQLITE_TRANSIENT);

    std::vector<Item> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Item item;
        item.setId(sqlite3_column_int(stmt, 0));
        item.setName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        item.setType(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        item.setDamage(sqlite3_column_int(stmt, 3));
        item.setDurability(sqlite3_column_int(stmt, 4));
        item.setRarity(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
        item.setPrice(sqlite3_column_double(stmt, 6));
        item.setStock(sqlite3_column_int(stmt, 7));
        item.setSupplierId(sqlite3_column_int(stmt, 8));
        result.push_back(item);
    }

    sqlite3_finalize(stmt);
    return result;
}
std::vector<Item> ItemRepository::filterByType(const std::string& type) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "SELECT * FROM items WHERE type = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return {};
    }
    sqlite3_bind_text(stmt, 1, type.c_str(), -1, SQLITE_TRANSIENT);

    std::vector<Item> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Item item;
        item.setId(sqlite3_column_int(stmt, 0));
        item.setName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        item.setType(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        item.setDamage(sqlite3_column_int(stmt, 3));
        item.setDurability(sqlite3_column_int(stmt, 4));
        item.setRarity(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
        item.setPrice(sqlite3_column_double(stmt, 6));
        item.setStock(sqlite3_column_int(stmt, 7));
        item.setSupplierId(sqlite3_column_int(stmt, 8));
        result.push_back(item);
    }

    sqlite3_finalize(stmt);
    return result;
}