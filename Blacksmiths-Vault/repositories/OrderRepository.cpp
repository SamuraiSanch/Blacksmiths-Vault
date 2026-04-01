#include "OrderRepository.h"

std::vector<Order> OrderRepository::getAll() {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "SELECT * FROM orders", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return {};
    }

    std::vector<Order> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Order order;
        order.setId(sqlite3_column_int(stmt, 0));
        order.setCustomerId(sqlite3_column_int(stmt, 1));
        order.setItemId(sqlite3_column_int(stmt, 2));
        order.setQuantity(sqlite3_column_int(stmt, 3));
        order.setTotalPrice(sqlite3_column_double(stmt, 4));
        order.setStatus(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
        order.setOrderDate(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
        result.push_back(order);
    }

    sqlite3_finalize(stmt);
    return result;
}
Order OrderRepository::getById(const int id) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "SELECT * FROM orders WHERE id = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return Order{};
    }
    sqlite3_bind_int(stmt, 1, id);

    Order order;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        order.setId(sqlite3_column_int(stmt, 0));
        order.setCustomerId(sqlite3_column_int(stmt, 1));
        order.setItemId(sqlite3_column_int(stmt, 2));
        order.setQuantity(sqlite3_column_int(stmt, 3));
        order.setTotalPrice(sqlite3_column_double(stmt, 4));
        order.setStatus(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
        order.setOrderDate(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
    }

    sqlite3_finalize(stmt);
    return order;
}
void OrderRepository::add(const Order& order) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "INSERT INTO orders (customer_id, item_id, quantity, total_price, status, order_date) VALUES (?, ?, ?, ?, ?, ?)", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, order.getCustomerId());
    sqlite3_bind_int(stmt, 2, order.getItemId());
    sqlite3_bind_int(stmt, 3, order.getQuantity());
    sqlite3_bind_double(stmt, 4, order.getTotalPrice());
    sqlite3_bind_text(stmt, 5, order.getStatus().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, order.getOrderDate().c_str(), -1, SQLITE_STATIC);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}
void OrderRepository::update(const Order& order) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "UPDATE orders SET customer_id = ?, item_id = ?, quantity = ?, total_price = ?, status = ?, order_date = ? WHERE id = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return;
    }
    sqlite3_bind_int(stmt, 1, order.getCustomerId());
    sqlite3_bind_int(stmt, 2, order.getItemId());
    sqlite3_bind_int(stmt, 3, order.getQuantity());
    sqlite3_bind_double(stmt, 4, order.getTotalPrice());
    sqlite3_bind_text(stmt, 5, order.getStatus().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, order.getOrderDate().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 7, order.getId());

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}
void OrderRepository::remove(const int id) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "DELETE FROM orders WHERE id = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, id);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}
std::vector<Order> OrderRepository::filterByStatus(const std::string& status) {
    sqlite3* db = Database::getInstance().getConnection();

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, "SELECT * FROM orders WHERE status = ?", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return {};
    }
    sqlite3_bind_text(stmt, 1, status.c_str(), -1, SQLITE_STATIC);

    std::vector<Order> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Order order;
        order.setId(sqlite3_column_int(stmt, 0));
        order.setCustomerId(sqlite3_column_int(stmt, 1));
        order.setItemId(sqlite3_column_int(stmt, 2));
        order.setQuantity(sqlite3_column_int(stmt, 3));
        order.setTotalPrice(sqlite3_column_double(stmt, 4));
        order.setStatus(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
        order.setOrderDate(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
        result.push_back(order);
    }

    sqlite3_finalize(stmt);
    return result;
}