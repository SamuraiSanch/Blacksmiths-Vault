#ifndef CUSTOMERREPOSITORY_H
#define CUSTOMERREPOSITORY_H
#include <Customer.h>
#include <vector>
#include <Database.h>

class CustomerRepository {
private:

public:
    std::vector<Customer> getAll();
    Customer getById(const int id);
    void add(const Customer& customer);
    void update(const Customer& customer);
    void remove(const int id);
    std::vector<Customer> filterByGuild(const std::string& guild);
};

#endif
