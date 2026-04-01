#include "SupplierRepository.h"

std::vector<Supplier> SupplierRepository::getAll() {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "SELECT * FROM suppliers", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return {};
    }

    std::vector<Supplier> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Supplier supplier;
        supplier.setId(sqlite3_column_int(stmt, 0));
        supplier.setName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        supplier.setOrigin(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        supplier.setContact(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        supplier.setReliabilityRating(sqlite3_column_int(stmt, 4));
        result.push_back(supplier);
    }

    sqlite3_finalize(stmt);
    return result;
}
Supplier SupplierRepository::getById(const int id) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "SELECT * FROM suppliers WHERE id = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return Supplier{};
    }
    sqlite3_bind_int(stmt, 1, id);

    Supplier supplier;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        supplier.setId(sqlite3_column_int(stmt, 0));
        supplier.setName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        supplier.setOrigin(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        supplier.setContact(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        supplier.setReliabilityRating(sqlite3_column_int(stmt, 4));
    }

    sqlite3_finalize(stmt);
    return supplier;
}
void SupplierRepository::add(const Supplier& supplier) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "INSERT INTO suppliers (name, origin, contact, reliability_rating) VALUES (?, ?, ?, ?)", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return;
    }
    sqlite3_bind_text(stmt, 1, supplier.getName().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, supplier.getOrigin().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, supplier.getContact().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, supplier.getReliabilityRating());

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}
void SupplierRepository::update(const Supplier& supplier) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "UPDATE suppliers SET name = ?, origin = ?, contact = ?, reliability_rating = ? WHERE id = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return;
    }
    sqlite3_bind_text(stmt, 1, supplier.getName().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, supplier.getOrigin().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, supplier.getContact().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, supplier.getReliabilityRating());
    sqlite3_bind_int(stmt, 5, supplier.getId());

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}
void SupplierRepository::remove(const int id) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "DELETE FROM suppliers WHERE id = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, id);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}
std::vector<Supplier> SupplierRepository::filterByOrigin(const std::string& origin) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "SELECT * FROM suppliers WHERE origin = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return {};
    }
    sqlite3_bind_text(stmt, 1, origin.c_str(), -1, SQLITE_STATIC);

    std::vector<Supplier> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Supplier supplier;
        supplier.setId(sqlite3_column_int(stmt, 0));
        supplier.setName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        supplier.setOrigin(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        supplier.setContact(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        supplier.setReliabilityRating(sqlite3_column_int(stmt, 4));
        result.push_back(supplier);
    }

    sqlite3_finalize(stmt);
    return result;
}