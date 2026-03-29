#include "Database.h"

Database::Database() {
    rc = sqlite3_open("test.db", &db);
    if (rc != SQLITE_OK)
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
}
Database::~Database() {


    sqlite3_close(db);
}
void Database::tryRequest() {
    const char* sql = "CREATE TABLE IF NOT EXISTS COMPANY("
        "ID INT PRIMARY KEY NOT NULL,"
        "NAME TEXT NOT NULL,"
        "AGE INT NOT NULL);";
    rc = sqlite3_exec(db, sql, nullptr, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else {
        std::cout << "Table created successfully" << std::endl;
    }
}