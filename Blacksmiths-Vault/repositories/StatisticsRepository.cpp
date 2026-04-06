#include "StatisticsRepository.h"

void StatisticsRepository::printTotalProfit() {
    sqlite3* db = Database::getInstance().getConnection();
    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db,
        "SELECT SUM(total_price) FROM orders WHERE status = 'completed'",
        -1, &stmt, nullptr);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        double profit = sqlite3_column_double(stmt, 0);
        std::cout << "Total profit: " << profit << " gold\n";
    }
    sqlite3_finalize(stmt);
}

void StatisticsRepository::printTop5Items() {
    sqlite3* db = Database::getInstance().getConnection();
    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db,
        "SELECT items.name, COUNT(orders.id) as order_count "
        "FROM orders JOIN items ON orders.item_id = items.id "
        "GROUP BY orders.item_id "
        "ORDER BY order_count DESC "
        "LIMIT 5",
        -1, &stmt, nullptr);

    std::cout << "Top 5 most popular items:\n";
    int rank = 1;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        int count = sqlite3_column_int(stmt, 1);
        std::cout << rank++ << ". " << name << " - " << count << " orders\n";
    }
    sqlite3_finalize(stmt);
}

void StatisticsRepository::printLowStockItems() {
    sqlite3* db = Database::getInstance().getConnection();
    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db,
        "SELECT name, stock FROM items WHERE stock < 5 ORDER BY stock ASC",
        -1, &stmt, nullptr);

    std::cout << "Items with low stock (< 5):\n";
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        int stock = sqlite3_column_int(stmt, 1);
        std::cout << "- " << name << ": " << stock << " left\n";
    }
    sqlite3_finalize(stmt);
}