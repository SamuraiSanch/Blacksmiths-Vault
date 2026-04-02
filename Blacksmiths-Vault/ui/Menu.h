#ifndef MENU_H
#define MENU_H
#include <CustomerRepository.h>
#include <ItemRepository.h>
#include <OrderRepository.h>
#include <SupplierRepository.h>

class Menu {
private:
    void processResponse(const short option);
    void processItemsResponse(const short option);
    void processOrdersResponse(const short option);
    void processSuppliersResponse(const short option);
    void processCustomersResponse(const short option);
    void processStatisticsResponse(const short option);
public:
    void startMenu();
};

#endif

