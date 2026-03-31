#include "Database.h"

Database::Database() {
    m_rc = sqlite3_open("Blacksmith_database.db", &m_db);
    if (m_rc != SQLITE_OK)
        std::cerr << "Can't open database: " << sqlite3_errmsg(m_db) << std::endl;
}
Database::~Database() {
    if (m_db)
        sqlite3_close(m_db);
}

sqlite3* Database::getConnection() {
    return m_db;
}

void Database::createCustomersTable() {
    const char* createTable = "CREATE TABLE IF NOT EXISTS customers("
        "id INTEGER PRIMARY KEY,"
        "name TEXT NOT NULL,"
        "guild TEXT NOT NULL,"
        "gold_balance REAL NOT NULL);";

    char* errMsg = nullptr;

    m_rc = sqlite3_exec(m_db, createTable, nullptr, 0, &errMsg);

    if (m_rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}
void Database::createSuppliersTable() {
    const char* createTable = "CREATE TABLE IF NOT EXISTS suppliers("
        "id INTEGER PRIMARY KEY,"
        "name TEXT NOT NULL,"
        "origin TEXT NOT NULL,"
        "contact TEXT NOT NULL,"
        "reliability_rating INT NOT NULL);";
   
    char* errMsg = nullptr;

    m_rc = sqlite3_exec(m_db, createTable, nullptr, 0, &errMsg);

    if (m_rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}
void Database::createItemsTable() {
    const char* createTable = "CREATE TABLE IF NOT EXISTS items("
        "id INTEGER PRIMARY KEY,"
        "name TEXT NOT NULL,"
        "type TEXT NOT NULL,"
        "damage INT,"
        "durability INT NOT NULL,"
        "rarity TEXT NOT NULL,"
        "price REAL NOT NULL,"
        "stock INT NOT NULL,"
        "supplier_id INT REFERENCES suppliers(id) NOT NULL);";

    char* errMsg = nullptr;

    m_rc = sqlite3_exec(m_db, createTable, nullptr, 0, &errMsg);

    if (m_rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}
void Database::createOrdersTable() {
    const char* createTable = "CREATE TABLE IF NOT EXISTS orders("
        "id INTEGER PRIMARY KEY,"
        "customer_id INT REFERENCES customers(id) NOT NULL,"
        "item_id INT REFERENCES items(id) NOT NULL,"
        "quantity INT NOT NULL,"
        "total_price REAL NOT NULL,"
        "status TEXT NOT NULL,"
        "order_date TEXT NOT NULL);";

    char* errMsg = nullptr;

    m_rc = sqlite3_exec(m_db, createTable, nullptr, 0, &errMsg);

    if (m_rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

void Database::initialize() {
    sqlite3_exec(m_db, "PRAGMA foreign_keys = ON;", nullptr, 0, nullptr);
    createCustomersTable();
    createSuppliersTable();
    createItemsTable();
    createOrdersTable();
}