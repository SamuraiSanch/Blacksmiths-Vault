#include "CustomerRepository.h"

std::vector<Customer> CustomerRepository::getAll() {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "SELECT * FROM customers", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return {};
    }

    std::vector<Customer> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Customer customer;
        customer.setId(sqlite3_column_int(stmt, 0));
        customer.setName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        customer.setGuild(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        customer.setGoldBalance(sqlite3_column_double(stmt, 3));
        result.push_back(customer);
    }

    sqlite3_finalize(stmt);
    return result;
}

Customer CustomerRepository::getById(const int id) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "SELECT * FROM customers WHERE id = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return Customer{};
    }
    sqlite3_bind_int(stmt, 1, id);

    Customer customer;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        customer.setId(sqlite3_column_int(stmt, 0));
        customer.setName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        customer.setGuild(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        customer.setGoldBalance(sqlite3_column_double(stmt, 3));
    }

    sqlite3_finalize(stmt);
    return customer;
}

void CustomerRepository::add(const Customer& customer) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "INSERT INTO customers (name, guild, gold_balance) VALUES (?, ?, ?)", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return;
    }
    sqlite3_bind_text(stmt, 1, customer.getName().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, customer.getGuild().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 3, customer.getGoldBalance());

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

void CustomerRepository::update(const Customer& customer) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "UPDATE customers SET name = ?, guild = ?, gold_balance = ? WHERE id = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    sqlite3_bind_text(stmt, 1, customer.getName().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, customer.getGuild().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 3, customer.getGoldBalance());
    sqlite3_bind_int(stmt, 4, customer.getId());

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

void CustomerRepository::remove(const int id) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "DELETE FROM customers WHERE id = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, id);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

std::vector<Customer> CustomerRepository::filterByGuild(const std::string& guild) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "SELECT * FROM customers WHERE guild = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return {};
    }
    sqlite3_bind_text(stmt, 1, guild.c_str(), -1, SQLITE_TRANSIENT);

    std::vector<Customer> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Customer customer;
        customer.setId(sqlite3_column_int(stmt, 0));
        customer.setName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        customer.setGuild(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        customer.setGoldBalance(sqlite3_column_double(stmt, 3));
        result.push_back(customer);
    }

    sqlite3_finalize(stmt);
    return result;
}