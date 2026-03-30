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
    const char* createTable = "CREATE TABLE IF NOT EXISTS CUSTOMERS("
        "ID INTEGER PRIMARY KEY,"
        "NAME TEXT NOT NULL,"
        "GUILD TEXT NOT NULL,"
        "GOLD_BALANCE INT NOT NULL);";

    char* errMsg = nullptr;

    m_rc = sqlite3_exec(m_db, createTable, nullptr, 0, &errMsg);

    if (m_rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}
void Database::createSuppliersTable() {
    const char* createTable = "CREATE TABLE IF NOT EXISTS SUPPLIERS("
        "ID INTEGER PRIMARY KEY,"
        "NAME TEXT NOT NULL,"
        "ORIGIN TEXT NOT NULL,"
        "CONTACT TEXT NOT NULL,"
        "RELIABILITY_RATING INT NOT NULL);";
   
    char* errMsg = nullptr;

    m_rc = sqlite3_exec(m_db, createTable, nullptr, 0, &errMsg);

    if (m_rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}
void Database::createItemsTable() {
    const char* createTable = "CREATE TABLE IF NOT EXISTS ITEMS("
        "ID INTEGER PRIMARY KEY,"
        "NAME TEXT NOT NULL,"
        "TYPE TEXT NOT NULL,"
        "DAMAGE INT,"
        "DURABILITY INT NOT NULL,"
        "RARITY TEXT NOT NULL,"
        "PRICE REAL NOT NULL,"
        "STOCK INT NOT NULL,"
        "SUPPLIER_ID INT REFERENCES SUPPLIERS(ID) NOT NULL);";

    char* errMsg = nullptr;

    m_rc = sqlite3_exec(m_db, createTable, nullptr, 0, &errMsg);

    if (m_rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}
void Database::createOrdersTable() {
    const char* createTable = "CREATE TABLE IF NOT EXISTS ORDERS("
        "ID INTEGER PRIMARY KEY,"
        "CUSTOMER_ID INT REFERENCES CUSTOMERS(ID) NOT NULL,"
        "ITEM_ID INT REFERENCES ITEMS(ID) NOT NULL,"
        "QUANTITY INT NOT NULL,"
        "TOTAL_PRICE REAL NOT NULL,"
        "STATUS TEXT NOT NULL,"
        "ORDER_DATE TEXT NOT NULL);";

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