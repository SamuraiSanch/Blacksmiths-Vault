#ifndef DATABASE_H
#define DATABASE_H
#include "sqlite3.h"
#include <iostream>

class Database {
private:
    sqlite3* db;
    char* errMsg = nullptr;
    int rc;
public:
    Database();
    ~Database();
    void tryRequest();
};


#endif
