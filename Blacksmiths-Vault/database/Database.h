#ifndef DATABASE_H
#define DATABASE_H
#include "sqlite3.h"
#include <iostream>

class Database {
private:
    sqlite3* m_db;
    int m_rc;

    Database();
    ~Database();

    void createSuppliersTable();
    void createItemsTable();
    void createCustomersTable();
    void createOrdersTable();
public:
    static Database& getInstance() {
        static Database instance;
        return instance;
    }

    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    sqlite3* getConnection();
    void initialize();
};


#endif
