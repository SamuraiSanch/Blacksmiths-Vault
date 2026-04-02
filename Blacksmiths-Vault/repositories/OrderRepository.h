#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H
#include "Order.h"
#include "Database.h"
#include <iostream>
#include <vector>

class OrderRepository {
private:

public:
    std::vector<Order> getAll();
    Order getById(const int id);
    void add(const Order& order);
    void update(const Order& order);
    void remove(const int id);
    void cancel(const int id);
    std::vector<Order> filterByStatus(const std::string& status);

};
#endif
