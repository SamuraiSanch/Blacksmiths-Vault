#ifndef SUPPLIERREPOSITORY_H
#define SUPPLIERREPOSITORY_H
#include "Supplier.h"
#include "Database.h"
#include <iostream>
#include <vector>
class SupplierRepository {
private:

public:
    std::vector<Supplier> getAll();
    Supplier getById(const int id);
    void add(const Supplier& supplier);
    void update(const Supplier& supplier);
    void remove(const int id);
    std::vector<Supplier> filterByOrigin(const std::string& origin);
};

#endif
